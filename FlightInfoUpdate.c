#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include "Flight.h"


//选择需要通过的信息修改航班信息
void UpdateSelectOne(flightLists *info)
{
	int one = -1;
	char update;
	puts("\t-------------------------");
	puts("\t|\t1.航班号\t|");
	puts("\t-------------------------");
	puts("\t|\t2.机型\t\t|");
	puts("\t-------------------------");
	puts("\t|\t0.退出修改\t|");
	puts("\t-------------------------");

	printf("请输入想通过的信息修改航班信息(0-2):");
	while (one < 0 || one > 2)
	{
		scanf("%d", &one);

		switch (one)
		{
		case 0:
			SelectOptions(info);
			break;
		case 1:
			UpdateByFlightNum(info);
			break;
		case 2:
			UpdateByPlaneType(info);
			break;
		default:
			printf("请输入正确的信息来修改航班信息(0-2):");
		}
	}
}


//根据航班号修改航班相关信息
void UpdateByFlightNum(flightLists *info)
{
	char flightNumOne[10];             //航班号
	printf("\n请输入所要修改的航班号：");
	gets(flightNumOne);
	gets(flightNumOne);
	int num[MAX];
	int j = 0;
	for (int i = 0; i < info->length; i++)
	{
		if (strcmp(info->infos[i].FlightNum, flightNumOne) == 0)
		{
			num[j] = i;
			j++;
		}
	}

	int a = UpdateWhichOne(info, num, j);

	UpdateSelect(info, num, a);

}

//根据机型修改航班相关信息
void UpdateByPlaneType(flightLists *info)
{
	char PlaneType[10];				//机型
	printf("\n请输入所要修改的机型：");
	gets(PlaneType);
	gets(PlaneType);
	int num[MAX];
	int j = 0;
	for (int i = 0; i < info->length; i++)
	{
		if (strcmp(info->infos[i].PlaneType, PlaneType) == 0)
		{
			num[j] = i;
			j++;
		}
	}

	int a = UpdateWhichOne(info, num, j);

	UpdateSelect(info, num, a);

}

//确认所要修改的航班信息
int UpdateWhichOne(flightLists *info, int num[], int j)
{

	if (num != NULL)
	{
		puts("\t-------------------------------------------------------------------------------------------------------------------------");
		puts("\t|   航班号  |   起点站	|   终点站	|	 起飞时间	|	到达时间	|    机型	|    票价	|");
		puts("\t-------------------------------------------------------------------------------------------------------------------------");

		for (int i = 0; i < j; i++)
		{
			printf("\t|    %s  |\t %s   |    %s       |\t%s     |      %s      |    %s      |    %d      |\n", info->infos[num[i]].FlightNum, info->infos[num[i]].StartPoint, info->infos[num[i]].EndPoint,
				info->infos[num[i]].StartTime, info->infos[num[i]].EndTime, info->infos[num[i]].PlaneType, info->infos[num[i]].price);
			puts("\t-------------------------------------------------------------------------------------------------------------------------");
		}

		printf("请问需要修改哪一行的航班信息：");
		scanf("%d", &j);
	}

	return j;
}

//选择修改某一处的航班信息
void UpdateSelect(flightLists *info,int num[], int j)
{
	if (j != 0)
	{
		int one = -1;
		printf("\n");
		puts("\t-------------------------");
		puts("\t|\t1.航班号\t|");
		puts("\t-------------------------");
		puts("\t|\t2.起点站\t|");
		puts("\t-------------------------");
		puts("\t|\t3.终点站\t|");
		puts("\t-------------------------");
		puts("\t|\t4.起飞时间\t|");
		puts("\t-------------------------");
		puts("\t|\t5.到达时间\t|");
		puts("\t-------------------------");
		puts("\t|\t6.机型\t\t|");
		puts("\t-------------------------");
		puts("\t|\t7.票价\t\t|");
		puts("\t-------------------------");
		puts("\t|\t0.退出修改\t|");
		puts("\t-------------------------");

		printf("请问需要修改哪一处的航班信息(0-7)：");
		while (one < 0 || one > 7)
		{
			scanf("%d", &one);
			switch (one)
			{
			case 0:
				SelectOptions(info);
				break;
			case 1:
				UpdateFlightNum(info, one, num[j - 1], num, j);
				break;
			case 2:
				UpdateStartPoint(info, one, num[j - 1], num, j);
				break;
			case 3:
				UpdateEndPoint(info, one, num[j - 1], num, j);
				break;
			case 4:
				UpdateStartTime(info, one, num[j - 1], num, j);
				break;
			case 5:
				UpdateEndTime(info, one, num[j - 1], num, j);
				break;
			case 6:
				UpdatePlaneType(info, one, num[j - 1], num, j);
				break;
			case 7:
				UpdatePrice(info, one, num[j - 1], num, j);
				break;
			default:
				printf("请输入正确的信息来修改航班信息(0-7):");
			}
		}
	}
}

