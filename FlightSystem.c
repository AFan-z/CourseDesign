#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>  
#include "Flight.h"


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


//ѡ�����
void SelectOptions(flightLists *info)
{
		int one = -1;
		printf("\n");
		puts("\t---------------------------------");
		puts("\t|\t1.¼�뺽����Ϣ\t\t|");
		puts("\t---------------------------------");
		puts("\t|\t2.��ѯ������Ϣ\t\t|");
		puts("\t---------------------------------");
		puts("\t|\t3.���򺽰���Ϣ\t\t|");
		puts("\t---------------------------------");
		puts("\t|\t4.ɾ��������Ϣ\t\t|");
		puts("\t---------------------------------");
		puts("\t|\t5.�޸ĺ�����Ϣ\t\t|");
		puts("\t---------------------------------");
		puts("\t|\t0.�˳�����    \t\t|");
		puts("\t---------------------------------");

		printf("������Ҫѡ��Ĳ���(0-5)��");
		while (one < 0 || one > 5)
		{
			scanf("%d", &one);
			switch (one)
			{
			case 0:
				break;
			case 1:
				InputSelectOne(info);
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
				printf("��������ȷ����Ϣ��ѡ�����(0-5):");
			}
		}
		printf("\n");
}


int main(void)
{
	flightLists *info;
	info = (flightLists *)malloc(sizeof(flightLists));
	info->length = 0;  //����˳����ʼ����

	InputByOld(info);   //���������ļ�
	SelectOptions(info);  //ѡ�����

	free(info);
	system("pause");
	return(0);
}