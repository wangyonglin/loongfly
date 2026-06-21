#include <loongify/gz.h>
#include <string.h>
#include <stdio.h>

/**
 * @brief 天干字符串 → 天干枚举值转换
 * @param tg_s 输入天干汉字字符串（"甲"/"乙"...）
 * @param tg   输出：对应天干枚举
 * @return 成功返回0，失败返回-1
 */
int loongify_tg_s_tg(const loongify_tg_s_t tg_s, loongify_tg_t *tg)
{
    // 入参空校验
    if (NULL == tg_s || NULL == tg)
    {
        return -1;
    }

    // 遍历匹配
    for (int i = TG_JIA; i <= TG_GUI; i++)
    {
        if (strcmp(tg_s, tg_list[i]) == 0)
        {
            *tg = (loongify_tg_t)i;
            return 0;
        }
    }

    // 无匹配
    return -1;
}

/**
 * @brief 地支汉字字符串 转 地支枚举
 * @param dz_s 输入地支汉字字符串
 * @param dz   输出地支枚举值
 * @return 成功返回0，参数非法/匹配失败返回-1
 */
int loongify_dz_s_dz(const loongify_tg_s_t dz_s, loongify_dz_t *dz)
{
    // 空指针校验
    if (NULL == dz_s || NULL == dz)
    {
        return -1;
    }

    for (int i = DZ_ZI; i <= DZ_HAI; ++i)
    {
        if (strcmp(dz_s, dz_list[i]) == 0)
        {
            *dz = (loongify_dz_t)i;
            return 0;
        }
    }

    // 无匹配项
    return -1;
}

int loongify_s_gz(const loongify_tg_s_t tg_s, const loongify_dz_s_t dz_s, loongify_gz_t *gz)
{
    // 空指针校验
    if (NULL == gz)
    {
        return -1;
    }

    if (loongify_tg_s_tg(tg_s, &gz->tg) == 0)
    {
        if (loongify_dz_s_dz(dz_s, &gz->dz) == 0)
        {
            return 0;
        }
    }
    return -1;
}

int loongify_gz(const loongify_tg_t tg, const loongify_dz_t dz, loongify_gz_t *gz)
{
    // 空指针校验
    if (NULL == gz)
    {
        return -1;
    }
    gz->tg = tg;
    gz->dz = dz;
    return -1;
}

int loongify_gz_s(const loongify_gz_t gz, loongify_gz_s_t *gz_s)
{
    if (!gz_s)
        return -1;

    if (gz.tg < TG_JIA || gz.tg > TG_GUI || gz.dz < DZ_ZI || gz.dz > DZ_HAI)
        return -1;

    const char *tg_s = tg_list[gz.tg];
    const char *dz_s = dz_list[gz.dz];

    if (tg_s && dz_s)
    {
        // 复制字符串到数组（目标大小已知为4，足够存储 "甲"+'\0'）
        strcpy((char *)gz_s->tg_s, tg_s);
        strcpy((char *)gz_s->dz_s, dz_s);

        return 0;
    }
    return -1;
}


void loongify_gz_p(const loongify_gz_t gz){
    printf("[天干:%s-%d], [地支:%s-%d]\n",tg_list[gz.tg] ,gz.tg,dz_list[gz.dz], gz.dz);
}