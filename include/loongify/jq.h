#if !defined(LOONGIFY_JQ_H)
#define LOONGIFY_JQ_H


/**
 * @brief 二十四节气枚举（太阳黄经 + 奇门节气排序）
 * 黄经规则：每节气间隔 15°，夏至起点 360°(0°)
 */
typedef enum {
    JQ_XIAZHI      = 0,    // 夏至  黄经360°(0°)  阴遁起始
    JQ_XIAOSHU,              // 小暑  黄经15°
    JQ_DASHU,                // 大暑  黄经30°
    JQ_LIQIU,                // 立秋  黄经45°
    JQ_CHUSHU,               // 处暑  黄经60°
    JQ_BAILU,                // 白露  黄经75°
    JQ_QIUFEN,               // 秋分  黄经90°
    JQ_HANLU,                // 寒露  黄经105°
    JQ_SHUANGJIANG,          // 霜降  黄经120°
    JQ_LIDONG,               // 立冬  黄经135°
    JQ_XIAOXUE,              // 小雪  黄经150°
    JQ_DAXUE,                // 大雪  黄经165°  阴遁结束
    JQ_DONGZHI,              // 冬至  黄经180°  阳遁起始
    JQ_XIAOHAN,              // 小寒  黄经195°
    JQ_DAHAN,                // 大寒  黄经210°
    JQ_LICHUN,               // 立春  黄经225°
    JQ_YUSHUI,               // 雨水  黄经240°
    JQ_JINGZHE,              // 惊蛰  黄经255°
    JQ_CHUNFEN,              // 春分  黄经270°
    JQ_QINGMING,             // 清明  黄经285°
    JQ_GUYU,                 // 谷雨  黄经300°
    JQ_LIXIA,                // 立夏  黄经315°
    JQ_XIAOMAN,              // 小满  黄经330°
    JQ_MANGZHONG,            // 芒种  黄经345°  阳遁结束
} loongify_jq_t;


#endif // LOONGIFY_JQ_H
