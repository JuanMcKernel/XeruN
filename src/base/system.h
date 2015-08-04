

#ifdef __cplusplus
extern "C" {
#endif

/*
 * DEBUGGING
 */

void dbg_msg(const char *sys, const char *fmt, ...);


/*
 * MEMORY
 */

void mem_zero(void *block, unsigned size);
void* mem_alloc(unsigned size, unsigned amount);

/*
 * STRINGS
 */

void str_format(char *buffer, int buffer_size, const char *format, ...);


#ifdef __cplusplus
}
#endif
