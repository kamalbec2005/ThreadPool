#include <stdio.h>
#include <pthread.h>
#include <types.h>

#ifndef _TP_WRAP_
#define _TP_WRAP_

#define TP_SUCCES:S 0
#define TP_FAILURE -1

#define MAX_GRP1_Q_CACHE 100
#define MAX_GRP2_Q_CACHE 100
#define MAX_GRP1_THREADS 1
#define MAX_GPR2_THREADS 4

uint8_t wrap_init(void);
uint8_t wrap_deinit(void);

#endif