//修改航班号
void UpdateFlightNum(flightLists *info, int one,int whichOne, int num[], int j)
{
	if (one == 1)
	{
		printf("\n请输入新航班号：");
		gets(info->infos[whichOne].FlightNum);
		gets(info->infos[whichOne].FlightNum);
		printf("\n\n\t修改成功!\n\n");
		char yOrn;
		printf("是否再修改航班信息(y/n):");
		scanf("%c", &yOrn);
		printf("\n");
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
			UpdateSelect(info, num, j);
	}

}

//修改起点站
void UpdateStartPoint(flightLists *info, int one, int whichOne, int num[], int j)
{
	if (one == 2)
	{
		printf("\n请输入新起点站：");
		gets(info->infos[whichOne].StartPoint);
		gets(info->infos[whichOne].StartPoint);
		printf("\n\n\t修改成功!\n");
		char yOrn;
		printf("是否再修改航班信息(y/n):");
		scanf("%c", &yOrn);
		printf("\n");
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
			UpdateSelect(info, num, j);
	}

}

//修改终点站
void UpdateEndPoint(flightLists *info, int one, int whichOne, int num[], int j)
{
	if (one == 3)
	{
		printf("\n请输入新终点站：");
		gets(info->infos[whichOne].EndPoint);
		gets(info->infos[whichOne].EndPoint);
		printf("\n\n\t修改成功!\n\n");
		char yOrn;
		printf("是否再修改航班信息(y/n):");
		scanf("%c", &yOrn);
		printf("\n");
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
			UpdateSelect(info, num, j);
	}

}

//修改起飞时间
void UpdateStartTime(flightLists *info, int one, int whichOne, int num[], int j)
{
	if (one == 4)
	{
		printf("\n请输入新起飞时间：");
		gets(info->infos[whichOne].StartTime);
		gets(info->infos[whichOne].StartTime);
		printf("\n\n\t修改成功!\n\n");
		char yOrn;
		printf("是否再修改航班信息(y/n):");
		scanf("%c", &yOrn);
		printf("\n");
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
			UpdateSelect(info, num, j);

	}

}

//修改到达时间
void UpdateEndTime(flightLists *info, int one, int whichOne, int num[], int j)
{
	if (one == 5)
	{
		printf("\n请输入新到达时间：");
		gets(info->infos[whichOne].EndTime);
		gets(info->infos[whichOne].EndTime);
		printf("\n\n\t修改成功!\n\n");
		char yOrn;
		printf("是否再修改航班信息(y/n):");
		scanf("%c", &yOrn);
		printf("\n");
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
			UpdateSelect(info, num, j);
	}

}

//修改机型
void UpdatePlaneType(flightLists *info, int one, int whichOne, int num[], int j)
{
	if (one == 6)
	{
		printf("\n请输入新机型：");
		gets(info->infos[whichOne].PlaneType);
		gets(info->infos[whichOne].PlaneType);
		printf("\n\n\t修改成功!\n\n");
		char yOrn;
		printf("是否再修改航班信息(y/n):");
		scanf("%c", &yOrn);
		printf("\n");
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
			UpdateSelect(info, num, j);
	}

}

//修改票价
void UpdatePrice(flightLists *info, int one, int whichOne, int num[], int j)
{
	if (one == 7)
	{
		printf("\n请输入新票价：");
		scanf("%d", &info->infos[whichOne].price);
		printf("\n\n\t修改成功!\n\n");
		char yOrn;
		printf("是否再修改航班信息(y/n):");
		scanf("%c", &yOrn);
		printf("\n");
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
			UpdateSelect(info, num, j);
	}

}