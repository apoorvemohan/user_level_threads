#include<stdio.h>
#include<stdlib.h>
#include<time.h>


struct qthread {
	long tid;
	struct qthread *prev;
	struct qthread *next;
	void* basePtr;
	void* offsetPtr;
	short detached;
	
}*activeThreadList = NULL,  *front = NULL, *rear = NULL;

void enqueueThread(struct qthread *newThread){

	if(activeThreadList == NULL) {

	activeThreadList = front = rear = newThread;	
	newThread->tid = 0;

	} else {

		newThread->next = front;
		front->prev = newThread;
		front = front->prev;
		activeThreadList = front;
		newThread->tid  = newThread->next->tid + 1; 
	}
}

void dequeueThread() {

	if(activeThreadList != NULL) {

		struct qthread* temp;		

		if(front == rear) {

			temp = rear;
			activeThreadList = front = rear = NULL;
		} else {

			temp = rear;
			rear = rear->prev;
			rear->next = NULL;
		}

		free(temp);
			
	} else
		fprintf(stderr, "No Active Threads!!! Unable to delete!!!\n");


}

int isQueueEmpty() {

	return (activeThreadList == NULL)?1:0;

}

void printThreadQueue() {

	if(activeThreadList){

		struct qthread *temp = activeThreadList;

		while(temp != NULL) {
			printf("%ld\n", temp->tid);
			temp = temp->next;
		}
	}
}


int main(){


struct qthread* dummyArray[10];

int i;

for(i=0;i<10;i++) {
	dummyArray[i] = (struct qthread*)malloc(sizeof(struct qthread));

}

for(i=0;i<10;i++)
	enqueueThread(dummyArray[i]); 

printThreadQueue();

}
