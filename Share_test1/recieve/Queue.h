#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct A{
	int hour;
	int minute;
	int second;
	char detation[300];
	struct A *next;
}Data;
typedef struct Q{
	Data *front;
	Data *rear;
}Queue;
Queue* initial_queue();
Data* initial_data(int);
void Enqueue(Queue**,Data**);
Data* Dequeue(Queue**);
Data* FindFront(Queue*);
Data* FindRear(Queue*);
bool isEmpty(Queue* );
void flush(Queue*,int ,int ,int );