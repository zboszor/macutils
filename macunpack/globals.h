#include <stdio.h>
#include <stdlib.h>

extern void dir(char *hdr);

#ifdef BIN
extern void bin(char *header, int data_size, int UMcp);
#endif /* BIN */
#ifdef JDW
extern void jdw(unsigned long ibytes);
#endif /* JDW */
#ifdef STF
extern void stf(unsigned long ibytes);
#endif /* STF */
#ifdef LZC
extern void lzc(char *ohdr);
#endif /* LZC */
#ifdef ASQ
extern void asq();
#endif /* ASQ */
#ifdef ARC
extern void arc();
#endif /* ARC */
#ifdef PIT
extern void pit();
#endif /* PIT */
#ifdef SIT
extern void sit();
#endif /* SIT */
#ifdef DIA
extern void dia(unsigned char *bin_hdr);
#endif /* DIA */
#ifdef CPT
extern void cpt();
#endif /* CPT */
#ifdef ZMA
extern void zma(char *start, unsigned long length);
#endif /* ZMA */
#ifdef LZH
extern void lzh(int kind);
#endif /* LZH */
#ifdef DD
extern void dd_file(unsigned char *bin_hdr);
extern void dd_arch(unsigned char *bin_hdr);
#endif /* DD */

extern unsigned char (*lzah_getbyte)();
void de_lzh(long ibytes, long obytes, char **data, int bits);

extern void do_error();
extern void mcb(char *hdr, unsigned long rsrcLength, unsigned long dataLength, int toread);
extern void de_lzah(unsigned long obytes);
extern void cpt_wrfile1(unsigned char *in_char, unsigned long ibytes, unsigned long obytes, int type, unsigned long blocksize);

extern char info[];
extern char text[];

extern int list, verbose, info_only, query, write_it, indent, dir_skip, no_dd;
extern FILE *infp;

extern int in_data_size, in_rsrc_size, in_ds, in_rs, ds_skip, rs_skip;

