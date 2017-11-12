#include"Get_Share_memory.h"
#include<stdio.h>
#include<windows.h>
#include<stdarg.h>
#define RECIEVE_Rate 3000
typedef Get_Share_memory* CameraIS; 
void Manager(int num,...);
int Detection(Get_Share_memory **G);
void main()
{
	
	Get_Share_memory *GHM1=new Get_Share_memory("//GlobalA",1024);
	//Get_Share_memory *GHM2=new Get_Share_memory("//GlobalB",1024);
	while(1){Manager(1,GHM1);}
	system("pause");
}
void Manager(int num,...)
{
	static int i=0;
	va_list L;
	va_start(L,num);
	printf("%d:",++i);
	for(int j=0;j<num;j++)
	{
		int AA;
		Get_Share_memory *G=va_arg(L,CameraIS);
		do{
			AA=Detection(&G);
		}while(AA);
	}
	printf("\n");
	va_end(L);
	Sleep(RECIEVE_Rate);
}
int Detection(Get_Share_memory **G)
{
	Get_Share_memory *GHM=*G;
	Queue *Q;
	int error=GHM->Read(&Q);
		if(error==NOT_CHANGE)
		{
			if(Q!=NULL)
			{
				Data *S=Q->front;
				while(S!=NULL)
				{
					printf(" %d\n",S->hour);
					S=S->next;
				}
			}
			printf("\n--------------------------------\n");
		}
		else if(error==NO_MEMORY)
		{
			//printf("NO_MEMORY\n");
			GHM->get_handle();
		}
		return error;
}