typedef struct real_time {
	int year;
	int month;
	int day;
	int hours;
	int minutes;
	int seconds;
} real_time;

extern unsigned long get4(char *bp);
extern unsigned long get4i(char *bp);
extern unsigned long get2(char *bp);
extern unsigned long get2i(char *bp);
extern unsigned char getb(FILE *fp);
extern void copy(char *d, char *s, int n);
extern int do_query();
extern void put4(char *dest, unsigned long value);
extern void put2(char *dest, unsigned long value);
extern void do_indent(int indent);
extern real_time set_time(int year, int month, int day, int hours, int minutes, int seconds);
extern unsigned long tomactime(real_time time);
extern real_time frommactime(unsigned long accum);
extern void transname(char *name, char *namebuf, int n);
extern void backtrans(char *macname, char *name);
