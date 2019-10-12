#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>  //提供exit（）原型
#include "Flight.h"



//航班信息录入
void InfoInput(flightLists *info)
{

	FILE *fp;

	//打开air.txt文件
	if ((fp = fopen("flight.txt", "w+")) == NULL) {
		fprintf(stdout, "错误，打不开\"flight.txt\"文件\n");
		exit(EXIT_FAILURE);       //退出
	}

	puts("\n请录入航班信息：\n");
	puts("分别输入:航班号(例:AB123)、起点站(例:广州)、终点站(例:北京)、起飞时间(例:10-10/12:12)\n"
		"到达时间(例:10-10/20:12)、机型(例:AC123)、票价(例:1234)(以空格分隔开每个数据,回车确认)\n");
	info->length = 0;
	char yOrn = 'y';
	if (fgetc(fp) == EOF)       //如果信息为空则在文件打印表头
		fprintf(fp, "|   航班号  	|   起点站	|   终点站	|		 起飞时间		|		到达时间		|    机型	|    票价	|\n");
	for (int i = info->length; i < MAX; i++)
	{
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		{
			//录入航班信息
			fscanf(stdin, "%s%s%s%s%s%s%d", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, &info->infos[i].price);
			//将航班信息输出到文件
			fprintf(fp, "	%s			%s		 %s			%s			%s				 %s		 %d\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);

			info->length++;   //记录航班数

		}else
			{
				SelectOptions(info);   //退回选择操作界面
				return;
			}

		printf("\n");
		printf("是否继续需要录入航班信息(y/n):");
		scanf("%c", &yOrn);
		scanf("%c", &yOrn);
		printf("\n");
	}
	fclose(fp);

}