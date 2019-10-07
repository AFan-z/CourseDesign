/*���ļ�ѹ��Ϊԭ����1/3*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>   //�ṩexit()ԭ��
#include<string.h>    //�ṩ strcpy(),strcat()ԭ��
#define LEN 40

int main(int argc, char *argv[]) {
	FILE *in, *out;  //��������ָ��FILEָ��
	int ch;
	char name[LEN];  //��������ļ���
	int count = 0;

	//��������в���
	if (argc < 2) {
		fprintf(stderr, "argc < 2,   %s \n", argv[0]);
		exit(EXIT_FAILURE);
	}

	//��������
	if ((in = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "(in = fopen(argv[1], \"r\")) == NULL,  \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	//�������
	strncpy(name, argv[2], LEN - 5); //�����ļ���
	name[LEN - 5] = '\0';

	strcat(name, ".red");   //���ļ��������.red

	if ((out = fopen(name, "w")) == NULL) { //�Զ�дģʽ���ļ�

		fprintf(stderr, "out = fopen(name, \"w\")) == NULL,\n");
		exit(3);
	}

	//��������
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out); //��ӡ3���ַ��еĵ�1���ַ�

	//��β����
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "(fclose(in)!=0||fclose(out)!=0\n");

	system("pause");
	return 0;

}