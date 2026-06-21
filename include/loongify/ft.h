#if !defined(LOONGIFY_FT_H)
#define LOONGIFY_FT_H

#include "gz.h"

//三元局类型
typedef enum {
    SY_H,SY_M,SY_L
}loongify_ft_sy_t;
typedef loongify_gz_t loongify_ft_t;


/**
 * @brief 由任意干支，向前推算最近的符头干支
 * @param gz 当前干支
 * @param ft  输出：对应符头干支
 * @return 0成功，-1参数非法
 */
int loongify_ft(const loongify_gz_t gz,loongify_ft_t *ft);


/**
 * @brief 根据干支判断符头所属三元（上/中/下元）
 * @param gz 干支结构体指针
 * @return 三元类型 / 错误码
 * 规则：
 * 符头：甲、己日
 * 上元：子、午、卯、酉
 * 中元：寅、申、巳、亥
 * 下元：辰、戌、丑、未
 */
int loongify_ft_sy(const loongify_ft_t ft, loongify_ft_sy_t *sy);
#endif // LOONGIFY_FT_H
