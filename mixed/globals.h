#include <stdio.h>
#include <stdlib.h>

extern void transname(char *name, char *namebuf, int n);

extern char info[];
extern char text[];

extern int list, info_only, query, write_it, indent, dir_skip;
extern FILE *infp;

extern int in_data_size, in_rsrc_size, in_ds, in_rs, ds_skip, rs_skip;

