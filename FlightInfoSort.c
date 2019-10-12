#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include "Flight.h"


//选择需要通过的信息排序航班信息
void SortSelectOne(flightLists *info)
{
	int one = -1;
	char sort;
	puts("\t-------------------------");
	puts("\t|\t1.航班号\t|");
	puts("\t-------------------------");
	puts("\t|\t2.票价\t\t|");
	puts("\t-------------------------");
	puts("\t|\t0.退出排序\t|");
	puts("\t-------------------------");

	printf("请输入想通过的信息排序航班信息(0-2):");
	while (one < 0 || one > 2)
	{
		scanf("%d", &one);

		switch (one)
		{
		case 0:
			SelectOptions(info);
			break;
		case 1:
			SortByFlightNum(info);
			break;
		case 2:
			SortByPrice(info);
			break;
		default:
			printf("请输入正确的信息来排序航班信息(0-2):");
		}
	}
}


//通过航班号进行升、降序排序
void SortByFlightNum(flightLists *info)
{
	flightInfo temp;  //交换
	char sort = 'A';  // 升序(ASC)或者降序(DESC),默认升序

	printf("\n请输入通过升序(ASC)或者降序(DESC)排序,(A/D):");
	scanf("%c", &sort);
	scanf("%c", &sort);
	printf("\n");

	while (sort != 'A' && sort != 'a' && sort != '\n' && sort != 'D' && sort != 'd')
	{
		printf("请输入正确字符(A/D):");
		scanf("%c", &sort);
	}
	if (sort == 'A' || sort == 'a' || sort == '\n')
	{
		for (int x = 0; x < info->length; x++)
		{
			for (int y = x + 1; y < info->length; y++)
			{
				if (strcmp(info->infos[x].FlightNum, info->infos[y].FlightNum) > 0)
				{
						temp = info->infos[x];
						info->infos[x] = info->infos[y];
						info->infos[y] = temp;
				}
			}
		}
	}
	else if(sort == 'D' || sort == 'd')
	{
		for (int x = 0; x < info->length; x++)
		{
			for (int y = x + 1; y < info->length; y++)
			{
				if (strcmp(info->infos[x].FlightNum, info->infos[y].FlightNum) < 0)
				{
					temp = info->infos[x];
					info->infos[x] = info->infos[y];
					info->infos[y] = temp;
				}
			}
		}
	}

	SortPrint(info);
}


//通过票价进行升、降序排序
void SortByPrice(flightLists *info)
{
	flightInfo temp;  //交换
	char sort = 'A';  // 升序(ASC)或者降序(DESC),默认升序

	printf("\n请输入通过升序(ASC)或者降序(DESC)排序,(A/D):");
	scanf("%c", &sort);
	scanf("%c", &sort);
	printf("\n");

	while (sort != 'A' && sort != 'a' && sort != '\n' && sort != 'D' && sort != 'd')
	{
		printf("请输入正确字符(A/D):");
		scanf("%c", &sort);
	}
	if (sort == 'A' || sort == 'a' || sort == '\n')
	{
		for (int x = 0; x < info->length; x++)
		{
			for (int y = x + 1; y < info->length; y++)
			{
				if (info->infos[x].price > info->infos[y].price)
				{
					temp = info->infos[x];
					info->infos[x] = info->infos[y];
					info->infos[y] = temp;
				}
			}
		}
	}
	else if (sort == 'D' || sort == 'd')
	{
		for (int x = 0; x < info->length; x++)
		{
			for (int y = x + 1; y < info->length; y++)
			{
				if (info->infos[x].price < info->infos[y].price)
				{
					temp = info->infos[x];
					info->infos[x] = info->infos[y];
					info->infos[y] = temp;
				}
			}
		}
	}

	SortPrint(info);
}


//打印排序后信息
void SortPrint(flightLists *info)
{
	char yOrn;

	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	puts("\t|   航班号  |   起点站	|   终点站	|	 起飞时间	|	到达时间	|    机型	|    票价	|");
	puts("\t-------------------------------------------------------------------------------------------------------------------------");

	for (int i = 0; i < info->length; i++)
	{
		printf("\t|    %s  |\t %s   |    %s       |\t%s     |      %s      |    %s      |    %d      |\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
			info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);
		puts("\t-------------------------------------------------------------------------------------------------------------------------");
	}

	printf("\n是否退出排序操作(y/n):");
	scanf("%c", &yOrn);
	scanf("%c", &yOrn);
	printf("\n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		SelectOptions(info);
	else
		SortSelectOne(info);
}