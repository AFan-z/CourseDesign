#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>  //�ṩexit����ԭ��
#include "Flight.h"


//ѡ����Ҫͨ������Ϣ¼�뺽����Ϣ
void InputSelectOne(flightLists* info)
{
	int one = -1;
	char input;
	printf("\n");
	puts("\t-------------------------");
	puts("\t|\t1.�ֶ�¼��\t|");
	puts("\t-------------------------");
	puts("\t|\t2.�ļ�����\t|");
	puts("\t-------------------------");
	puts("\t|\t0.�˳�¼��\t|");
	puts("\t-------------------------");

	printf("��������ͨ������Ϣ¼�뺽����Ϣ(0-2):");
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
			printf("��������ȷ����Ϣ��¼�뺽����Ϣ(0-2):");
		}
	}
}


//����ԭ�е������ļ���Ϣ
void InputByOld(flightLists* info)
{
	FILE* fp;


	int i = info->length;
	char ch;

	if ((fp = fopen("flightInfo.txt", "a+")) == NULL) {
		fprintf(stdout, "���󣬴򲻿�\"flightInfo.txt\"�ļ�\n");
		exit(EXIT_FAILURE);       //�˳�
	}

	ch = fgetc(fp);                  //�ж��Ƿ�Ϊ���ļ�
	if (ch != EOF)					//���Ϊ�����´��ļ���
	{
		fclose(fp);
		if ((fp = fopen("flightInfo.txt", "a+")) == NULL) {
			fprintf(stdout, "���󣬴򲻿�\"flightInfo.txt\"�ļ�\n");
			exit(EXIT_FAILURE);       //�˳�
		}
	}
	
	while (ch !=EOF && !feof(fp))   //�ж��Ƿ񵽴��ļ�β
	{
		fscanf(fp,"%s%s%s%s%s%s%d", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
			info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, &info->infos[i].price);
		i++;

		if (!feof(fp))
			info->length++;
	}
	if (fclose(fp) != 0)
		fprintf(stderr, "���󣬹رղ����ļ�\n");
}


//������Ϣ¼��
void InputInfo(flightLists* info)
{

	FILE* fp, * FInfo;

	//����ʱ�ļ�
	if ((fp = fopen("flightInput.txt", "w+")) == NULL) {
		fprintf(stdout, "���󣬴򲻿�\"flightInput.txt\"�ļ�\n");
		exit(EXIT_FAILURE);       //�˳�
	}

	//���ļ�
	if ((FInfo = fopen("flightInfo.txt", "a+")) == NULL) {
		fprintf(stdout, "���󣬴򲻿�\"flightInfo.txt\"�ļ�\n");
		exit(EXIT_FAILURE);       //�˳�
	}

	puts("\n��¼�뺽����Ϣ��\n");

	char yOrn = 'y';
	//if (fgetc(fp) == EOF)       //�����ϢΪ�������ļ���ӡ��ͷ
	//	fprintf(fp, "|   �����  	|   ���վ	|   �յ�վ	|		 ���ʱ��		|		����ʱ��		|    ����	|    Ʊ��	|\n");
	for (int i = info->length; i < FLIGHT_INFO_MAX; i++)
	{
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		{
			//¼�뺽����Ϣ

			printf("�����뺽���(��:CA1302)��");
			scanf("%s", info->infos[i].FlightNum);
			printf("���������վ(��:����)��");
			scanf("%s", info->infos[i].StartPoint);
			printf("�������յ�վ(��:����)��");
			scanf("%s", info->infos[i].EndPoint);
			printf("���������ʱ��(��:201910161523)��");
			scanf("%s", info->infos[i].StartTime);
			printf("�����뵽��ʱ��(��:201910162320)��");
			scanf("%s", info->infos[i].EndTime);
			printf("���������(��:777(��))��");
			scanf("%s", info->infos[i].PlaneType);
			printf("������Ʊ��(��:1234)��");
			scanf("%d", &info->infos[i].price);

			//��������Ϣ�������ʱ�ļ�
			fprintf(fp, "%s	%s	%s	%s	%s	%s	%d\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);
			//���溽����Ϣ
			fprintf(FInfo, "%s	%s	%s	%s	%s	%s	%d\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);
			info->length++;   //��¼������

		}
		else
		{
			SelectOptions(info);   //�˻�ѡ���������
			return;
		}

		printf("\n");
		printf("�Ƿ������Ҫ¼�뺽����Ϣ(y/n):");
		scanf("%c",&yOrn);
		scanf("%c",&yOrn);
		printf("\n");
	}


	if (fclose(fp) != 0 || fclose(FInfo) != 0)
		fprintf(stderr, "���󣬹رղ����ļ�\n");

	printf("\n");
	printf("�Ƿ����¼��(y/n):");
	scanf("%c",&yOrn);
	printf("\n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		InputSelectOne(info);
	else
		SelectOptions(info);

}

//���ļ���¼�뺽����Ϣ
void InfoInputByFlie(flightLists* info)
{
	FILE* fp, * FInfo;
	int i = info->length;
	char flieName[20];  //�ļ���
	char yOrn;

	printf("\n������Ҫ���뺽����Ϣ���ļ�����");
	gets(flieName);
	gets(flieName);

	if ((fp = fopen(flieName,"r")) == NULL) {
		fprintf(stdout, "���󣬴򲻿�\"%s\"�ļ�\n", flieName);
		exit(EXIT_FAILURE);       //�˳�
	}

	//���ļ�
	if ((FInfo = fopen("flightInfo.txt", "a+")) == NULL) {
		fprintf(stdout, "���󣬴򲻿�\"flightInfo.txt\"�ļ�\n");
		exit(EXIT_FAILURE);       //�˳�
	}


	while (!feof(fp))   //�ж��Ƿ񵽴��ļ�β
	{

		fscanf(fp,"%s %s %s %s %s %s %d", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
			info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, &info->infos[i].price);

		//�������ļ�
		fprintf(FInfo, "%s	%s	%s	%s	%s	%s	%d\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
			info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);
		i++;
		info->length++;
	}


	if (fclose(fp) != 0 || fclose(FInfo) != 0)
		fprintf(stderr, "���󣬹رղ����ļ�\n");

	printf("\n");
	printf("�Ƿ����¼��(y/n):");
	scanf("%c",&yOrn);
	printf("\n");
	if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		InputSelectOne(info);
	else
		SelectOptions(info);

}


//��ӡ������Ϣ
void InfoPrint(flightLists* info)
{
	puts("\n\n���еĺ�����ϢΪ��");
	puts("\t------------------------------------------------------------------------------------------------------------------------");
	puts("\t|   �����  |   ���վ	|   �յ�վ	|	 ���ʱ��	|	����ʱ��	|    ����	|    Ʊ��      |");
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
		printf("\t\t\t|\t\t�޺�����Ϣ������¼�룡����\t\t|\n");
		printf("\t\t\t---------------------------------------------------------\n");
	}

	SelectOptions(info);

}


//�޸Ļ�ɾ���󱣴����ļ���
void InfoDelOrUpdate(flightLists* info)
{
	FILE* fp;


	if ((fp = fopen("flightInfo.txt", "w+")) == NULL) {
		fprintf(stdout, "���󣬴򲻿�\"flightInfo.txt\"�ļ�\n");
		exit(EXIT_FAILURE);       //�˳�
	}


	for (int i = 0; i < info->length; i++)
	{
		fprintf(fp, "%s	%s	%s	%s	%s	%s	%d\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
			info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);
	}

	if (fclose(fp) != 0)
		fprintf(stderr, "���󣬹رղ����ļ�\n");
}
