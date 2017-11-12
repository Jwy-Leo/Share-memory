#pragma once
#include<windows.h>
#include<winBase.h>
#include<conio.h>
/*ERROR IMFORMATION*/
#define BIG_SIZE   100
#define NO_MEMORY  200
#define UN_LOAD    300
#define MEM_LOCK   400
class Share_memory
{
	HANDLE Memory_Deside_Destination;
	LPCTSTR Memory_Destination;

	int size;
	char name[20];

	void Write_data(LPCTSTR destination,char* data);
	LPCTSTR LinkMemory(HANDLE Memory_Deside_Destination,int Size);
	HANDLE Create_momory(char* memory_name,int Size);
	void Unlock();
public:
	Share_memory(char* memory_name,int Size);
	~Share_memory();
	int Write(char* data);											//return ERROR CODE
	char* WhoIsShareMem();
};

