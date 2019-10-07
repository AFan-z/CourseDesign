/*使用标椎的I/O*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>  //提供exit（）原型

int main(int argc, char *argv[])
{
	int ch;  //读取文件是，储存每个字符的地方
	FILE *fp; //文件指针
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
		putc(ch, stdout);   //与putchar（）相同
		count++;
	}
	fclose(fp);

	printf("\n");
	printf("File %s has %lu characters\n", argv[1], count);

	system("pause");

	return 0;
}