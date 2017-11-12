#include"Share_memory.h"
#include<stdio.h>
#include<time.h>
#define Random 1
#define Send_Rate 0	//ms


void main()
{
	int a=0;
	Share_memory SM("//GlobalA",1024);
#if Random==1
	int i=0;
	srand(time(NULL));
	while(1)
	{
		char s[300]={'\0'};
		int num=rand()%100;
		sprintf(s," %d",num);
		int error=SM.Write(s);
		if(error== BIG_SIZE)
			printf("BIG_SIZE");
		else if(error== NO_MEMORY)
			printf("NO_MEMORY");
		else if(error== UN_LOAD)
			printf("UN_LOAD");
		else
		{
			printf("Sent:\t%d\n",num);
			i++;
			continue;
		}
		printf("\r");
		Sleep(Send_Rate);
	}
#elif Random==0
	for(int i=0;;i++)
	{
		char s[300]={'\0'};
		sprintf(s," %d",a);
		int error=SM.Write(s);
		if(error== MEM_LOCK)
			continue;
		else if(error== BIG_SIZE)
			printf("BIG_SIZE");
		else if(error== NO_MEMORY)
			printf("NO_MEMORY");
		else if(error== UN_LOAD)
			printf("UN_LOAD");
		else
		{
			printf("Sent:\t%d\n",a);
			a++;
			continue;
		}
		printf("\r");
		Sleep(Send_Rate);
	}
#endif
	system("pause");
}