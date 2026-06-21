#if !defined(LOONGIFY_XS_H)
#define LOONGIFY_XS_H

#include "gz.h"

/**
 * @brief 符首(六仪)枚举，对应六甲旬首
 * 遁甲规则：甲隐而不显，以六仪代六甲
 */
typedef enum{
    FS_WU=TG_WU,   // 戊 → 对应 甲子旬首
    FS_JI=TG_JI,   // 己 → 对应 甲戌旬首
    FS_GENG=TG_GENG, // 庚 → 对应 甲申旬首
    FS_XIN=TG_XIN,  // 辛 → 对应 甲午旬首
    FS_REN=TG_REN,  // 壬 → 对应 甲辰旬首
    FS_GUI=TG_GUI  // 癸 → 对应 甲寅旬首
} loongify_fs_t;

/**
 * @brief 六甲旬首枚举（奇门/干支旬首）
 * 顺序：甲子 → 甲戌 → 甲申 → 甲午 → 甲辰 → 甲寅
 */
// typedef enum {
//     XS_JZ,  // 甲子旬首
//     XS_JX,  // 甲戌旬首
//     XS_JS,  // 甲申旬首
//     XS_JW,  // 甲午旬首
//     XS_JC,  // 甲辰旬首
//     XS_JY   // 甲寅旬首
// } loongify_xs_t;

typedef loongify_gz_t loongify_xs_t;

int loongify_fs(loongify_xs_t xs, loongify_fs_t *fs);
int loongify_xs(const loongify_gz_t gz,loongify_xs_t * xs);
// loongify_gz_t loongify_xs_gz(const loongify_xs_t ft);


#endif // LOONGIFY_XS_H
