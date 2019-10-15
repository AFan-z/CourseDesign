#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include "Flight.h"

//查询：可按航班的航班号、起点站、终点站、起飞时间以及到达时间等信息进行查询；


//选择需要通过的信息查询航班信息
void SearchSelectOne(flightLists* info)
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
	puts("\t|\t0.退出查询\t|");
	puts("\t-------------------------");

	printf("请输入想通过的信息查询航班信息(0-6):");
	while (one < 0 || one > 6)
	{
		scanf("%d", &one);
		switch (one)
		{
		case 0:
			SelectOptions(info);
			break;
		case 1:
			searchByFlightNum(info);
			break;
		case 2:
			searchByStartPoint(info);
			break;
		case 3:
			searchByEndPoint(info);
			break;
		case 4:
			searchByStartTime(info);
			break;
		case 5:
			searchByEndTime(info);
			break;
		case 6:
			searchByPlaneType(info);
			break;
		default:
			printf("请输入正确的信息来查询航班信息(0-6):");
		}
	}
}


//通过航班号查询
void searchByFlightNum(flightLists* info)
{
	char flightNumOne[10];             //航班号
	int judge = 0;                     //判断是否查询到信息

	printf("\n请输入所要查询的航班号：");
	gets(flightNumOne);
	gets(flightNumOne);
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	puts("\t|   航班号  |   起点站	|   终点站	|	 起飞时间	|	到达时间	|    机型	|    票价       |");
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	char yOrn = 'y';
	for (int i = 0; i < info->length; i++)
	{
		if (strcmp(info->infos[i].FlightNum, flightNumOne) == 0)   //如果所查询的航班号存在则打印出来
		{
			printf("\t|   %s  |\t %s   |    %s       |\t%s    |      %s     |   %s     |    %d       |\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);
			puts("\t-------------------------------------------------------------------------------------------------------------------------");
			judge++;
		}
	}

	if (judge == 0)
	{
		printf("\n\n");
		printf("\t\t\t---------------------------------------------------------\n");
		printf("\t\t\t|\t\t所查询的航班号\"%s\"为空！！！\t\t|\n", flightNumOne);
		printf("\t\t\t---------------------------------------------------------\n");
		printf("是否继续查询(y/n):");
		scanf("%c", &yOrn);
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		{
			SearchSelectOne(info);
			return;
		}
		else
		{
			SelectOptions(info);
			return;
		}
	}

	printf("\n是否退出查询操作(y/n):");
	scanf("%c", &yOrn);
	printf("\n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		SelectOptions(info);
	else
		SearchSelectOne(info);
}

//通过起点站查询
void searchByStartPoint(flightLists* info)
{
	char StartPoint[10];			//起点站
	int judge = 0;                     //判断是否查询到信息

	printf("\n请输入所要查询的起点站：");
	gets(StartPoint);
	gets(StartPoint);
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	puts("\t|   航班号  |   起点站	|   终点站	|	 起飞时间	|	到达时间	|    机型	|    票价       |");
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	char yOrn = 'y';
	for (int i = 0; i < info->length; i++)
	{
		if (strcmp(info->infos[i].StartPoint, StartPoint) == 0)   //如果所查询的起点站存在则打印出来
		{
			printf("\t|   %s  |\t %s   |    %s       |\t%s    |      %s     |   %s     |    %d       |\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);
			puts("\t-------------------------------------------------------------------------------------------------------------------------");
			judge++;
		}
	}

	if (judge == 0)
	{
		printf("\n\n");
		printf("\t\t\t---------------------------------------------------------\n");
		printf("\t\t\t|\t\t所查询的航班号\"%s\"为空！！！\t\t|\n", StartPoint);
		printf("\t\t\t---------------------------------------------------------\n");
		printf("是否继续查询(y/n):");
		scanf("%c", &yOrn);
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		{
			SearchSelectOne(info);
			return;
		}
		else
		{
			SelectOptions(info);
			return;
		}
	}

	printf("是否退出查询操作(y/n):");
	scanf("%c", &yOrn);
	printf("/n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		SelectOptions(info);
	else
		SearchSelectOne(info);
}

//通过终点站查询
void searchByEndPoint(flightLists* info)
{
	char EndPoint[10];				//终点站
	int judge = 0;                     //判断是否查询到信息

	printf("\n请输入所要查询的终点站：");
	gets(EndPoint);
	gets(EndPoint);
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	puts("\t|   航班号  |   起点站	|   终点站	|	 起飞时间	|	到达时间	|    机型	|    票价       |");
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	char yOrn = 'y';
	for (int i = 0; i < info->length; i++)
	{
		if (strcmp(info->infos[i].EndPoint, EndPoint) == 0)   //如果所查询的终点站存在则打印出来
		{
			printf("\t|   %s  |\t %s   |    %s       |\t%s    |      %s     |   %s     |    %d       |\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);
			puts("\t-------------------------------------------------------------------------------------------------------------------------");
			judge++;
		}

	}

	if (judge == 0)
	{
		printf("\n\n");
		printf("\t\t\t---------------------------------------------------------\n");
		printf("\t\t\t|\t\t所查询的航班号\"%s\"为空！！！\t\t|\n", EndPoint);
		printf("\t\t\t---------------------------------------------------------\n");
		printf("是否继续查询(y/n):");
		scanf("%c", &yOrn);
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		{
			SearchSelectOne(info);
			return;
		}
		else
		{
			SelectOptions(info);
			return;
		}
	}

	printf("是否退出查询操作(y/n):");
	scanf("%c", &yOrn);
	printf("/n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		SelectOptions(info);
	else
		SearchSelectOne(info);
}



//通过起飞时间查询
void searchByStartTime(flightLists* info)
{
	char StartTime[15];				//起飞时间
	int judge = 0;                     //判断是否查询到信息

	printf("\n请输入所要查询的起飞时间：");
	gets(StartTime);
	gets(StartTime);
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	puts("\t|   航班号  |   起点站	|   终点站	|	 起飞时间	|	到达时间	|    机型	|    票价       |");
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	char yOrn = 'y';
	for (int i = 0; i < info->length; i++)
	{
		if (strcmp(info->infos[i].StartTime, StartTime) == 0)   //如果所查询的起飞时间存在则打印出来
		{
			printf("\t|   %s  |\t %s   |    %s       |\t%s    |      %s     |   %s     |    %d       |\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);
			puts("\t-------------------------------------------------------------------------------------------------------------------------");
			judge++;
		}

	}

	if (judge == 0)
	{
		printf("\n\n");
		printf("\t\t\t---------------------------------------------------------\n");
		printf("\t\t\t|\t\t所查询的航班号\"%s\"为空！！！\t\t|\n", StartTime);
		printf("\t\t\t---------------------------------------------------------\n");
		printf("是否继续查询(y/n):");
		scanf("%c", &yOrn);
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		{
			SearchSelectOne(info);
			return;
		}
		else
		{
			SelectOptions(info);
			return;
		}
	}

	printf("是否退出查询操作(y/n):");
	scanf("%c", &yOrn);
	printf("/n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		SelectOptions(info);
	else
		SearchSelectOne(info);
}

//通过到达时间查询
void searchByEndTime(flightLists* info)
{
	char EndTime[15];				//到达时间
	int judge = 0;                     //判断是否查询到信息

	printf("\n请输入所要查询的到达时间：");
	gets(EndTime);
	gets(EndTime);
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	puts("\t|   航班号  |   起点站	|   终点站	|	 起飞时间	|	到达时间	|    机型	|    票价       |");
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	char yOrn = 'y';
	for (int i = 0; i < info->length; i++)
	{
		if (strcmp(info->infos[i].EndTime, EndTime) == 0)   //如果所查询的到达时间存在则打印出来
		{
			printf("\t|   %s  |\t %s   |    %s       |\t%s    |      %s     |   %s     |    %d       |\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);
			puts("\t-------------------------------------------------------------------------------------------------------------------------");
			judge++;
		}

	}

	if (judge == 0)
	{
		printf("\n\n");
		printf("\t\t\t---------------------------------------------------------\n");
		printf("\t\t\t|\t\t所查询的航班号\"%s\"为空！！！\t\t|\n", EndTime);
		printf("\t\t\t---------------------------------------------------------\n");
		printf("是否继续查询(y/n):");
		scanf("%c", &yOrn);
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		{
			SearchSelectOne(info);
			return;
		}
		else
		{
			SelectOptions(info);
			return;
		}
	}

	printf("是否退出查询操作(y/n):");
	scanf("%c", &yOrn);
	printf("/n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		SelectOptions(info);
	else
		SearchSelectOne(info);
}

//通过机型查询
void searchByPlaneType(flightLists* info)
{
	char PlaneType[10];				//机型
	int judge = 0;                     //判断是否查询到信息

	printf("\n请输入所要查询的机型：");
	gets(PlaneType);
	gets(PlaneType);
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	puts("\t|   航班号  |   起点站	|   终点站	|	 起飞时间	|	到达时间	|    机型	|    票价       |");
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	char yOrn = 'y';
	for (int i = 0; i < info->length; i++)
	{
		if (strcmp(info->infos[i].PlaneType, PlaneType) == 0)   //如果所查询的机型存在则打印出来
		{
			printf("\t|   %s  |\t %s   |    %s       |\t%s    |      %s     |   %s     |    %d       |\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);
			puts("\t-------------------------------------------------------------------------------------------------------------------------");
			judge++;
		}

	}

	if (judge == 0)
	{
		printf("\n\n");
		printf("\t\t\t---------------------------------------------------------\n");
		printf("\t\t\t|\t\t所查询的航班号\"%s\"为空！！！\t\t|\n", PlaneType);
		printf("\t\t\t---------------------------------------------------------\n");
		printf("是否继续查询(y/n):");
		scanf("%c", &yOrn);
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		{
			SearchSelectOne(info);
			return;
		}
		else
		{
			SelectOptions(info);
			return;
		}
	}

	printf("是否退出查询操作(y/n):");
	scanf("%c", &yOrn);
	printf("/n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		SelectOptions(info);
	else
		SearchSelectOne(info);
}