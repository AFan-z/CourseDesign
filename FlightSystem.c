#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>  //提供exit（）原型
#include "Flight.h"



void infoInput(flightLists *info)    //航班信息录入
{

	FILE *fp;

	//打开air.txt文件
	if ((fp = fopen("flight.txt", "w+")) == NULL) {
		fprintf(stdout, "错误，打不开\"flight.txt\"文件\n");
		exit(EXIT_FAILURE);       //退出
	}

	puts("请录入航班信息：");
	puts("分别输入:航班号(例:AB123)、起点站(例:广州)、终点站(例:北京)、起飞时间(例:10-10/12:12)\n"
		"到达时间(例:10-10/20:12)、机型(例:AC123)、票价(例:1234)(以空格分隔开每个数据,回车确认)\n");
	info->length = 0;
	char yOrn = 'y';
	fprintf(fp, "|   航班号  	|   起点站	|   终点站	|		 起飞时间		|		到达时间		|    机型	|    票价	|\n");
	for (int i = 0; i < MAX; i++)
	{
		if (yOrn == 'y' || yOrn == 'Y'|| yOrn == '\n')
		{
			//录入航班信息
			fscanf(stdin, "%s%s%s%s%s%s%d", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, &info->infos[i].price);  
			//将航班信息输出到文件
			fprintf(fp, "	%s			%s		 %s			%s			%s				 %s		%d\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);

			info->length++;   //记录航班数

		}else
			break;
		printf("\n");
		printf("是否继续需要录入航班信息(y/n):");
		scanf("%c", &yOrn);
		scanf("%c", &yOrn);
		printf("\n");
	}
	fclose(fp);
}





/*
题目11：航班信息的查询与检索
对飞机航班信息进行录入、排序和查找等操作，每个航班记录包括八项，分别是：航班号、起点站、终点站、起飞时间、到达时间、机型以及票价。
2．功能要求：
（1）录入：采用交互工作方式添加航班信息，建立数据文件；
（2）查询：可按航班的航班号、起点站、终点站、起飞时间以及到达时间等信息进行查询；
（3）排序：可按航班的航班号、票价进行排序；
（4）删除：根据航班号删除航班相关信息；
（5）修改：根据航班号修改航班相关信息。

*/

int main()
{
	flightLists *info;
	info = (flightLists *)malloc(sizeof(flightLists));

	infoInput(info);
	SearchSelectOne(info);

	free(info);
	system("pause");
	return(0);
}



