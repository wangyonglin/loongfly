#if !defined(LOONG_STDLIB_H)
#define LOONG_STDLIB_H

#include <loong/stddef.h>

//始化干支结构
loong_gz_t loong_gz_init(loong_tg_t tg, loong_dz_t dz);
//天干转字符
const char* loong_tg_str(const loong_tg_t tg);
//干支转字符
loong_gz_s loong_gz_str(const loong_gz_t gz);

//定局查询:干支->[甲&己]->旬首
int loong_gz_xs_ex(const loong_gz_t gz,loong_gz_t *jj);

//定三元局
loong_sy_t loong_sy_make(const loong_gz_t xs_ex);

//定局查询:干支->[甲]->旬首
int loong_gz_xs(const loong_gz_t gz,loong_gz_t *xs);

//定局查询:干支->[甲]->旬首->六仪[符头]
int loong_gz_ft(const loong_gz_t gz,loong_tg_t *ft);

loong_j_t loong_j_make(const loong_gz_t gz);

loong_gz4_t loong_gz4_make();

int loong_gz4_init(const loong_gz4_t gz4,loong_cf_t *cf);
/**
 * @brief 打印四柱干支（年、月、日、时）
 * @param gz4 四柱结构体（传值方式）
 */
void loong_gz4_echo(const loong_gz4_t gz4);


#endif // LOONG_STDLIB_H
