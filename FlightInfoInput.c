#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>  //�ṩexit����ԭ��
#include "Flight.h"



//������Ϣ¼��
void InfoInput(flightLists *info)
{

	FILE *fp;

	//��air.txt�ļ�
	if ((fp = fopen("flight.txt", "w+")) == NULL) {
		fprintf(stdout, "���󣬴򲻿�\"flight.txt\"�ļ�\n");
		exit(EXIT_FAILURE);       //�˳�
	}

	puts("\n��¼�뺽����Ϣ��\n");
	puts("�ֱ�����:�����(��:AB123)�����վ(��:����)���յ�վ(��:����)�����ʱ��(��:10-10/12:12)\n"
		"����ʱ��(��:10-10/20:12)������(��:AC123)��Ʊ��(��:1234)(�Կո�ָ���ÿ������,�س�ȷ��)\n");
	info->length = 0;
	char yOrn = 'y';
	if (fgetc(fp) == EOF)       //�����ϢΪ�������ļ���ӡ��ͷ
		fprintf(fp, "|   �����  	|   ���վ	|   �յ�վ	|		 ���ʱ��		|		����ʱ��		|    ����	|    Ʊ��	|\n");
	for (int i = info->length; i < MAX; i++)
	{
		if (yOrn == 'y' || yOrn == 'Y' || yOrn == '\n')
		{
			//¼�뺽����Ϣ
			fscanf(stdin, "%s%s%s%s%s%s%d", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, &info->infos[i].price);
			//��������Ϣ������ļ�
			fprintf(fp, "	%s			%s		 %s			%s			%s				 %s		 %d\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);

			info->length++;   //��¼������

		}else
			{
				SelectOptions(info);   //�˻�ѡ���������
				return;
			}

		printf("\n");
		printf("�Ƿ������Ҫ¼�뺽����Ϣ(y/n):");
		scanf("%c", &yOrn);
		scanf("%c", &yOrn);
		printf("\n");
	}
	fclose(fp);

}