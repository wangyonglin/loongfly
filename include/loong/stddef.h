#if !defined(LOONGIFY_STDDEF_H)
#define LOONGIFY_STDDEF_H
#include <stdio.h> // 也定义 NUL
#include <stdbool.h>

typedef bool loong_b_t;
typedef char loong_pchar_t[4];
typedef unsigned char loong_puchar_s[4];

// 十天干，取值范围 1~10
typedef enum loong_tg_t
{
    TG_JIA = 1, // 甲
    TG_YI,      // 乙
    TG_BING,    // 丙
    TG_DING,    // 丁
    TG_WU,      // 戊
    TG_JI,      // 己
    TG_GENG,    // 庚
    TG_XIN,     // 辛
    TG_REN,     // 壬
    TG_GUI      // 癸
} loong_tg_t;

// 十二地支，取值范围 1~12
typedef enum
{
    DZ_ZI = 1, // 子
    DZ_CHOU,   // 丑
    DZ_YIN,    // 寅
    DZ_MAO,    // 卯
    DZ_CHEN,   // 辰
    DZ_SI,     // 巳
    DZ_WU,     // 午
    DZ_WEI,    // 未
    DZ_SHEN,   // 申
    DZ_YOU,    // 酉
    DZ_XU,     // 戌
    DZ_HAI     // 亥
} loong_dz_t;

// 干支组合结构体
typedef struct
{
    loong_tg_t tg;
    loong_dz_t dz;
} loong_gz_t;

typedef enum
{
    JX_TIANPENG = 1,  // 天蓬星 (坎宫, 属水)
    JX_TIANRUI = 2,   // 天芮星 (坤宫, 属土, 也称天禽星在中宫)
    JX_TIANCHONG = 3, // 天冲星 (震宫, 属木)
    JX_TIANFU = 4,    // 天辅星 (巽宫, 属木)
    JX_TIANQIN = 5,   // 天禽星 (中宫, 属土)  —— 中宫寄二宫，故与天芮同宫
    JX_TIANXIN = 6,   // 天心星 (乾宫, 属金)
    JX_TIANZHU = 7,   // 天柱星 (兑宫, 属金)
    JX_TIANREN = 8,   // 天任星 (艮宫, 属土)
    JX_TIANYING = 9   // 天英星 (离宫, 属火)
} loongify_jx_t;

/**
 * @brief 奇门遁甲局数枚举
 * 通用局数，配合阳遁、阴遁使用
 */
typedef enum
{
    JU0 = 0,
    JU1 = 1, // 一局
    JU2,     // 二局
    JU3,     // 三局
    JU4,     // 四局
    JU5,     // 五局
    JU6,     // 六局
    JU7,     // 七局
    JU8,     // 八局
    JU9      // 九局
} loong_j_t;

// 阴阳遁类型
typedef enum
{
    D_YINDUN = 0, // 阴遁
    D_YANGDUN = 1 // 阳遁
} loong_d_t;

/**
 * @brief 二十四节气枚举（太阳黄经 + 奇门节气排序）
 * 黄经规则：每节气间隔 15°，夏至起点 360°(0°)
 */
typedef enum
{
    JQ_XIAZHI = 0,  // 夏至  黄经360°(0°)  阴遁起始
    JQ_XIAOSHU,     // 小暑  黄经15°
    JQ_DASHU,       // 大暑  黄经30°
    JQ_LIQIU,       // 立秋  黄经45°
    JQ_CHUSHU,      // 处暑  黄经60°
    JQ_BAILU,       // 白露  黄经75°
    JQ_QIUFEN,      // 秋分  黄经90°
    JQ_HANLU,       // 寒露  黄经105°
    JQ_SHUANGJIANG, // 霜降  黄经120°
    JQ_LIDONG,      // 立冬  黄经135°
    JQ_XIAOXUE,     // 小雪  黄经150°
    JQ_DAXUE,       // 大雪  黄经165°  阴遁结束
    JQ_DONGZHI,     // 冬至  黄经180°  阳遁起始
    JQ_XIAOHAN,     // 小寒  黄经195°
    JQ_DAHAN,       // 大寒  黄经210°
    JQ_LICHUN,      // 立春  黄经225°
    JQ_YUSHUI,      // 雨水  黄经240°
    JQ_JINGZHE,     // 惊蛰  黄经255°
    JQ_CHUNFEN,     // 春分  黄经270°
    JQ_QINGMING,    // 清明  黄经285°
    JQ_GUYU,        // 谷雨  黄经300°
    JQ_LIXIA,       // 立夏  黄经315°
    JQ_XIAOMAN,     // 小满  黄经330°
    JQ_MANGZHONG,   // 芒种  黄经345°  阳遁结束
} loong_q_t;

