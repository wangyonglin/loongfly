#include <loongify/xs.h>

// /**
//  * @brief 根据旬首枚举，获取对应六甲干支
//  * @param ft 旬首枚举
//  * @return 对应干支结构体，非法值返回空干支
//  */
// loongify_gz_t loongify_xs_gz(const loongify_xs_t ft)
// {
//     loongify_gz_t gz = {0}; // 初始化为0，作为非法标识

//     switch (ft)
//     {
//         case XS_JZ: // 甲子
//             loongify_gz(TG_JIA,DZ_ZI, &gz);
//             break;
//         case XS_JX: // 甲戌
//             loongify_gz(TG_JIA, DZ_XU, &gz);
//             break;
//         case XS_JS: // 甲申
//             loongify_gz(TG_JIA, DZ_SHEN, &gz);
//             break;
//         case XS_JW: // 甲午
//             loongify_gz(TG_JIA, DZ_WU, &gz);
//             break;
//         case XS_JC: // 甲辰
//             loongify_gz(TG_JIA, DZ_CHEN, &gz);
//             break;
//         case XS_JY: // 甲寅
//             loongify_gz(TG_JIA, DZ_YIN, &gz);
//             break;
//         default:
//             // 非法旬首，保持初始0值
//             break;
//     }

//     return gz;
// }

int loongify_xs(const loongify_gz_t gz, loongify_xs_t *xs)
{
    // 输出指针判空
    if (NULL == xs)
    {
        return -1;
    }

    // 校验天干、地支枚举范围
    if (gz.tg < TG_JIA || gz.tg > TG_GUI || gz.dz < DZ_ZI || gz.dz > DZ_HAI)
    {
        return -1;
    }

    int diff = gz.dz - gz.tg;
    if (diff < 0)
    {
        diff += 12;
    }

    switch (diff)
    {
        case 0:
        case 12:
            loongify_gz(TG_JIA, DZ_ZI, xs); // 甲子旬
            break;
        case 10:
            loongify_gz(TG_JIA, DZ_XU, xs); // 甲戌旬
            break;
        case 8:
            loongify_gz(TG_JIA, DZ_SHEN, xs); // 甲申旬
            break;
        case 6:
            loongify_gz(TG_JIA, DZ_WU, xs); // 甲午旬
            break;
        case 4:
            loongify_gz(TG_JIA, DZ_CHEN, xs); // 甲辰旬
            break;
        case 2:
            loongify_gz(TG_JIA, DZ_YIN, xs); // 甲寅旬
            break;
        default:
            return -1;    // 计算异常
    }

    return 0;
}



/**
 * @brief 旬首枚举 转换为 对应符首(六仪)
 * @param xs 输入旬首
 * @param fs 输出符首
 * @return 成功返回0，非法值返回-1
 */
int loongify_fs(loongify_xs_t xs, loongify_fs_t *fs)
{
    if (NULL == fs)
    {
        return -1;
    }
    if(xs.tg!=TG_JIA) return -1;

    switch (xs.dz)
    {
        case DZ_ZI:  *fs = FS_WU;    break; // 甲子 → 戊
        case DZ_XU:  *fs = FS_JI;    break; // 甲戌 → 己
        case DZ_SHEN:  *fs = FS_GENG;  break; // 甲申 → 庚
        case DZ_WU:  *fs = FS_XIN;   break; // 甲午 → 辛
        case DZ_CHEN:  *fs = FS_REN;   break; // 甲辰 → 壬
        case DZ_YIN:  *fs = FS_GUI;   break; // 甲寅 → 癸
        default:
            return -1;
    }
    return 0;
}
