#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>  //�ṩexit����ԭ��
#define MAX 50


typedef struct
{                                   //������Ϣ
	char AirNum[10];                //�����
	char StartPoint[10];			//���վ
	char EndPoint[10];				//�յ�վ
	char StartTime[15];				//���ʱ��
	char EndTime[15];				//����ʱ��
	char PlaneType[10];				//����
	int price;						//Ʊ��
}airInfo;

typedef struct {                  
	airInfo infos[MAX];
	int length;					 //�������
}airLists;

void infoInput(airLists *info)
{

	FILE *fp;

	if ((fp = fopen("air.txt", "w+")) == NULL) {
		fprintf(stdout, "���󣬴򲻿�\"air.txt\"�ļ�\n");
		exit(EXIT_FAILURE);       //�˳�
	}

	puts("��¼�뺽����Ϣ��");
	puts("�ֱ�����:����š����վ���յ�վ�����ʱ�䡢����ʱ�䡢���͡�Ʊ��(�Կո�ָ���ÿ������)");

	char yOrn = 'y';
	fprintf(fp, "|   �����  	|   ���վ	|   �յ�վ	|		 ���ʱ��		|		����ʱ��		|    ����	|    Ʊ��	|\n");
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

		printf("�Ƿ���Ҫ¼�뺽����Ϣ(y/n):");
		scanf("%c", &yOrn);
		scanf("%c", &yOrn);

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
	airLists *info;
	info = (airLists *)malloc(sizeof(airLists));

	infoInput(info);

	system("pause");
	return(0);
}



