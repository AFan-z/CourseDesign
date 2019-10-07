/*ʹ�ñ�׵��I/O*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>  //�ṩexit����ԭ��

int main(int argc, char *argv[])
{
	int ch;  //��ȡ�ļ��ǣ�����ÿ���ַ��ĵط�
	FILE *fp; //�ļ�ָ��
	unsigned long count = 0;
	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);   //��putchar������ͬ
		count++;
	}
	fclose(fp);

	printf("\n");
	printf("File %s has %lu characters\n", argv[1], count);

	system("pause");

	return 0;
}