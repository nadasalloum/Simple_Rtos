


#ifndef OS_H_
#define OS_H_
#include "main.h"
#define MAX_NUM_OF_TASKS 	((uint8_t)3)

typedef void (*fncPtr)(void);           /**< Function pointer for registering tasks. */


typedef enum
{
	BLOCKED,
	READY,
	SUSPENDED
} OS_state;


/*Task Control Block*/
typedef struct
{
	fncPtr		function;
	uint8_t		task_periodicity;
	OS_state	task_state;
} OS_struct;


typedef enum
{
	OK_task,
	NOK_NULL_POINTER,
	NOK_COUNT_LIMIT,
	NOK_TIME_LIMIT,
	NOK_UNKNOWN
} OS_feedback;


OS_feedback OS_TaskCreate(fncPtr task, uint8_t periodicity, OS_state default_state);

void Sechdular(void);

void OS_TaskExecution(void);






#endif /* OS_H_ */
