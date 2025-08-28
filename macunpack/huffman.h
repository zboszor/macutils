#define	HUFF_BE		0
#define	HUFF_LE		1

struct node {
    int flag, byte;
    struct node *one, *zero;
};
typedef struct node node;

extern int (*get_bit)();
extern void de_compress(unsigned long ibytes, int mb);
extern void core_compress(char *ptr);
extern void de_huffman(unsigned long obytes);
extern void de_huffman_end(unsigned int term);
extern void set_huffman(int endian);
extern void read_tree();
extern void clrhuff();
extern int gethuffbyte(node *l_nodelist);
extern int getihuffbyte();

extern struct node nodelist[];
extern int bytesread;

