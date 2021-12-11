#ifndef _RINGBUF_H_        
#define _RINGBUF_H_                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
#include <pthread.h>

struct ringbuf_t
{
    pthread_mutex_t mutex;
    pthread_cond_t cond_full;
    pthread_cond_t cond_empty;
    int bufsiz;
    int front;
    int back;
    char* buf;
};

extern struct ringbuf_t* rb_init(int bufsiz);

extern void rb_finalize(struct ringbuf_t* rb);

extern int rb_size(struct ringbuf_t* rb);

extern int rb_is_full(struct ringbuf_t* rb);

extern int rb_is_empty(struct ringbuf_t* rb);

extern void rb_insert(struct ringbuf_t* rb, int c);

extern int rb_remove(struct ringbuf_t* rb);

#endif
