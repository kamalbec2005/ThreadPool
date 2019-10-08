/*
 * thread_pool__wrap.c
 *
 *  Created on: 10-Sep-2019
 *      Author: kamal
 */

#include "thread_pool_wrap.h"
#include <sched.h>

/*
	To keep data in queue
*/
typedef struct _stGrp1Req{
	char *msg;
	void *data;
}stGrp1Req;

typedef struct _stGrp2Req{
	char *msg;
	void *data;
}stGrp2Req;

typedef struct _stThredsInfo{
	pthread_t apGrp2Threads[MAX_GRP2_THREADS];
	pthread_t apGrp1Threads[MAX_GRP1_THREADS];
}stThreadsInfo;

static stGrp1Req stGrp1Queue[MAX_SINGN_Q_CACHE];
static stGrp2Req stGrp2Queue[MAX_GRP2_Q_CACHE];
static stThreadsInfo pstThreadsInfo;

static void create_thread_pool();
static stGrp1Req* wrap_grp1_pop(void);
static stGrp2Req* wrap_grp2_pop(void);
static int wrap_sing_push(char *msg, void *data);
static int wrap_grp2_push(char *msg, void *data);

/*
Function	: wrap_init
Procedure	: 1) Create sing and grp2 queues
		  2) Create threads
		  3) Start threads
Return		: SUCCESS if there is no issue
		  FAIL if there is any failure
*/
uint8_t wrap_init(void)
{
	/*Creating threads*/
	create_thread_pool();
	return SUCCESS;
}

void* wrap_singn_thread(void *data)
{
	/*dequeue the messaage*/
	
}

void* wrap_grp2_thread(void *data)
{
}

static void create_thread_pool()
{
	printf("Going to create thread pool\n");
	
	pthread_attr_t grp1_tattr;
	pthread_attr_t grp2_tattr;
	struct sched_param param;
	
	/* initialized with default attributes */
	pthread_attr_init (&grp1_tattr);	

	/* Gettig thread scheduler*/
	pthread_attr_getschedparam(&grp1_tattr, &param);
	printf("Actual priority = %d\n", param.sched_priority);
	param.sched_priority = 0;

	for (int i=0; i<MAX_GRP1_THREADS; i++)
	{
		pthread_create(&pstThreadsInfo.apGrp1Threads[i], &grp1_tattr, wrap_singn_thread, NULL);
	}
	
	/* initialized with default attributes */
	pthread_attr_init (&grp2_tattr);	

	/* Gettig thread scheduler*/
	pthread_attr_getschedparam(&grp2_tattr, &param);
	param.sched_priority = 20;

	for (int i=0; i<MAX_GRP2_THREADS; i++)
	{
		pthread_create(&pstThreadsInfo.apGrp2Threads[i], &grp2_tattr, wrap_grp2_thread, NULL);
	}
}
