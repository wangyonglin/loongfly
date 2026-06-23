/**
 * @file jq.c
 * @brief 二十四节气计算实现（基于天文算法）
 */

#include <loong/jq.h>
#include <math.h>

#define PI 3.141592653589793
#define JD2000 2451545.0

static double rad(double d) { return d * PI / 180.0; }
static double norm360(double a) { a = fmod(a, 360.0); if (a < 0) a += 360.0; return a; }

// 太阳黄经计算（Meeus 第二版）
static double solar_longitude(double jd) {
    double T = (jd - JD2000) / 36525.0;
    double T2 = T * T;
    double L = 280.46646 + 36000.76983 * T + 0.0003032 * T2;
    double M = 357.52911 + 35999.05029 * T - 0.0001537 * T2;
    double C = (1.914602 - 0.004817 * T - 0.000014 * T2) * sin(rad(M))
             + (0.019993 - 0.000101 * T) * sin(rad(2 * M))
             + 0.000289 * sin(rad(3 * M));
    return norm360(L + C - 0.00569 + 0.00478 * sin(rad(125.04 - 1934.136 * T)));
}

// 迭代求解
static double find_jd(double jd_est, double target_lon) {
    double jd = jd_est, diff;
    for (int i = 0; i < 30; i++) {
        diff = target_lon - solar_longitude(jd);
        if (diff < -180) diff += 360;
        if (diff > 180) diff -= 360;
        jd += diff / 0.9856;
        if (fabs(diff) < 0.00001) break;
    }
    return jd;
}

// 对外接口
double loong_jieqi_jd(int year, loong_jieqi_t jq) {
    if (jq < 0 || jq >= JQ_COUNT) return 0.0;
    // 基准：2000年冬至（JD 2451903.235）
    double base_jd = 2451903.235;
    int base_year = 2000;
    int base_jq = JQ_DONG_ZHI;
    double offset = (year - base_year) * 365.2422 + (jq - base_jq) * 15.2184;
    return find_jd(base_jd + offset, jq * 15.0);
}



// bool loong_jieqi_time(int year, loong_jieqi_t jq, loong_jieqi_time_t *out) {
//     if (!out) return false;
//     double jd = loong_jieqi_jd(year, jq);
//     if (jd == 0.0) return false;
//     jd_to_datetime(jd, out);
//     return true;
// }
bool loong_jieqi_time(int year, loong_jieqi_t jq, loong_jieqi_time_t *out) {
    if (!out || year < 1900 || year > 2100 || jq < 0 || jq >= JQ_COUNT)
        return false;
    *out = JIE_QI_TABLE[year - 1900][jq];
    return true;
}

/**
 * 将儒略日（UTC）转换为公历日期（北京时间）
 * @param jd_utc  儒略日（UTC）
 * @param out     输出结构体指针
 */
void jd_to_datetime(double jd_utc, loong_jieqi_time_t *out) {
    // 加上北京时区偏移（UTC+8）
    jd_utc += 8.0 / 24.0;

    // 使用标准算法（Fliegel-Van Flandern 算法）将儒略日转为公历
    // 该算法对所有正儒略日有效，且为整数运算，无浮点误差
    long jd = (long)(jd_utc + 0.5);   // 四舍五入到整数儒略日

    long l = jd + 68569;
    long n = (4 * l) / 146097;
    l = l - (146097 * n + 3) / 4;
    long i = (4000 * (l + 1)) / 1461001;
    l = l - (1461 * i) / 4 + 31;
    long j = (80 * l) / 2447;
    int d = (int)(l - (2447 * j) / 80);
    l = j / 11;
    int m = (int)(j + 2 - 12 * l);
    int y = (int)(100 * (n - 49) + i + l);

    out->year = y;
    out->month = m;
    out->day = d;

    // 计算时分（从儒略日的小数部分）
    double frac = jd_utc + 0.5 - floor(jd_utc + 0.5);
    double seconds = frac * 86400.0;
    int h = (int)(seconds / 3600);
    int mi = (int)((seconds - h * 3600) / 60);
    out->hour = h % 24;
    out->minute = mi;
}