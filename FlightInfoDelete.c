#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include "Flight.h"


//选择需要通过的信息删除航班信息
void DeleteSelectOne(flightLists *info)
{
	int one = -1;
	char del;
	puts("\t-------------------------");
	puts("\t|\t1.航班号\t|");
	puts("\t-------------------------");
	puts("\t|\t2.机型\t\t|");
	puts("\t-------------------------");
	puts("\t|\t0.退出删除\t|");
	puts("\t-------------------------");

	printf("请输入想通过的信息删除航班信息(0-2):");
	while (one < 0 || one > 2)
	{
		scanf("%d", &one);

		switch (one)
		{
		case 0:
			SelectOptions(info);
			break;
		case 1:
			DeleteByFlightNum(info, one);
			break;
		case 2:
			DeleteByPlaneType(info, one);
			break;
		default:
			printf("请输入正确的信息来删除航班信息(0-2):");
		}
	}
}

//根据航班号删除航班相关信息
void DeleteByFlightNum(flightLists *info, int one)
{

	char flightNumOne[10];             //航班号

	printf("\n请输入所要删除的航班号：");
	gets(flightNumOne);
	gets(flightNumOne);
	DeleteOptions(info, flightNumOne, one);

}


//根据机型删除航班相关信息
void DeleteByPlaneType(flightLists *info, int one)
{

	char PlaneType[10];             //机型

	printf("\n请输入所要删除的航班号：");
	gets(PlaneType);
	gets(PlaneType);
	DeleteOptions(info, PlaneType, one);
}


//删除操作
void DeleteOptions(flightLists *info, char type[], int one)
{

	char yOrn;
	int length = info->length;

	if (one == 1)  //通过航班号删除操作
	{
		for (int i = 0; i < info->length; i++)
		{
			if (strcmp(info->infos[i].FlightNum, type) == 0)
			{
				for (int j = i; j < info->length - 1; j++)	//将info[i]之后的元素前移一个位置			
					info->infos[j] = info->infos[j + 1];
				info->length--;
			}
		}
	}
	else if(one == 2)   //通过机型删除操作
	{
		for (int i = 0; i < info->length; i++)
		{
			if (strcmp(info->infos[i].PlaneType, type) == 0)
			{
				for (int j = i; j < info->length - 1; j++)	//将info[i]之后的元素前移一个位置			
					info->infos[j] = info->infos[j + 1];
				info->length--;
			}
		}
	}

	if (length == info->length)   //判断所要删除的机型是否为空或者已删除
	{
		printf("\n\n");
		printf("\t\t\t-----------------------------------------------------------------\n");
		printf("\t\t\t|\t\t所删除的航班或机型\"%s\"为空！！！\t\t|\n", type);
		printf("\t\t\t-----------------------------------------------------------------\n");
		printf("是否继续删除(y/n):");
		scanf("%c", &yOrn);
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		{
			DeleteSelectOne(info);
			return;
		}
		else
		{
			SelectOptions(info);
			return;
		}
	}
	else
		printf("\n\n\"%s\"删除成功！！！\n", type);

	printf("\n");
	printf("是否继续删除(y/n):");
	scanf("%c", &yOrn);
	printf("\n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		DeleteSelectOne(info);
	else
		SelectOptions(info);
}