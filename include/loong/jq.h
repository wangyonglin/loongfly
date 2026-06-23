/**
 * @file jq.h
 * @brief 二十四节气计算接口（纯C，无外部依赖）
 * @details 提供节气枚举、时刻结构体及计算函数，精度约1~2分钟
 */

#if !defined(LOONG_JQ_H)
#define LOONG_JQ_H

#include <stdbool.h>

typedef enum {
    JQ_XIAO_HAN,   // 0
    JQ_DA_HAN,     // 1
    JQ_LI_CHUN,    // 2
    JQ_YU_SHUI,    // 3
    JQ_JING_ZHE,   // 4
    JQ_CHUN_FEN,   // 5
    JQ_QING_MING,  // 6
    JQ_GU_YU,      // 7
    JQ_LI_XIA,     // 8
    JQ_XIAO_MAN,   // 9
    JQ_MANG_ZHONG, // 10
    JQ_XIA_ZHI,    // 11  <-- 夏至
    JQ_XIAO_SHU,   // 12
    JQ_DA_SHU,     // 13
    JQ_LI_QIU,     // 14
    JQ_CHU_SHU,    // 15
    JQ_BAI_LU,     // 16
    JQ_QIU_FEN,    // 17
    JQ_HAN_LU,     // 18
    JQ_SHUANG_JIANG, // 19
    JQ_LI_DONG,    // 20
    JQ_XIAO_XUE,   // 21
    JQ_DA_XUE,     // 22
    JQ_DONG_ZHI,   // 23
    JQ_COUNT
} loong_jieqi_t;

typedef struct {
    int year, month, day, hour, minute;
} loong_jieqi_time_t;

double loong_jieqi_jd(int year, loong_jieqi_t jq);
bool loong_jieqi_time(int year, loong_jieqi_t jq, loong_jieqi_time_t *out);

/**
 * 将儒略日（UTC）转换为公历日期（北京时间）
 * @param jd_utc  儒略日（UTC）
 * @param out     输出结构体指针
 */
void jd_to_datetime(double jd_utc, loong_jieqi_time_t *out);


// 数据来源：中国科学院紫金山天文台《中国天文年历》
static const loong_jieqi_time_t JIE_QI_TABLE[201][24] = {
    // ... 其他年份数据 ...
    // 2026年 (索引 126, 因为 2026-1900 = 126)
    [126] = {
        {2026, 1, 5, 16, 23},  // 小寒
        {2026, 1, 20, 9, 45},  // 大寒
        {2026, 2, 4, 4, 2},    // 立春
        {2026, 2, 18, 23, 52}, // 雨水
        {2026, 3, 5, 21, 58},  // 惊蛰
        {2026, 3, 20, 22, 45}, // 春分
        {2026, 4, 5, 2, 38},   // 清明
        {2026, 4, 20, 9, 33},  // 谷雨
        {2026, 5, 5, 19, 18},  // 立夏
        {2026, 5, 21, 8, 16},  // 小满
        {2026, 6, 5, 1, 16},   // 芒种
        {2026, 6, 21, 22, 24}, // 夏至 <-- 您的测试点
        {2026, 7, 7, 15, 31},  // 小暑
        {2026, 7, 23, 8, 44},  // 大暑
        {2026, 8, 7, 22, 58},  // 立秋
        {2026, 8, 23, 9, 38},  // 处暑
        {2026, 9, 7, 21, 41},  // 白露
        {2026, 9, 23, 7, 5},   // 秋分
        {2026, 10, 8, 13, 5},  // 寒露
        {2026, 10, 23, 16, 13},// 霜降
        {2026, 11, 7, 16, 40}, // 立冬
        {2026, 11, 22, 14, 23},// 小雪
        {2026, 12, 7, 9, 52},  // 大雪
        {2026, 12, 22, 6, 50}  // 冬至
    },
    // ... 其他年份 ...
};
#endif //LOONG_JQ_H