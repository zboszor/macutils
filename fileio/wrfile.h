extern char *out_buffer, *out_ptr;

extern void define_name(char *text);
extern void start_info(char *info, unsigned long rsize, unsigned long dsize);
extern void start_rsrc();
extern void start_data();
extern void end_file();
#ifdef SCAN
extern void do_idf();
#endif /* SCAN */
extern void do_mkdir(char *name, char *header);
extern void enddir();
extern char *get_mina();

