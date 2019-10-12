#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>  
#include "Flight.h"


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


//选择操作
void SelectOptions(flightLists *info)
{
		int one = -1;
		printf("\n");
		puts("\t---------------------------------");
		puts("\t|\t1.录入航班信息\t\t|");
		puts("\t---------------------------------");
		puts("\t|\t2.查询航班信息\t\t|");
		puts("\t---------------------------------");
		puts("\t|\t3.排序航班信息\t\t|");
		puts("\t---------------------------------");
		puts("\t|\t4.删除航班信息\t\t|");
		puts("\t---------------------------------");
		puts("\t|\t5.修改航班信息\t\t|");
		puts("\t---------------------------------");
		puts("\t|\t0.退出程序    \t\t|");
		puts("\t---------------------------------");

		printf("请问需要选择的操作(0-5)：");
		while (one < 0 || one > 5)
		{
			scanf("%d", &one);
			switch (one)
			{
			case 0:
				break;
			case 1:
				InfoInput(info);
				break;
			case 2:
				SearchSelectOne(info);
				break;
			case 3:
				SortSelectOne(info);
				break;
			case 4:
				DeleteSelectOne(info);
				break;
			case 5:
				UpdateSelectOne(info);
				break;
			default:
				printf("请输入正确的信息来选择操作(0-5):");
			}
		}
		printf("\n");
}


int main(void)
{
	flightLists *info;
	info = (flightLists *)malloc(sizeof(flightLists));

	SelectOptions(info);  //选择操作

	//InfoInput(info);
	//SearchSelectOne(info);
	//SortSelectOne(info);
	//DeleteByFlightNum(info);
	//UpdateByFlightNum(info);

	free(info);
	system("pause");
	return(0);
}