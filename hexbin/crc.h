#define INITCRC binhex_crcinit

extern unsigned long crc;
extern unsigned long binhex_crcinit;
extern unsigned long binhex_updcrc(unsigned long icrc, unsigned char *icp, int icnt);

extern void comp_q_crc(register unsigned int c);
extern void comp_q_crc_n(register unsigned char *s, register unsigned char *e);
extern void verify_crc(unsigned long calc_crc, unsigned long file_crc);
