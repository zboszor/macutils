#include <stdio.h>
#include <string.h>

extern void dl(char *macname, char *filename);
extern void hecx(char *macname, char *filename);
extern void hqx(char *macname);
extern void mu(char *macname);

extern char info[];
extern char trname[];

struct macheader {
	char m_name[128];
	char m_type[4];
	char m_author[4];
	short m_flags;
	long m_datalen;
	long m_rsrclen;
	long m_createtime;
	long m_modifytime;
};

extern struct macheader mh;

extern int listmode;
extern int verbose;
extern int info_only;
extern int uneven_lines;
extern int to_read;
extern int was_macbin;

extern FILE *ifp;

extern void do_error();