typedef struct
{
    loong_pchar_t tg;
    loong_pchar_t dz;
} loong_gz_s;

typedef enum
{
    LOONG_SY_N = 0,
    LOONG_SY_L,
    LOONG_SY_M,
    LOONG_SY_H
} loong_sy_t;


typedef struct
{
    loong_q_t q;
    loong_j_t h;
    loong_j_t m;
    loong_j_t l;
} loong_qj_t;
static const loong_qj_t LOONG_QJ[24] = {
    // 阳遁（立春 → 芒种）
    {JQ_LICHUN, JU8, JU5, JU2},    // 立春 八五二
    {JQ_YUSHUI, JU9, JU6, JU3},    // 雨水 九六三
    {JQ_JINGZHE, JU1, JU7, JU4},   // 惊蛰 一七四
    {JQ_CHUNFEN, JU3, JU9, JU6},   // 春分 三九六
    {JQ_QINGMING, JU4, JU1, JU7},  // 清明 四一七
    {JQ_GUYU, JU5, JU2, JU8},      // 谷雨 五二八
    {JQ_LIXIA, JU4, JU1, JU7},     // 立夏 四一七
    {JQ_XIAOMAN, JU5, JU2, JU8},   // 小满 五二八（匹配示例）
    {JQ_MANGZHONG, JU6, JU3, JU9}, // 芒种 六三九

    // 阴遁（夏至 → 大雪）
    {JQ_XIAZHI, JU9, JU3, JU6},      // 夏至 九三六（匹配示例）
    {JQ_XIAOSHU, JU8, JU2, JU5},     // 小暑 八二五
    {JQ_DASHU, JU7, JU1, JU4},       // 大暑 七一四
    {JQ_LIQIU, JU2, JU5, JU8},       // 立秋 二五八
    {JQ_CHUSHU, JU1, JU4, JU7},      // 处暑 一四七
    {JQ_BAILU, JU9, JU3, JU6},       // 白露 九三六
    {JQ_QIUFEN, JU7, JU1, JU4},      // 秋分 七一四
    {JQ_HANLU, JU6, JU9, JU3},       // 寒露 六九三
    {JQ_SHUANGJIANG, JU5, JU8, JU2}, // 霜降 五八二
    {JQ_LIDONG, JU6, JU9, JU3},      // 立冬 六九三
    {JQ_XIAOXUE, JU5, JU8, JU2},     // 小雪 五八二
    {JQ_DAXUE, JU4, JU7, JU1},       // 大雪 四七一

    // 阳遁（冬至 → 大寒）
    {JQ_DONGZHI, JU1, JU7, JU4}, // 冬至 一七四
    {JQ_XIAOHAN, JU2, JU8, JU5}, // 小寒 二八五
    {JQ_DAHAN, JU3, JU9, JU6}    // 大寒 三九六
};
// 天干名称映射表（索引0对应“甲”，索引9对应“癸”）
static const char *TG_NAMES[] = {
    NULL, "甲", "乙", "丙", "丁", "戊",
    "己", "庚", "辛", "壬", "癸"};

// 地支名称映射表（索引0对应“子”，索引11对应“亥”）
static const char *DZ_NAMES[] = {
    NULL, "子", "丑", "寅", "卯", "辰", "巳",
    "午", "未", "申", "酉", "戌", "亥"};

