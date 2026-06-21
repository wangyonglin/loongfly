#if !defined(LOONGIFY_GZ_H)
#define LOONGIFY_GZ_H

#include <string.h>   // for strcmp



typedef unsigned char loongify_tg_s_t[4];
typedef unsigned char loongify_dz_s_t[4];


// 十天干，取值范围 1~10
typedef enum {
    TG_JIA = 1,  // 甲
    TG_YI,       // 乙
    TG_BING,     // 丙
    TG_DING,     // 丁
    TG_WU,       // 戊
    TG_JI,       // 己
    TG_GENG,     // 庚
    TG_XIN,      // 辛
    TG_REN,      // 壬
    TG_GUI       // 癸
} loongify_tg_t;

// 十二地支，取值范围 1~12
typedef enum {
    DZ_ZI = 1,   // 子
    DZ_CHOU,     // 丑
    DZ_YIN,      // 寅
    DZ_MAO,      // 卯
    DZ_CHEN,     // 辰
    DZ_SI,       // 巳
    DZ_WU,       // 午
    DZ_WEI,      // 未
    DZ_SHEN,     // 申
    DZ_YOU,      // 酉
    DZ_XU,       // 戌
    DZ_HAI       // 亥
} loongify_dz_t;



// 干支组合结构体
typedef struct {
    loongify_tg_t tg;
    loongify_dz_t dz;
} loongify_gz_t;



// 干支组合结构体
typedef struct {
    loongify_tg_s_t tg_s;
    loongify_dz_s_t dz_s;
} loongify_gz_s_t;


// 全局名称数组（和前面转换函数共用）
static const char *tg_list[] = {
    NULL, "甲", "乙", "丙", "丁", "戊",
    "己", "庚", "辛", "壬", "癸"
};

static const char *dz_list[] = {
    NULL, "子", "丑", "寅", "卯", "辰", "巳",
    "午", "未", "申", "酉", "戌", "亥"
};


// 根据字符串获取天干枚举值（例如 "甲" -> TG_JIA）
int loongify_tg_s_tg(const loongify_tg_s_t tg_s, loongify_tg_t * tg);

// 根据字符串获取地支枚举值（例如 "子" -> DZ_ZI）
int loongify_dz_s_dz(const loongify_dz_s_t dz_s, loongify_dz_t * dz);


int loongify_s_gz(const loongify_tg_s_t tg_s, const loongify_dz_s_t dz_s, loongify_gz_t *gz);
// 根据天干/地支的字符串构建干支结构体（成功返回0，失败返回-1）
int loongify_gz(const loongify_tg_t tg, const loongify_dz_t dz, loongify_gz_t *gz);

// 将干支结构体转换为字符串（如 "甲子"），需要调用者提供缓冲区
int loongify_gz_s(loongify_gz_t gz, loongify_gz_s_t *gz_s);

void loongify_gz_p(const loongify_gz_t gz);






#endif // LOONGIFY_GZ_H
