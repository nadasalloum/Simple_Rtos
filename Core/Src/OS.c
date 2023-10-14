
#include "os.h"

extern uint32_t tick_counts;
static uint8_t Number_of_tasks=0;
static OS_struct arr[MAX_NUM_OF_TASKS];
OS_feedback OS_TaskCreate(fncPtr function, uint8_t periodicty, OS_state default_state){
	OS_feedback status=	NOK_UNKNOWN;
	
	if(Number_of_tasks>=MAX_NUM_OF_TASKS){
		status=NOK_COUNT_LIMIT;
        	}
	else if(function==NULL){
	 	status =NOK_NULL_POINTER;
	    }

  else{
	arr[Number_of_tasks].function=function;
	arr[Number_of_tasks].task_periodicity=periodicty;
	arr[Number_of_tasks].task_state=default_state;
	status =OK_task;
	Number_of_tasks++;
      }
	return status;
}


void Sechdular(void){

	for(uint8_t i=0;i<Number_of_tasks;i++){
		
		if(arr[i].task_state!=SUSPENDED){
		     if(tick_counts%arr[i].task_periodicity==0){
			arr[i].task_state=READY;

			 }
		else{
			
			//do nothing
			
	         }
		}
	}
}

void OS_TaskExecution(void){

	uint8_t task_id;

 	for(task_id = 0; task_id < Number_of_tasks; task_id++)
 	{
		if(arr[task_id].task_state == READY)
 		{
			arr[task_id].function();
			arr[task_id].task_state = BLOCKED;
		}
 	}

}