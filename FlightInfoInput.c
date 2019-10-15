#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>  //提供exit（）原型
#include "Flight.h"


//选择需要通过的信息录入航班信息
void InputSelectOne(flightLists* info)
{
	int one = -1;
	char input;
	printf("\n");
	puts("\t-------------------------");
	puts("\t|\t1.手动录入\t|");
	puts("\t-------------------------");
	puts("\t|\t2.文件导入\t|");
	puts("\t-------------------------");
	puts("\t|\t0.退出录入\t|");
	puts("\t-------------------------");

	printf("请输入想通过的信息录入航班信息(0-2):");
	while (one < 0 || one > 2)
	{
		scanf("%d", &one);

		switch (one)
		{
		case 0:
			SelectOptions(info);
			break;
		case 1:
			InputInfo(info);
			break;
		case 2:
			InfoInputByFlie(info);
			break;
		default:
			printf("请输入正确的信息来录入航班信息(0-2):");
		}
	}
}


//导入原有的数据文件信息
void InputByOld(flightLists* info)
{
	FILE* fp;


	int i = info->length;
	char ch;

	if ((fp = fopen("flightInfo.txt", "a+")) == NULL) {
		fprintf(stdout, "错误，打不开\"flightInfo.txt\"文件\n");
		exit(EXIT_FAILURE);       //退出
	}

	ch = fgetc(fp);                  //判断是否为空文件
	if (ch != EOF)					//如果为空重新打开文件流
	{
		fclose(fp);
		if ((fp = fopen("flightInfo.txt", "a+")) == NULL) {
			fprintf(stdout, "错误，打不开\"flightInfo.txt\"文件\n");
			exit(EXIT_FAILURE);       //退出
		}
	}
	
	while (ch !=EOF && !feof(fp))   //判断是否到达文件尾
	{
		fscanf(fp,"%s%s%s%s%s%s%d", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
			info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, &info->infos[i].price);
		i++;

		if (!feof(fp))
			info->length++;
	}
	if (fclose(fp) != 0)
		fprintf(stderr, "错误，关闭不了文件\n");
}


//航班信息录入
void InputInfo(flightLists* info)
{

	FILE* fp, * FInfo;

	//打开临时文件
	if ((fp = fopen("flightInput.txt", "w+")) == NULL) {
		fprintf(stdout, "错误，打不开\"flightInput.txt\"文件\n");
		exit(EXIT_FAILURE);       //退出
	}

	//打开文件
	if ((FInfo = fopen("flightInfo.txt", "a+")) == NULL) {
		fprintf(stdout, "错误，打不开\"flightInfo.txt\"文件\n");
		exit(EXIT_FAILURE);       //退出
	}

	puts("\n请录入航班信息：\n");

	char yOrn = 'y';
	//if (fgetc(fp) == EOF)       //如果信息为空则在文件打印表头
	//	fprintf(fp, "|   航班号  	|   起点站	|   终点站	|		 起飞时间		|		到达时间		|    机型	|    票价	|\n");
	for (int i = info->length; i < FLIGHT_INFO_MAX; i++)
	{
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		{
			//录入航班信息

			printf("请输入航班号(例:CA1302)：");
			scanf("%s", info->infos[i].FlightNum);
			printf("请输入起点站(例:广州)：");
			scanf("%s", info->infos[i].StartPoint);
			printf("请输入终点站(例:北京)：");
			scanf("%s", info->infos[i].EndPoint);
			printf("请输入起飞时间(例:201910161523)：");
			scanf("%s", info->infos[i].StartTime);
			printf("请输入到达时间(例:201910162320)：");
			scanf("%s", info->infos[i].EndTime);
			printf("请输入机型(例:777(大))：");
			scanf("%s", info->infos[i].PlaneType);
			printf("请输入票价(例:1234)：");
			scanf("%d", &info->infos[i].price);

			//将航班信息输出到临时文件
			fprintf(fp, "%s	%s	%s	%s	%s	%s	%d\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);
			//保存航班信息
			fprintf(FInfo, "%s	%s	%s	%s	%s	%s	%d\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);
			info->length++;   //记录航班数

		}
		else
		{
			SelectOptions(info);   //退回选择操作界面
			return;
		}

		printf("\n");
		printf("是否继续需要录入航班信息(y/n):");
		scanf("%c",&yOrn);
		scanf("%c",&yOrn);
		printf("\n");
	}


	if (fclose(fp) != 0 || fclose(FInfo) != 0)
		fprintf(stderr, "错误，关闭不了文件\n");

	printf("\n");
	printf("是否继续录入(y/n):");
	scanf("%c",&yOrn);
	printf("\n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		InputSelectOne(info);
	else
		SelectOptions(info);

}

//从文件中录入航班信息
void InfoInputByFlie(flightLists* info)
{
	FILE* fp, * FInfo;
	int i = info->length;
	char flieName[20];  //文件名
	char yOrn;

	printf("\n请输入要导入航班信息的文件名：");
	gets(flieName);
	gets(flieName);

	if ((fp = fopen(flieName,"r")) == NULL) {
		fprintf(stdout, "错误，打不开\"%s\"文件\n", flieName);
		exit(EXIT_FAILURE);       //退出
	}

	//打开文件
	if ((FInfo = fopen("flightInfo.txt", "a+")) == NULL) {
		fprintf(stdout, "错误，打不开\"flightInfo.txt\"文件\n");
		exit(EXIT_FAILURE);       //退出
	}


	while (!feof(fp))   //判断是否到达文件尾
	{

		fscanf(fp,"%s %s %s %s %s %s %d", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
			info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, &info->infos[i].price);

		//保存至文件
		fprintf(FInfo, "%s	%s	%s	%s	%s	%s	%d\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
			info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);
		i++;
		info->length++;
	}


	if (fclose(fp) != 0 || fclose(FInfo) != 0)
		fprintf(stderr, "错误，关闭不了文件\n");

	printf("\n");
	printf("是否继续录入(y/n):");
	scanf("%c",&yOrn);
	printf("\n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		InputSelectOne(info);
	else
		SelectOptions(info);

}


//打印航班信息
void InfoPrint(flightLists* info)
{
	puts("\n\n所有的航班信息为：");
	puts("\t------------------------------------------------------------------------------------------------------------------------");
	puts("\t|   航班号  |   起点站	|   终点站	|	 起飞时间	|	到达时间	|    机型	|    票价      |");
	puts("\t------------------------------------------------------------------------------------------------------------------------");
	for (int i = 0; i < info->length; i++)
	{
		printf("\t|   %s  |\t %s   |    %s       |\t%s    |      %s     |   %s     |    %d      |\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
			info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);
		puts("\t------------------------------------------------------------------------------------------------------------------------");
	}

	if (info->length == 0)
	{
		printf("\n\n");
		printf("\t\t\t---------------------------------------------------------\n");
		printf("\t\t\t|\t\t无航班信息，请先录入！！！\t\t|\n");
		printf("\t\t\t---------------------------------------------------------\n");
	}

	SelectOptions(info);

}


//修改或删除后保存至文件中
void InfoDelOrUpdate(flightLists* info)
{
	FILE* fp;


	if ((fp = fopen("flightInfo.txt", "w+")) == NULL) {
		fprintf(stdout, "错误，打不开\"flightInfo.txt\"文件\n");
		exit(EXIT_FAILURE);       //退出
	}


	for (int i = 0; i < info->length; i++)
	{
		fprintf(fp, "%s	%s	%s	%s	%s	%s	%d\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
			info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);
	}

	if (fclose(fp) != 0)
		fprintf(stderr, "错误，关闭不了文件\n");
}
