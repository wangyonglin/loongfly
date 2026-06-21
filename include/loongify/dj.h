#if !defined(LOONGIFY_DJ_H)
#define LOONGIFY_DJ_H


#include "ju.h"
#include "jq.h"

#define  ERR -1

// 阴阳遁类型
typedef enum {
    D_YIN  = 0,  // 阴遁
    D_YANG = 1   // 阳遁
} loongify_d_t;




typedef struct 
{
    /* data */
    loongify_jq_t jq;   //节气
    loongify_ju_t h;    // 上元
    loongify_ju_t m;  // 中元
    loongify_ju_t l;  // 下元
}loongify_dj_t;

const loongify_dj_t djlist[24] = {
    // 阳遁（立春 → 芒种）
    {JQ_LICHUN,      JU8, JU5, JU2},  // 立春 八五二
    {JQ_YUSHUI,      JU9, JU6, JU3},  // 雨水 九六三
    {JQ_JINGZHE,     JU1, JU7, JU4},  // 惊蛰 一七四
    {JQ_CHUNFEN,     JU3, JU9, JU6},  // 春分 三九六
    {JQ_QINGMING,    JU4, JU1, JU7},  // 清明 四一七
    {JQ_GUYU,        JU5, JU2, JU8},  // 谷雨 五二八
    {JQ_LIXIA,       JU4, JU1, JU7},  // 立夏 四一七
    {JQ_XIAOMAN,     JU5, JU2, JU8},  // 小满 五二八（匹配示例）
    {JQ_MANGZHONG,   JU6, JU3, JU9},  // 芒种 六三九

    // 阴遁（夏至 → 大雪）
    {JQ_XIAZHI,      JU9, JU3, JU6},  // 夏至 九三六（匹配示例）
    {JQ_XIAOSHU,     JU8, JU2, JU5},  // 小暑 八二五
    {JQ_DASHU,       JU7, JU1, JU4},  // 大暑 七一四
    {JQ_LIQIU,       JU2, JU5, JU8},  // 立秋 二五八
    {JQ_CHUSHU,      JU1, JU4, JU7},  // 处暑 一四七
    {JQ_BAILU,       JU9, JU3, JU6},  // 白露 九三六
    {JQ_QIUFEN,      JU7, JU1, JU4},  // 秋分 七一四
    {JQ_HANLU,       JU6, JU9, JU3},  // 寒露 六九三
    {JQ_SHUANGJIANG, JU5, JU8, JU2},  // 霜降 五八二
    {JQ_LIDONG,      JU6, JU9, JU3},  // 立冬 六九三
    {JQ_XIAOXUE,     JU5, JU8, JU2},  // 小雪 五八二
    {JQ_DAXUE,       JU4, JU7, JU1},  // 大雪 四七一

    // 阳遁（冬至 → 大寒）
    {JQ_DONGZHI,     JU1, JU7, JU4},  // 冬至 一七四
    {JQ_XIAOHAN,     JU2, JU8, JU5},  // 小寒 二八五
    {JQ_DAHAN,       JU3, JU9, JU6}   // 大寒 三九六
};



#endif //LOONGIFY_DJ_H