#pragma once
#include<windows.h>
#include<winBase.h>
#include"Queue.h"
#define NOT_CHANGE 100
#define NO_MEMORY  200
class Get_Share_memory
{
	HANDLE Memory_Deside_Destination;
	LPCTSTR Memory_Destination;
	int size;
	char name[20];
	LPCTSTR LinkMemory(HANDLE Memory_Deside_Destination,int Size);
	void Unlock();
	Queue *Q; 
public:
	Get_Share_memory(char* memory_name,int Size);
	~Get_Share_memory(void);
	HANDLE Connect_Decide_MemoryIS(char* memory_name);
	int Read(Queue **B);
	void get_handle();
};

