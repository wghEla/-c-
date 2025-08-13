#include <stdio.h> 
#include <stdlib.h>

typedef struct queue {
	int *data;
	int capacity;
	int front;
	int rear;
} Queue;

void init (Queue*pq,int capacity) {
	pq->data=(int *)malloc ((capacity+1)*sizeof(int));         //capacity+1的空间才能容纳capacity个元素 
	pq->capacity=capacity;
	pq->front=pq->rear=0;
}
//初始化 

int isEmpty (Queue*pq) {
	return pq->front==pq->rear;
}

int isFull (Queue *pq) {
	return pq->front==(pq->rear+1)%(pq->capacity+1);        //满：即rear再往下移就与front重合了 
}

int enQueue (Queue*pq,int x) {
	int flag=0;
	if (isFull(pq)) {
	} else {
		pq->data[pq->rear]=x;
		pq->rear=(pq->rear+1)%(pq->capacity+1);                 //循环% 
		flag=1;
	}
	return flag;
}
//入队 

int deQueue (Queue*pq,int* x) {
	int flag=0;
	if (isEmpty(pq)) {
	} else {
		*x=pq->data[pq->front];
		pq->front=(pq->front+1)%(pq->capacity+1);                       //循环% 
		flag=1;
	}
	return flag;
}
//出队 


int main()
{
	Queue q;
	int capacity;
	init(&q,capacity);
	return 0;
}
