#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include "Flight.h"


//ѡ����Ҫͨ������Ϣɾ��������Ϣ
void DeleteSelectOne(flightLists *info)
{
	int one = -1;
	char del;
	puts("\t-------------------------");
	puts("\t|\t1.�����\t|");
	puts("\t-------------------------");
	puts("\t|\t2.����\t\t|");
	puts("\t-------------------------");
	puts("\t|\t0.�˳�ɾ��\t|");
	puts("\t-------------------------");

	printf("��������ͨ������Ϣɾ��������Ϣ(0-2):");
	while (one < 0 || one > 2)
	{
		scanf("%d", &one);

		switch (one)
		{
		case 0:
			SelectOptions(info);
			break;
		case 1:
			DeleteByFlightNum(info, one);
			break;
		case 2:
			DeleteByPlaneType(info, one);
			break;
		default:
			printf("��������ȷ����Ϣ��ɾ��������Ϣ(0-2):");
		}
	}
}

//���ݺ����ɾ�����������Ϣ
void DeleteByFlightNum(flightLists *info, int one)
{

	char flightNumOne[10];             //�����

	printf("\n��������Ҫɾ���ĺ���ţ�");
	gets(flightNumOne);
	gets(flightNumOne);
	DeleteOptions(info, flightNumOne, one);

}


//���ݻ���ɾ�����������Ϣ
void DeleteByPlaneType(flightLists *info, int one)
{

	char PlaneType[10];             //����

	printf("\n��������Ҫɾ���ĺ���ţ�");
	gets(PlaneType);
	gets(PlaneType);
	DeleteOptions(info, PlaneType, one);
}


//ɾ������
void DeleteOptions(flightLists *info, char type[], int one)
{

	char yOrn;
	int length = info->length;

	if (one == 1)  //ͨ�������ɾ������
	{
		for (int i = 0; i < info->length; i++)
		{
			if (strcmp(info->infos[i].FlightNum, type) == 0)
			{
				for (int j = i; j < info->length - 1; j++)	//��info[i]֮���Ԫ��ǰ��һ��λ��			
					info->infos[j] = info->infos[j + 1];
				info->length--;
			}
		}
	}
	else if(one == 2)   //ͨ������ɾ������
	{
		for (int i = 0; i < info->length; i++)
		{
			if (strcmp(info->infos[i].PlaneType, type) == 0)
			{
				for (int j = i; j < info->length - 1; j++)	//��info[i]֮���Ԫ��ǰ��һ��λ��			
					info->infos[j] = info->infos[j + 1];
				info->length--;
			}
		}
	}

	if (length == info->length)   //�ж���Ҫɾ���Ļ����Ƿ�Ϊ�ջ�����ɾ��
	{
		printf("\n\n");
		printf("\t\t\t-----------------------------------------------------------------\n");
		printf("\t\t\t|\t\t��ɾ���ĺ�������\"%s\"Ϊ�գ�����\t\t|\n", type);
		printf("\t\t\t-----------------------------------------------------------------\n");
		printf("�Ƿ����ɾ��(y/n):");
		scanf("%c", &yOrn);
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		{
			DeleteSelectOne(info);
			return;
		}
		else
		{
			SelectOptions(info);
			return;
		}
	}
	else
		printf("\n\n\"%s\"ɾ���ɹ�������\n", type);

	printf("\n");
	printf("�Ƿ����ɾ��(y/n):");
	scanf("%c", &yOrn);
	printf("\n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		DeleteSelectOne(info);
	else
		SelectOptions(info);
}