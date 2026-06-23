#include <loong/stdlib.h>
#include <stdio.h>
#include <string.h>

// 如果采用结构体
loong_gz_t loong_gz_init(loong_tg_t tg, loong_dz_t dz)
{
    return (loong_gz_t){.tg = tg, .dz = dz};
}

const char *loong_tg_str(const loong_tg_t tg)
{
    if (tg >= TG_JIA && tg <= TG_GUI)
        return TG_NAMES[tg];
    return (const char *)"?";
}
loong_gz_s loong_gz_str(const loong_gz_t gz)
{
    loong_gz_s gz_s;
    memset(&gz_s, 0x00, sizeof(loong_gz_s));
    strcpy(gz_s.tg, TG_NAMES[gz.tg]);
    strcpy(gz_s.dz, DZ_NAMES[gz.dz]);
    return gz_s;
}

// 根据干支反查六十甲子序号（索引0~59），未找到返回 -1
int loong_get_gz_index(loong_tg_t tg, loong_dz_t dz)
{
    for (int i = 0; i < 60; i++)
    {
        if (LOONG_GZ[i].tg == tg && LOONG_GZ[i].dz == dz)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief 定局查询：根据日干支查找符头（最近的甲日或己日）
 * @param gz   输入的日干支（如乙丑日）
 * @param ft   输出参数，存放查到的符头干支（如甲子日）
 * @return int 成功返回 0，失败（空指针或无效干支）返回 -1
 */
int loong_gz_xs_ex(const loong_gz_t gz, loong_gz_t *jj)
{
    // 1. 空指针保护
    if (jj == NULL)
    {
        return -1;
    }

    // 2. 获取当前日干支在六十甲子中的序号
    int idx = loong_get_gz_index(gz.tg, gz.dz);
    if (idx == -1)
    {
        return -1; // 无效的干支组合
    }

    // 3. 向前循环查找（由于甲和己间隔5天，while循环最多执行5次）
    while (1)
    {
        loong_gz_t current = LOONG_GZ[idx];
        // 判断是否为符头：天干为甲 或 天干为己
        if (current.tg == TG_JIA || current.tg == TG_JI)
        {
            *jj = current; // 将找到的符头赋值给输出参数
            return 0;      // 查找成功
        }
        // 未找到，日期回退一天（注意循环到59再回0）
        idx = (idx - 1 + 60) % 60;
    }
}

/**
 * @brief 定局查询：根据任意干支查找其所属旬首（甲子、甲戌等）
 * @param gz   输入的干支（如乙丑）
 * @param xs   输出参数，存放查到的旬首干支（如甲子）
 * @return int 成功返回 0，失败（空指针或无效干支）返回 -1
 */
int loong_gz_xs(const loong_gz_t gz, loong_gz_t *xs)
{
    // 1. 空指针保护
    if (xs == NULL)
        return -1;

    // 2. 获取当前干支在六十甲子中的序号 (0~59)
    int idx = loong_get_gz_index(gz.tg, gz.dz);
    if (idx == -1)
    {
        return -1; // 无效的干支组合
    }

    // 3. 计算旬首索引：每10个一组，直接取整向下（C语言整数除法自动截断）
    int xs_idx = (idx / 10) * 10;

    // 4. 将查到的旬首赋值给输出参数
    *xs = LOONG_GZ[xs_idx];

    return 0;
}

int loong_gz_ft(const loong_gz_t gz, loong_tg_t *ft)
{
    if (ft == NULL)
        return -1;

    loong_gz_t xs_j;
    // 调用求旬首函数，需要确保这个函数已定义
    if (loong_gz_xs(gz, &xs_j) != 0)
        return -1; // 如果求旬首失败

    switch (xs_j.dz)
    {
    case DZ_ZI: // 甲子
        *ft = TG_WU;
        break;
    case DZ_XU: // 甲戌
        *ft = TG_JI;
        break;
    case DZ_SHEN: // 甲申
        *ft = TG_GENG;
        break;
    case DZ_WU: // 甲午
        *ft = TG_XIN;
        break;
    case DZ_CHEN: // 甲辰
        *ft = TG_REN;
        break;
    case DZ_YIN: // 甲寅
        *ft = TG_GUI;
        break;
    default:
        return -1; // 无效的旬首地支（理论上不会发生）
    }
    return 0;
}

// 干支查旬首
//  int  loong_c_init(const loong_gz_t gz,loong_c_t *c){

//         // 输出指针判空
//     if (NULL == c)
//     {
//         return -1;
//     }

//     // 校验天干、地支枚举范围
//     if (gz.tg < TG_JIA || gz.tg > TG_GUI || gz.dz < DZ_ZI || gz.dz > DZ_HAI)
//     {
//         return -1;
//     }

//     int diff = gz.dz - gz.tg;
//     if (diff < 0)
//     {
//         diff += 12;
//     }

//     switch (diff)
//     {
//         case 0:
//         case 12:
//             c->xs=loong_gz_init(TG_JIA, DZ_ZI); // 甲子旬
//             c->ft=TG_WU;  // 甲子 → 戊
//             break;
//         case 10:
//             c->xs=loong_gz_init(TG_JIA, DZ_XU); // 甲戌旬
//             c->ft=TG_JI;  // 甲戌 → 己
//             break;
//         case 8:
//             c->xs=loong_gz_init(TG_JIA, DZ_SHEN); // 甲申旬
//             c->ft=TG_GENG;  //甲申 → 庚
//             break;
//         case 6:
//             c->xs=loong_gz_init(TG_JIA, DZ_WU); // 甲午旬
//             c->ft=TG_XIN;  // 甲午 → 辛
//             break;
//         case 4:
//             c->xs=loong_gz_init(TG_JIA, DZ_CHEN); // 甲辰旬
//             c->ft=TG_REN;  // 甲辰 → 壬
//             break;
//         case 2:
//             c->xs=loong_gz_init(TG_JIA, DZ_YIN); // 甲寅旬
//             c->ft=TG_GUI;  // 甲寅 → 癸
//             break;
//         default:
//             return -1;    // 计算异常
//     }

//     return 0;

// }

loong_j_t loong_j_make(const loong_gz_t gz)
{

    loong_gz_t ft_ex;
    if (loong_gz_xs_ex(gz, &ft_ex) != 0)
        return JU0;
}

loong_sy_t loong_sy_make(const loong_gz_t xs_ex)
{
    if (xs_ex.tg == TG_JIA || xs_ex.tg == TG_JI)
    {
        // 上元
        if (xs_ex.dz == DZ_ZI || xs_ex.dz == DZ_WU || xs_ex.dz == DZ_MAO || xs_ex.dz == DZ_YOU)
        {
            return LOONG_SY_H;
        }
        // 中元
        else if (xs_ex.dz == DZ_YIN || xs_ex.dz == DZ_SHEN || xs_ex.dz == DZ_SI || xs_ex.dz == DZ_HAI)
        {
            return LOONG_SY_M;
        }
        // 下元
        else if (xs_ex.dz == DZ_CHEN || xs_ex.dz == DZ_XU || xs_ex.dz == DZ_CHOU || xs_ex.dz == DZ_WEI)
        {
            return LOONG_SY_L;
        }
    };
    return LOONG_SY_N;
}

loong_gz4_t loong_gz4_make()
{
    loong_gz4_t gz4 = {.year = {.tg = TG_WU, .dz = DZ_CHEN},
                       .month = {.tg = TG_XIN, .dz = DZ_YOU},
                       .day = {.tg = TG_JI, .dz = DZ_MAO},
                       .hour = {.tg = TG_DING, .dz = DZ_MAO}};
    return gz4;
}
/**
 * @brief 打印四柱干支（年、月、日、时）
 * @param gz4 四柱结构体（传值方式）
 */
void loong_gz4_echo(const loong_gz4_t gz4)
{
    loong_gz_s y = loong_gz_str(gz4.year);
    loong_gz_s m = loong_gz_str(gz4.month);
    loong_gz_s d = loong_gz_str(gz4.day);
    loong_gz_s h = loong_gz_str(gz4.hour);
    printf("年柱：%s%s  ", y.tg, y.dz);
    printf("月柱：%s%s  ", m.tg, m.dz);
    printf("日柱：%s%s  ", d.tg, d.dz);
    printf("时柱：%s%s\n", h.tg, h.dz);
}

int loong_gz4_init(const loong_gz4_t gz4,loong_cf_t *cf)
{
    if (cf == NULL)
        return -1;
    loong_gz4_echo(gz4);
    loong_gz_xs(gz4.hour, &cf->xs);
    loong_gz_s xs_s = loong_gz_str(cf->xs);
    printf("旬首[甲]->%s%s\n", xs_s.tg, xs_s.dz);

    loong_tg_t ft;
    loong_gz_ft(gz4.hour, &cf->ft);
    const char *ft_s = loong_tg_str(cf->ft);
    printf("符头->%s\n", ft_s);
    loong_gz_ft(gz4.day, &ft);

   loong_sy_t sy= loong_sy_make(gz4.day);
   if(sy==LOONG_SY_N)return -1;
   
    return 0;
}