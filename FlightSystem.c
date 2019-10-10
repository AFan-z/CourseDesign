#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>  //�ṩexit����ԭ��
#include "Flight.h"



void infoInput(flightLists *info)    //������Ϣ¼��
{

	FILE *fp;

	//��air.txt�ļ�
	if ((fp = fopen("flight.txt", "w+")) == NULL) {
		fprintf(stdout, "���󣬴򲻿�\"flight.txt\"�ļ�\n");
		exit(EXIT_FAILURE);       //�˳�
	}

	puts("��¼�뺽����Ϣ��");
	puts("�ֱ�����:�����(��:AB123)�����վ(��:����)���յ�վ(��:����)�����ʱ��(��:10-10/12:12)\n"
		"����ʱ��(��:10-10/20:12)������(��:AC123)��Ʊ��(��:1234)(�Կո�ָ���ÿ������,�س�ȷ��)\n");
	info->length = 0;
	char yOrn = 'y';
	fprintf(fp, "|   �����  	|   ���վ	|   �յ�վ	|		 ���ʱ��		|		����ʱ��		|    ����	|    Ʊ��	|\n");
	for (int i = 0; i < MAX; i++)
	{
		if (yOrn == 'y' || yOrn == 'Y'|| yOrn == '\n')
		{
			//¼�뺽����Ϣ
			fscanf(stdin, "%s%s%s%s%s%s%d", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, &info->infos[i].price);  
			//��������Ϣ������ļ�
			fprintf(fp, "	%s			%s		 %s			%s			%s				 %s		%d\n", info->infos[i].FlightNum, info->infos[i].StartPoint, info->infos[i].EndPoint,
				info->infos[i].StartTime, info->infos[i].EndTime, info->infos[i].PlaneType, info->infos[i].price);

			info->length++;   //��¼������

		}else
			break;
		printf("\n");
		printf("�Ƿ������Ҫ¼�뺽����Ϣ(y/n):");
		scanf("%c", &yOrn);
		scanf("%c", &yOrn);
		printf("\n");
	}
	fclose(fp);
}





/*
��Ŀ11��������Ϣ�Ĳ�ѯ�����
�Էɻ�������Ϣ����¼�롢����Ͳ��ҵȲ�����ÿ�������¼��������ֱ��ǣ�����š����վ���յ�վ�����ʱ�䡢����ʱ�䡢�����Լ�Ʊ�ۡ�
2������Ҫ��
��1��¼�룺���ý���������ʽ��Ӻ�����Ϣ�����������ļ���
��2����ѯ���ɰ�����ĺ���š����վ���յ�վ�����ʱ���Լ�����ʱ�����Ϣ���в�ѯ��
��3�����򣺿ɰ�����ĺ���š�Ʊ�۽�������
��4��ɾ�������ݺ����ɾ�����������Ϣ��
��5���޸ģ����ݺ�����޸ĺ��������Ϣ��

*/

int main()
{
	flightLists *info;
	info = (flightLists *)malloc(sizeof(flightLists));

	infoInput(info);
	SearchSelectOne(info);

	free(info);
	system("pause");
	return(0);
}



