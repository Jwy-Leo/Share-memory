#include "Share_memory.h"
/*--------NEED---------*/
/*Check the condition 1.null 2.copy*/
/*enqueue              */
/*---------------------*/

Share_memory::Share_memory(char* memory_name,int Size)
{
	this->Memory_Deside_Destination=Create_momory(memory_name,size);
	strcpy(this->name,memory_name);
	this->size=Size;
}


Share_memory::~Share_memory(void)
{
	CloseHandle(Memory_Deside_Destination);
}
HANDLE Share_memory::Create_momory(char* memory_name,int Size)
{
	HANDLE Memory_Deside_Destination=CreateFileMapping( 
		INVALID_HANDLE_VALUE,    // use paging file
		NULL,                    // default security
		PAGE_READWRITE,          // read/write access
		0,                       // maximum object size (high-order DWORD)
		Size,					// maximum object size (low-order DWORD)
		memory_name);
	return Memory_Deside_Destination;
}
LPCTSTR Share_memory::LinkMemory(HANDLE Memory_Deside_Destination,int Size)
{
	LPCTSTR Memory_Destination=(LPTSTR)MapViewOfFile(Memory_Deside_Destination,   // handle to map object
													FILE_MAP_ALL_ACCESS,		 // read/write permission
													0,
													0,
													Size);
	return Memory_Destination;
}
void Share_memory::Write_data(LPCTSTR destination,char* data)
{
	CopyMemory((PVOID)destination,data,sizeof(char)*size);
}
int Share_memory::Write(char* data)
{
	if(size<strlen(data))
		return BIG_SIZE;
	else
	{
		Memory_Destination=LinkMemory(Memory_Deside_Destination,size);
		if (Memory_Destination==NULL)
				return NO_MEMORY;
		else
		{
			char s[1024];
			strcpy(s,Memory_Destination);
			if(!strcmp(s,"")||s==NULL)
			{
				Write_data(this->Memory_Destination,data);
				Unlock();
			}
			else
			{
				Unlock();
				return UN_LOAD;
			}
		}
		return 0;
	}
}
void Share_memory::Unlock()
{
	UnmapViewOfFile(Memory_Destination);
}
char* Share_memory::WhoIsShareMem()
{
	return name;
}
