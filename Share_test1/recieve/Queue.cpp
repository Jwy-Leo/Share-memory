#include"Queue.h"
Queue* initial_queue()
{
	Queue *Q=(Queue*)malloc(sizeof(Queue));
	Q->front=NULL;
	Q->rear=NULL;
	return Q;
}

Data* initial_data(int H,int M,int S,char *A)
{
	Data *D=(Data*)malloc(sizeof(Data));
	D->hour=H;
	D->minute=M;
	D->second=S;
	strcpy(D->detation,A);
	D->next=NULL;
	return D;
}
void Enqueue(Queue **Q,Data **D)
{
	Queue *queue=*Q;
	if(queue==NULL)
		queue=initial_queue();
	if(isEmpty(queue))
	{
		queue->front=*D;
		queue->rear=*D;
	}
	else
	{
		if(queue->front==queue->rear)
		{
			queue->front->next=*D;
			queue->rear=*D;
		}
		else
		{
			queue->rear->next=*D;
			queue->rear=*D;
		}
	}
}
Data* Dequeue(Queue **Q)
{
	Queue *queue=*Q;
	Data *D=NULL;
	if(!isEmpty(*Q))
	{
		D=FindFront(queue);
		if(D!=FindRear(queue))
		{
			queue->front=D->next;
			D->next=NULL;
		}
		else
		{
			queue->front=NULL;
			queue->rear=NULL;
			D->next=NULL;
		}
	}
	return D;
}
Data* FindFront(Queue *Q)
{
	return Q->front;
}
Data* FindRear(Queue *Q)
{
	return Q->rear;
}
bool isEmpty(Queue* Q)
{
	if(Q->front==NULL&&Q->rear==NULL)
		return true;
	else
		return false;
}
void flush(Queue* Q,int H,int M,int S)
{
	Data *FREE=NULL;
	if(H==NULL)
		if(Q->front->minute==M&&Q->front->second==S)
		{
			 FREE=Dequeue(&Q);
			 if(FREE!=NULL)
				delete FREE;
			 flush(Q,H,M,S);
		}
	else if(H==NULL&&M==NULL)
		if(Q->front->second==S)
		{
			FREE=Dequeue(&Q);
			if(FREE!=NULL)
				delete FREE;
			flush(Q,H,M,S);
		}
	else
		if(Q->front->hour==H&&Q->front->minute==M&&Q->front->second==S)
		{
			FREE=Dequeue(&Q);
			if(FREE!=NULL)
				delete FREE;
			flush(Q,H,M,S);
		}
}