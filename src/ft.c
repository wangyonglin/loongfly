#include <loongify/ft.h>
/**
 * @brief 根据干支判断三元（上/中/下元）
 * @param gz  输入干支结构体
 * @param sy  输出三元结果
 * @return 成功返回0，参数非法/非符头返回-1
 * 规则：
 * 符头：甲、己日
 * 上元：子、午、卯、酉
 * 中元：寅、申、巳、亥
 * 下元：辰、戌、丑、未
 */
int loongify_ft_sy(const loongify_ft_t ft, loongify_ft_sy_t *sy)
{
    // 空指针整体校验
    if (!sy)
    {
        return -1;
    }

    // 仅甲、己为符头，判断三元
    if (ft.tg == TG_JIA || ft.tg == TG_JI)
    {
        // 上元
        if (ft.dz == DZ_ZI || ft.dz == DZ_WU || ft.dz == DZ_MAO || ft.dz == DZ_YOU)
        {
            *sy = SY_H;
            return 0;
        }
        // 中元
        else if (ft.dz == DZ_YIN || ft.dz == DZ_SHEN || ft.dz == DZ_SI || ft.dz == DZ_HAI)
        {
            *sy = SY_M;
            return 0;
        }
        // 下元
        else if (ft.dz == DZ_CHEN || ft.dz == DZ_XU || ft.dz == DZ_CHOU || ft.dz == DZ_WEI)
        {
            *sy = SY_L;
            return 0;
        }
    }

    // 非甲/己符头 或 地支不匹配
    return -1;
}


/**
 * @brief 由任意干支，向前推算最近的符头干支
 * @param gz 当前干支
 * @param ft  输出：对应符头干支
 * @return 0成功，-1参数非法
 */
int loongify_ft(const loongify_gz_t gz,loongify_ft_t *ft)
{
    if (!ft)
        return -1;

    loongify_tg_t tg = gz.tg;
    loongify_dz_t dz = gz.dz;

    // 最多遍历60次（一甲子循环）
    for (int i = 0; i < 60; i++)
    {
        // 判断是否为符头天干：甲、己
        if (tg == TG_JIA || tg == TG_JI)
        {
            ft->tg = tg;
            ft->dz = dz;
            return 0;
        }

        // 干支向前递推一位
        // 地支循环
        dz = (dz - 1) < DZ_ZI ? DZ_HAI : (loongify_dz_t)(dz - 1);
        // 天干循环
        tg = (tg - 1) < TG_JIA ? TG_GUI : (loongify_tg_t)(tg - 1);
    }

    return -1;
}
