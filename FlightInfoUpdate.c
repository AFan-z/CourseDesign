#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include "Flight.h"


//ѡ����Ҫͨ������Ϣ�޸ĺ�����Ϣ
void UpdateSelectOne(flightLists *info)
{
	int one = -1;
	char update;
	puts("\t-------------------------");
	puts("\t|\t1.�����\t|");
	puts("\t-------------------------");
	puts("\t|\t2.����\t\t|");
	puts("\t-------------------------");
	puts("\t|\t0.�˳��޸�\t|");
	puts("\t-------------------------");

	printf("��������ͨ������Ϣ�޸ĺ�����Ϣ(0-2):");
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
			printf("��������ȷ����Ϣ���޸ĺ�����Ϣ(0-2):");
		}
	}
}


//���ݺ�����޸ĺ��������Ϣ
void UpdateByFlightNum(flightLists *info)
{
	char flightNumOne[10];             //�����
	printf("\n��������Ҫ�޸ĵĺ���ţ�");
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

//���ݻ����޸ĺ��������Ϣ
void UpdateByPlaneType(flightLists *info)
{
	char PlaneType[10];				//����
	printf("\n��������Ҫ�޸ĵĻ��ͣ�");
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

//ȷ����Ҫ�޸ĵĺ�����Ϣ
int UpdateWhichOne(flightLists *info, int num[], int j)
{

	if (num != NULL)
	{
		puts("\t-------------------------------------------------------------------------------------------------------------------------");
		puts("\t|   �����  |   ���վ	|   �յ�վ	|	 ���ʱ��	|	����ʱ��	|    ����	|    Ʊ��	|");
		puts("\t-------------------------------------------------------------------------------------------------------------------------");

		for (int i = 0; i < j; i++)
		{
			printf("\t|    %s  |\t %s   |    %s       |\t%s     |      %s      |    %s      |    %d      |\n", info->infos[num[i]].FlightNum, info->infos[num[i]].StartPoint, info->infos[num[i]].EndPoint,
				info->infos[num[i]].StartTime, info->infos[num[i]].EndTime, info->infos[num[i]].PlaneType, info->infos[num[i]].price);
			puts("\t-------------------------------------------------------------------------------------------------------------------------");
		}

		printf("������Ҫ�޸���һ�еĺ�����Ϣ��");
		scanf("%d", &j);
	}

	return j;
}

//ѡ���޸�ĳһ���ĺ�����Ϣ
void UpdateSelect(flightLists *info,int num[], int j)
{
	if (j != 0)
	{
		int one = -1;
		printf("\n");
		puts("\t-------------------------");
		puts("\t|\t1.�����\t|");
		puts("\t-------------------------");
		puts("\t|\t2.���վ\t|");
		puts("\t-------------------------");
		puts("\t|\t3.�յ�վ\t|");
		puts("\t-------------------------");
		puts("\t|\t4.���ʱ��\t|");
		puts("\t-------------------------");
		puts("\t|\t5.����ʱ��\t|");
		puts("\t-------------------------");
		puts("\t|\t6.����\t\t|");
		puts("\t-------------------------");
		puts("\t|\t7.Ʊ��\t\t|");
		puts("\t-------------------------");
		puts("\t|\t0.�˳��޸�\t|");
		puts("\t-------------------------");

		printf("������Ҫ�޸���һ���ĺ�����Ϣ(0-7)��");
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
				printf("��������ȷ����Ϣ���޸ĺ�����Ϣ(0-7):");
			}
		}
	}
}

//�޸ĺ����
void UpdateFlightNum(flightLists *info, int one,int whichOne, int num[], int j)
{
	if (one == 1)
	{
		printf("\n�������º���ţ�");
		gets(info->infos[whichOne].FlightNum);
		gets(info->infos[whichOne].FlightNum);
		printf("\n\n\t�޸ĳɹ�!\n\n");
		char yOrn;
		printf("�Ƿ����޸ĺ�����Ϣ(y/n):");
		scanf("%c", &yOrn);
		printf("\n");
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
			UpdateSelect(info, num, j);
	}

}

//�޸����վ
void UpdateStartPoint(flightLists *info, int one, int whichOne, int num[], int j)
{
	if (one == 2)
	{
		printf("\n�����������վ��");
		gets(info->infos[whichOne].StartPoint);
		gets(info->infos[whichOne].StartPoint);
		printf("\n\n\t�޸ĳɹ�!\n");
		char yOrn;
		printf("�Ƿ����޸ĺ�����Ϣ(y/n):");
		scanf("%c", &yOrn);
		printf("\n");
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
			UpdateSelect(info, num, j);
	}

}

//�޸��յ�վ
void UpdateEndPoint(flightLists *info, int one, int whichOne, int num[], int j)
{
	if (one == 3)
	{
		printf("\n���������յ�վ��");
		gets(info->infos[whichOne].EndPoint);
		gets(info->infos[whichOne].EndPoint);
		printf("\n\n\t�޸ĳɹ�!\n\n");
		char yOrn;
		printf("�Ƿ����޸ĺ�����Ϣ(y/n):");
		scanf("%c", &yOrn);
		printf("\n");
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
			UpdateSelect(info, num, j);
	}

}

//�޸����ʱ��
void UpdateStartTime(flightLists *info, int one, int whichOne, int num[], int j)
{
	if (one == 4)
	{
		printf("\n�����������ʱ�䣺");
		gets(info->infos[whichOne].StartTime);
		gets(info->infos[whichOne].StartTime);
		printf("\n\n\t�޸ĳɹ�!\n\n");
		char yOrn;
		printf("�Ƿ����޸ĺ�����Ϣ(y/n):");
		scanf("%c", &yOrn);
		printf("\n");
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
			UpdateSelect(info, num, j);

	}

}

//�޸ĵ���ʱ��
void UpdateEndTime(flightLists *info, int one, int whichOne, int num[], int j)
{
	if (one == 5)
	{
		printf("\n�������µ���ʱ�䣺");
		gets(info->infos[whichOne].EndTime);
		gets(info->infos[whichOne].EndTime);
		printf("\n\n\t�޸ĳɹ�!\n\n");
		char yOrn;
		printf("�Ƿ����޸ĺ�����Ϣ(y/n):");
		scanf("%c", &yOrn);
		printf("\n");
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
			UpdateSelect(info, num, j);
	}

}

//�޸Ļ���
void UpdatePlaneType(flightLists *info, int one, int whichOne, int num[], int j)
{
	if (one == 6)
	{
		printf("\n�������»��ͣ�");
		gets(info->infos[whichOne].PlaneType);
		gets(info->infos[whichOne].PlaneType);
		printf("\n\n\t�޸ĳɹ�!\n\n");
		char yOrn;
		printf("�Ƿ����޸ĺ�����Ϣ(y/n):");
		scanf("%c", &yOrn);
		printf("\n");
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
			UpdateSelect(info, num, j);
	}

}

//�޸�Ʊ��
void UpdatePrice(flightLists *info, int one, int whichOne, int num[], int j)
{
	if (one == 7)
	{
		printf("\n��������Ʊ�ۣ�");
		scanf("%d", &info->infos[whichOne].price);
		printf("\n\n\t�޸ĳɹ�!\n\n");
		char yOrn;
		printf("�Ƿ����޸ĺ�����Ϣ(y/n):");
		scanf("%c", &yOrn);
		printf("\n");
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
			UpdateSelect(info, num, j);
	}

}