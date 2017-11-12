#include "Get_Share_memory.h"
/*---------------NEED-----------------*/
/***********FLUSH AND READ*************/
/***GET THE FRONT AND COPY TO MEMORY***/
/**GET LENGTH**************************/
/*------------------------------------*/
Get_Share_memory::Get_Share_memory(char* memory_name,int Size)
{
	this->size=Size;
	this->Memory_Deside_Destination=NULL;
	this->Memory_Destination=NULL;
	this->Q=initial_queue();
	strcpy(this->name,memory_name);
	Memory_Deside_Destination=Connect_Decide_MemoryIS(memory_name);
}


Get_Share_memory::~Get_Share_memory(void)
{
	CloseHandle(Memory_Deside_Destination);
	if(Memory_Destination!=NULL)
		Unlock();
}
HANDLE Get_Share_memory::Connect_Decide_MemoryIS(char* memory_name)
{
	HANDLE Memory_Deside_Destination = OpenFileMapping(
												FILE_MAP_ALL_ACCESS,   // read/write access
												FALSE,                 // do not inherit the name
												memory_name);               // name of mapping object
	return Memory_Deside_Destination;
}
LPCTSTR Get_Share_memory::LinkMemory(HANDLE Memory_Deside_Destination,int Size)
{
	LPCTSTR Memory_Destination=(LPTSTR)MapViewOfFile(Memory_Deside_Destination,   // handle to map object
													FILE_MAP_ALL_ACCESS,		 // read/write permission
													0,
													0,
													Size);
	return Memory_Destination;
}
int Get_Share_memory::Read(Queue **B)
{
	Memory_Destination=LinkMemory( Memory_Deside_Destination,size);
	if(Memory_Destination!=NULL)
	{

		Q=(Queue*)Memory_Destination;
		//D=Dequeue(&Q);
		*B=Q;
		//CopyMemory((PVOID)Memory_Destination,Q,sizeof(Data)*size);	///LENGTH YET
		/*   FLUSH AND FIND FRONT*/
		Unlock();
	}
	else
	{
		Unlock();
		return NO_MEMORY;
	}
	return 0;
}
void Get_Share_memory::Unlock()
{
	UnmapViewOfFile(Memory_Destination);
}
void  Get_Share_memory::get_handle()
{
	Memory_Deside_Destination=Connect_Decide_MemoryIS(name);
}