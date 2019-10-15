#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include "Flight.h"

//��ѯ���ɰ�����ĺ���š����վ���յ�վ�����ʱ���Լ�����ʱ�����Ϣ���в�ѯ��


//ѡ����Ҫͨ������Ϣ��ѯ������Ϣ
void SearchSelectOne(flightLists* info)
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
	puts("\t|\t0.�˳���ѯ\t|");
	puts("\t-------------------------");

	printf("��������ͨ������Ϣ��ѯ������Ϣ(0-6):");
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
			printf("��������ȷ����Ϣ����ѯ������Ϣ(0-6):");
		}
	}
}


//ͨ������Ų�ѯ
void searchByFlightNum(flightLists* info)
{
	char flightNumOne[10];             //�����
	int judge = 0;                     //�ж��Ƿ��ѯ����Ϣ

	printf("\n��������Ҫ��ѯ�ĺ���ţ�");
	gets(flightNumOne);
	gets(flightNumOne);
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	puts("\t|   �����  |   ���վ	|   �յ�վ	|	 ���ʱ��	|	����ʱ��	|    ����	|    Ʊ��       |");
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	char yOrn = 'y';
	for (int i = 0; i < info->length; i++)
	{
		if (strcmp(info->infos[i].FlightNum, flightNumOne) == 0)   //�������ѯ�ĺ���Ŵ������ӡ����
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
		printf("\t\t\t|\t\t����ѯ�ĺ����\"%s\"Ϊ�գ�����\t\t|\n", flightNumOne);
		printf("\t\t\t---------------------------------------------------------\n");
		printf("�Ƿ������ѯ(y/n):");
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

	printf("\n�Ƿ��˳���ѯ����(y/n):");
	scanf("%c", &yOrn);
	printf("\n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		SelectOptions(info);
	else
		SearchSelectOne(info);
}

//ͨ�����վ��ѯ
void searchByStartPoint(flightLists* info)
{
	char StartPoint[10];			//���վ
	int judge = 0;                     //�ж��Ƿ��ѯ����Ϣ

	printf("\n��������Ҫ��ѯ�����վ��");
	gets(StartPoint);
	gets(StartPoint);
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	puts("\t|   �����  |   ���վ	|   �յ�վ	|	 ���ʱ��	|	����ʱ��	|    ����	|    Ʊ��       |");
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	char yOrn = 'y';
	for (int i = 0; i < info->length; i++)
	{
		if (strcmp(info->infos[i].StartPoint, StartPoint) == 0)   //�������ѯ�����վ�������ӡ����
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
		printf("\t\t\t|\t\t����ѯ�ĺ����\"%s\"Ϊ�գ�����\t\t|\n", StartPoint);
		printf("\t\t\t---------------------------------------------------------\n");
		printf("�Ƿ������ѯ(y/n):");
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

	printf("�Ƿ��˳���ѯ����(y/n):");
	scanf("%c", &yOrn);
	printf("/n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		SelectOptions(info);
	else
		SearchSelectOne(info);
}

//ͨ���յ�վ��ѯ
void searchByEndPoint(flightLists* info)
{
	char EndPoint[10];				//�յ�վ
	int judge = 0;                     //�ж��Ƿ��ѯ����Ϣ

	printf("\n��������Ҫ��ѯ���յ�վ��");
	gets(EndPoint);
	gets(EndPoint);
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	puts("\t|   �����  |   ���վ	|   �յ�վ	|	 ���ʱ��	|	����ʱ��	|    ����	|    Ʊ��       |");
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	char yOrn = 'y';
	for (int i = 0; i < info->length; i++)
	{
		if (strcmp(info->infos[i].EndPoint, EndPoint) == 0)   //�������ѯ���յ�վ�������ӡ����
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
		printf("\t\t\t|\t\t����ѯ�ĺ����\"%s\"Ϊ�գ�����\t\t|\n", EndPoint);
		printf("\t\t\t---------------------------------------------------------\n");
		printf("�Ƿ������ѯ(y/n):");
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

	printf("�Ƿ��˳���ѯ����(y/n):");
	scanf("%c", &yOrn);
	printf("/n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		SelectOptions(info);
	else
		SearchSelectOne(info);
}



//ͨ�����ʱ���ѯ
void searchByStartTime(flightLists* info)
{
	char StartTime[15];				//���ʱ��
	int judge = 0;                     //�ж��Ƿ��ѯ����Ϣ

	printf("\n��������Ҫ��ѯ�����ʱ�䣺");
	gets(StartTime);
	gets(StartTime);
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	puts("\t|   �����  |   ���վ	|   �յ�վ	|	 ���ʱ��	|	����ʱ��	|    ����	|    Ʊ��       |");
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	char yOrn = 'y';
	for (int i = 0; i < info->length; i++)
	{
		if (strcmp(info->infos[i].StartTime, StartTime) == 0)   //�������ѯ�����ʱ��������ӡ����
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
		printf("\t\t\t|\t\t����ѯ�ĺ����\"%s\"Ϊ�գ�����\t\t|\n", StartTime);
		printf("\t\t\t---------------------------------------------------------\n");
		printf("�Ƿ������ѯ(y/n):");
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

	printf("�Ƿ��˳���ѯ����(y/n):");
	scanf("%c", &yOrn);
	printf("/n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		SelectOptions(info);
	else
		SearchSelectOne(info);
}

//ͨ������ʱ���ѯ
void searchByEndTime(flightLists* info)
{
	char EndTime[15];				//����ʱ��
	int judge = 0;                     //�ж��Ƿ��ѯ����Ϣ

	printf("\n��������Ҫ��ѯ�ĵ���ʱ�䣺");
	gets(EndTime);
	gets(EndTime);
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	puts("\t|   �����  |   ���վ	|   �յ�վ	|	 ���ʱ��	|	����ʱ��	|    ����	|    Ʊ��       |");
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	char yOrn = 'y';
	for (int i = 0; i < info->length; i++)
	{
		if (strcmp(info->infos[i].EndTime, EndTime) == 0)   //�������ѯ�ĵ���ʱ��������ӡ����
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
		printf("\t\t\t|\t\t����ѯ�ĺ����\"%s\"Ϊ�գ�����\t\t|\n", EndTime);
		printf("\t\t\t---------------------------------------------------------\n");
		printf("�Ƿ������ѯ(y/n):");
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

	printf("�Ƿ��˳���ѯ����(y/n):");
	scanf("%c", &yOrn);
	printf("/n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		SelectOptions(info);
	else
		SearchSelectOne(info);
}

//ͨ�����Ͳ�ѯ
void searchByPlaneType(flightLists* info)
{
	char PlaneType[10];				//����
	int judge = 0;                     //�ж��Ƿ��ѯ����Ϣ

	printf("\n��������Ҫ��ѯ�Ļ��ͣ�");
	gets(PlaneType);
	gets(PlaneType);
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	puts("\t|   �����  |   ���վ	|   �յ�վ	|	 ���ʱ��	|	����ʱ��	|    ����	|    Ʊ��       |");
	puts("\t-------------------------------------------------------------------------------------------------------------------------");
	char yOrn = 'y';
	for (int i = 0; i < info->length; i++)
	{
		if (strcmp(info->infos[i].PlaneType, PlaneType) == 0)   //�������ѯ�Ļ��ʹ������ӡ����
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
		printf("\t\t\t|\t\t����ѯ�ĺ����\"%s\"Ϊ�գ�����\t\t|\n", PlaneType);
		printf("\t\t\t---------------------------------------------------------\n");
		printf("�Ƿ������ѯ(y/n):");
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

	printf("�Ƿ��˳���ѯ����(y/n):");
	scanf("%c", &yOrn);
	printf("/n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		SelectOptions(info);
	else
		SearchSelectOne(info);
}