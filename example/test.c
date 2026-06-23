#include <stdio.h>
#include <loong/stdlib.h>
#include <loong/jq.h>
int main()
{
    loong_gz4_t gz4=loong_gz4_make();
    loong_cf_t cf;
    loong_gz4_init(gz4,&cf);
    loong_jieqi_time_t t;


    // 打印2026年所有节气
    const char *names[] = {
        "小寒","大寒","立春","雨水","惊蛰","春分","清明","谷雨",
        "立夏","小满","芒种","夏至","小暑","大暑","立秋","处暑",
        "白露","秋分","寒露","霜降","立冬","小雪","大雪","冬至"
    };
    printf("\n2026年二十四节气（北京时间）：\n");
    for (int jq = 0; jq < JQ_COUNT; jq++) {
        if (loong_jieqi_time(2026, jq, &t)) {
            printf("%-6s %02d-%02d %02d:%02d\n",
                   names[jq], t.month, t.day, t.hour, t.minute);
        }
    }
    // loong_jieqi_time_t t;
    // if (loong_jieqi_time(2026, JQ_XIA_ZHI, &t)) {
    //     printf("2026年夏至：%04d-%02d-%02d %02d:%02d\n",
    //            t.year, t.month, t.day, t.hour, t.minute);
    // }

        // 已知 2000-01-01 12:00:00 UTC 的儒略日为 2451545.0
    // double test_jd = 2451545.0;  // UTC
    // loong_jieqi_time_t t;
    // jd_to_datetime(test_jd, &t);  // 需要将 jd_to_datetime 暴露或复制到测试处
    // printf("测试转换: %04d-%02d-%02d %02d:%02d\n", t.year, t.month, t.day, t.hour, t.minute);
    // // 预期输出: 2000-01-01 20:00 (北京时间)
    return 0;
}