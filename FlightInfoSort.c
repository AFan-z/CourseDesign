#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include "Flight.h"


//ѡ����Ҫͨ������Ϣ���򺽰���Ϣ
void SortSelectOne(flightLists *info)
{
	int one = -1;
	char sort;
	puts("\t-------------------------");
	puts("\t|\t1.�����\t|");
	puts("\t-------------------------");
	puts("\t|\t2.Ʊ��\t\t|");
	puts("\t-------------------------");
	puts("\t|\t0.�˳�����\t|");
	puts("\t-------------------------");

	printf("��������ͨ������Ϣ���򺽰���Ϣ(0-2):");
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
			printf("��������ȷ����Ϣ�����򺽰���Ϣ(0-2):");
		}
	}
}


//ͨ������Ž���������������
void SortByFlightNum(flightLists *info)
{
	flightInfo temp;  //����
	char sort = 'A';  // ����(ASC)���߽���(DESC),Ĭ������

	printf("\n������ͨ������(ASC)���߽���(DESC)����,(A/D):");
	scanf("%c", &sort);
	scanf("%c", &sort);
	printf("\n");

	while (sort != 'A' && sort != 'a' && sort != '\n' && sort != 'D' && sort != 'd')
	{
		printf("��������ȷ�ַ�(A/D):");
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


//ͨ��Ʊ�۽���������������
void SortByPrice(flightLists *info)
{
	flightInfo temp;  //����
	char sort = 'A';  // ����(ASC)���߽���(DESC),Ĭ������

	printf("\n������ͨ������(ASC)���߽���(DESC)����,(A/D):");
	scanf("%c", &sort);
	scanf("%c", &sort);
	printf("\n");

	while (sort != 'A' && sort != 'a' && sort != '\n' && sort != 'D' && sort != 'd')
	{
		printf("��������ȷ�ַ�(A/D):");
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


//��ӡ�������Ϣ
void SortPrint(flightLists *info)
{
	char yOrn;

	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	puts("\t|   �����  |   ���վ	|   �յ�վ	|	 ���ʱ��	|	����ʱ��	|    ����	|    Ʊ��	|");
	puts("\t-------------------------------------------------------------------------------------------------------------------------");

	for (int i = 0; i < info->length; i++)
	{
		printf("\t|    %s  |\t %s   |    %s       |\t%s     |      %s      |    %s      |    %d      |\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
			info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);
		puts("\t-------------------------------------------------------------------------------------------------------------------------");
	}

	printf("\n�Ƿ��˳��������(y/n):");
	scanf("%c", &yOrn);
	scanf("%c", &yOrn);
	printf("\n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		SelectOptions(info);
	else
		SortSelectOne(info);
}