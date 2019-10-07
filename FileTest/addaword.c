/*ʹ��fprintf(),fscanf()��rewind()*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 41

int main(void) {
	FILE *fp;
	char words[MAX];

	if ((fp = fopen("wordy", "a+")) == NULL) {
		fprintf(stdout, "(fp = fopen(\"wordy\", \"a + \")) == NULL\n");
		exit(EXIT_FAILURE);
	}

	puts("���words���ļ�,��#");
	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
		fprintf(fp, "%s\n", words);

	puts("�������ݣ�");
	rewind(fp);  //���ص��ļ���ʼ��

	while (fscanf(fp, "%s", words) == 1)
		puts(words);
	puts("Done!");
	if (fclose(fp) != 0)
		fprintf(stderr, "fclose(fp)!=0\n");

	system("pause");
	return 0;
}