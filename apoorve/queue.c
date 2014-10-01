#include<stdio.h>
#include<stdlib.h>
#include<time.h>



}



int main(){


struct qthread* dummyArray[10];

int i;

for(i=0;i<10;i++) {
	dummyArray[i] = (struct qthread*)malloc(sizeof(struct qthread));

}

for(i=0;i<10;i++)
	insertThread(dummyArray[i]); 

printActiveThreadList();

}
