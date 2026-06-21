#include <stdio.h>
#include <loongify/loongify.h>

int main()
{
    loongify_gz_t gz;
    // loongify_s_gz("丙", "寅", &gz);
    // loongify_s_gz("丁", "丑", &gz);
    // loongify_s_gz("乙", "丑", &gz);
    loongify_s_gz("辛", "酉", &gz);
    //  loongify_gz(TG_JI, DZ_MAO, &gz);
    // printf("干支索引：天干=%d, 地支=%d\n", gz.tg, gz.dz);
    

    // loongify_gz_s_t gz_s;
    // loongify_gz_s(gz, &gz_s);
    // printf("干支->%s%s\n", gz_s.tg_s, gz_s.dz_s);

    loongify_gz_p(gz);

    loongify_xs_t xs;
    loongify_xs(gz, &xs);
    loongify_fs_t fs;
    loongify_fs(xs, &fs);
    printf("旬首-> %s%s      符首-> %s\n",tg_list[xs.tg] ,dz_list[xs.dz],tg_list[fs]);

    loongify_ft_t ft;
    loongify_ft(gz, &ft);
    loongify_ft_sy_t sy;
    loongify_ft_sy(ft, &sy);
    printf("符头-> %s%s     三元-> %d\n", tg_list[ft.tg], dz_list[ft.dz],sy);
   
    return 0;
}