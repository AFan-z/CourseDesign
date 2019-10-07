/*把文件压缩为原来的1/3*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>   //提供exit()原型
#include<string.h>    //提供 strcpy(),strcat()原型
#define LEN 40

int main(int argc, char *argv[]) {
	FILE *in, *out;  //声明两个指向FILE指针
	int ch;
	char name[LEN];  //储存输出文件名
	int count = 0;

	//检查命令行参数
	if (argc < 2) {
		fprintf(stderr, "argc < 2,   %s \n", argv[0]);
		exit(EXIT_FAILURE);
	}

	//设置输入
	if ((in = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "(in = fopen(argv[1], \"r\")) == NULL,  \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	//设置输出
	strncpy(name, argv[2], LEN - 5); //拷贝文件名
	name[LEN - 5] = '\0';

	strcat(name, ".red");   //在文件名后添加.red

	if ((out = fopen(name, "w")) == NULL) { //以读写模式打开文件

		fprintf(stderr, "out = fopen(name, \"w\")) == NULL,\n");
		exit(3);
	}

	//拷贝数据
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out); //打印3个字符中的第1个字符

	//收尾工作
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "(fclose(in)!=0||fclose(out)!=0\n");

	system("pause");
	return 0;

}