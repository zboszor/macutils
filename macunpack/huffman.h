#define	HUFF_BE		0
#define	HUFF_LE		1

struct node {
    int flag, byte;
    struct node *one, *zero;
};
typedef struct node node;

extern int (*get_bit)();
extern void clrhuff();

extern struct node nodelist[];
extern int bytesread;

extern int gethuffbyte(node *l_nodelist);
