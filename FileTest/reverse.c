#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define CNTL_Z '\032'  //DOS�ı��ļ��е��ļ���β���
#define SLEN 81

int main(void) {
	char file[SLEN];
	char ch;
	FILE *fp;
	long count, last;

	puts("enter the name of the file to be proccessed:");
	scanf("%80s", file);
	if ((fp = fopen(file, "rb")) == NULL) { 
		 //ֻ��ģʽ
		printf("Can't open %s\n", file);
		exit(EXIT_FAILURE);
	}

	fseek(fp, 0L, SEEK_END);  //���嵽�ļ�ĩβ

	last = ftell(fp); 
	for (count = 1L; count <= last; count++) {
		fseek(fp, -count, SEEK_END);   //����
		ch = getc(fp);
		if (ch != CNTL_Z && ch != '\r')   //MS-DOS�ļ�
			putchar(ch);
	}
	putchar('\n');
	fclose(fp);

	system("pause");
	return 0;
}