#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>  //提供exit（）原型
#define MAX 50


typedef struct
{                                   //航班信息
	char AirNum[10];                //航班号
	char StartPoint[10];			//起点站
	char EndPoint[10];				//终点站
	char StartTime[15];				//起飞时间
	char EndTime[15];				//到达时间
	char PlaneType[10];				//机型
	int price;						//票价
}airInfo;

typedef struct {                  
	airInfo infos[MAX];
	int length;					 //航班个数
}airLists;

void infoInput(airLists *info)
{

	FILE *fp;

	if ((fp = fopen("air.txt", "w+")) == NULL) {
		fprintf(stdout, "错误，打不开\"air.txt\"文件\n");
		exit(EXIT_FAILURE);       //退出
	}

	puts("请录入航班信息：");
	puts("分别输入:航班号、起点站、终点站、起飞时间、到达时间、机型、票价(以空格分隔开每个数据)");

	char yOrn = 'y';
	fprintf(fp, "|   航班号  	|   起点站	|   终点站	|		 起飞时间		|		到达时间		|    机型	|    票价	|\n");
	for (int i = 0; i < MAX; i++)
	{
		if (yOrn == 'y' || yOrn == 'Y'|| yOrn == '\n')
		{
			fscanf(stdin, "%s%s%s%s%s%s%d", info->infos[i].AirNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, &info->infos[i].price);
			fprintf(fp, "	%s			%s		 %s			%s			%s			 %s		%d\n", info->infos[i].AirNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);
			info->length++;


		}else
			break;

		printf("是否需要录入航班信息(y/n):");
		scanf("%c", &yOrn);
		scanf("%c", &yOrn);

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
	airLists *info;
	info = (airLists *)malloc(sizeof(airLists));

	infoInput(info);

	system("pause");
	return(0);
}