// 六十甲子顺序表（索引0~59，必须严格按顺序）
static const loong_gz_t LOONG_GZ[60] = {
    {TG_JIA, DZ_ZI},    // 0  甲子
    {TG_YI, DZ_CHOU},   // 1  乙丑
    {TG_BING, DZ_YIN},  // 2  丙寅
    {TG_DING, DZ_MAO},  // 3  丁卯
    {TG_WU, DZ_CHEN},   // 4  戊辰
    {TG_JI, DZ_SI},     // 5  己巳
    {TG_GENG, DZ_WU},   // 6  庚午
    {TG_XIN, DZ_WEI},   // 7  辛未
    {TG_REN, DZ_SHEN},  // 8  壬申
    {TG_GUI, DZ_YOU},   // 9  癸酉
    {TG_JIA, DZ_XU},    // 10 甲戌
    {TG_YI, DZ_HAI},    // 11 乙亥
    {TG_BING, DZ_ZI},   // 12 丙子
    {TG_DING, DZ_CHOU}, // 13 丁丑
    {TG_WU, DZ_YIN},    // 14 戊寅
    {TG_JI, DZ_MAO},    // 15 己卯
    {TG_GENG, DZ_CHEN}, // 16 庚辰
    {TG_XIN, DZ_SI},    // 17 辛巳
    {TG_REN, DZ_WU},    // 18 壬午
    {TG_GUI, DZ_WEI},   // 19 癸未
    {TG_JIA, DZ_SHEN},  // 20 甲申
    {TG_YI, DZ_YOU},    // 21 乙酉
    {TG_BING, DZ_XU},   // 22 丙戌
    {TG_DING, DZ_HAI},  // 23 丁亥
    {TG_WU, DZ_ZI},     // 24 戊子
    {TG_JI, DZ_CHOU},   // 25 己丑
    {TG_GENG, DZ_YIN},  // 26 庚寅
    {TG_XIN, DZ_MAO},   // 27 辛卯
    {TG_REN, DZ_CHEN},  // 28 壬辰
    {TG_GUI, DZ_SI},    // 29 癸巳
    {TG_JIA, DZ_WU},    // 30 甲午
    {TG_YI, DZ_WEI},    // 31 乙未
    {TG_BING, DZ_SHEN}, // 32 丙申
    {TG_DING, DZ_YOU},  // 33 丁酉
    {TG_WU, DZ_XU},     // 34 戊戌
    {TG_JI, DZ_HAI},    // 35 己亥
    {TG_GENG, DZ_ZI},   // 36 庚子
    {TG_XIN, DZ_CHOU},  // 37 辛丑
    {TG_REN, DZ_YIN},   // 38 壬寅
    {TG_GUI, DZ_MAO},   // 39 癸卯
    {TG_JIA, DZ_CHEN},  // 40 甲辰
    {TG_YI, DZ_SI},     // 41 乙巳
    {TG_BING, DZ_WU},   // 42 丙午
    {TG_DING, DZ_WEI},  // 43 丁未
    {TG_WU, DZ_SHEN},   // 44 戊申
    {TG_JI, DZ_YOU},    // 45 己酉
    {TG_GENG, DZ_XU},   // 46 庚戌
    {TG_XIN, DZ_HAI},   // 47 辛亥
    {TG_REN, DZ_ZI},    // 48 壬子
    {TG_GUI, DZ_CHOU},  // 49 癸丑
    {TG_JIA, DZ_YIN},   // 50 甲寅
    {TG_YI, DZ_MAO},    // 51 乙卯
    {TG_BING, DZ_CHEN}, // 52 丙辰
    {TG_DING, DZ_SI},   // 53 丁巳
    {TG_WU, DZ_WU},     // 54 戊午
    {TG_JI, DZ_WEI},    // 55 己未
    {TG_GENG, DZ_SHEN}, // 56 庚申
    {TG_XIN, DZ_YOU},   // 57 辛酉
    {TG_REN, DZ_XU},    // 58 壬戌
    {TG_GUI, DZ_HAI}    // 59 癸亥
};

typedef struct
{
    loong_gz_t year;  // 年柱
    loong_gz_t month; // 月柱
    loong_gz_t day;   // 日柱
    loong_gz_t hour;  // 时柱
} loong_gz4_t;


typedef struct
{
    loong_d_t d; //阴阳遁
    loong_sy_t sy;
    loong_q_t q;
    loong_j_t j;
    loong_gz_t xs; // 旬首
    loong_tg_t ft; // 符头
} loong_cf_t;

#endif // LOONGIFY_STDDEF_H
