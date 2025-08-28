#define XMODEM	0
#define YMODEM	1
#define ZMODEM	2

extern int xfertype;
extern int pre_beta;
extern int time_out;

extern void setup_tty();
extern void reset_tty();
extern void cleanup(int sig);
extern void timedout(int sig);
extern int tgetc(int timeout);
extern int tgetrec(char *buf, int count, int timeout);
extern void tputc(int c);
extern void tputrec(char *buf, int count);
extern void xm_to();
extern void xm_from();
