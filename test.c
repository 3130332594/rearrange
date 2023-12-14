#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define COL_MAX 20
#define INPUT_MAX 100

int read_column_numbers(int columns[], int max);
void rearrange(const char* input, const char* output, int columns[], int num);
int main()
{
	char input[INPUT_MAX];//�����������
	char output[INPUT_MAX];//����������
	int columns[COL_MAX];//����б�����
	int num;//���columns��Ԫ�ظ���

	//�����б�
	printf("���������뵥�����֣�ÿ�����ּ��Կո�������������-1��ʾ����\n");
	num = read_column_numbers(columns, COL_MAX);
	//����ԭʼ�ַ���
	gets(input);
	printf("ԭʼ����Ϊ: %s\n", input);
	//�������������ַ������е���
	rearrange(input, output, columns, num);
	printf("������Ϊ��%s", output);
	return EXIT_SUCCESS;
}

int read_column_numbers(int columns[], int max)
{
	int ch;//������뻺����
	int num = 0;//��������Ԫ�ظ���
	int col=0;//columns�����±�

	//����Ҫ������ʾ��Χ���±�
	while(col < max && scanf("%d", &columns[col])==1 && columns[col] >= 0)
	{
		col++;
		num++;
	}
	//��Ϊ�±귶Χ�ǳɶԵģ��ʼ���Ƿ�Ϊż��
	if (num % 2 != 0)
	{
		puts("erro input");
		exit(EXIT_FAILURE);
	}
	while ((ch = getchar()) != '\n')
	{
		;
	}

	return num;
}

void rearrange(const char* input,  char* output, int columns[], int num)
{
	int col;//columns�����±�
	int len;//����input�ĳ���
	int nchars;//Ŀ�귶Χ�ڵ�Ԫ�ظ���
	int output_col=0;//����output����

	len = strlen(input);
	//
	for (col = 0; col < num; col += 2)
	{
		nchars = columns[col + 1] - columns[col] + 1;
		//�ж�input�Ƿ�С��nchars
		if (nchars > len&&output_col>INPUT_MAX)
		{
			break;
		}
		//���շ�Χ���п���
		strncpy(output + output_col, input + columns[col], nchars);
		output_col += nchars;
	}
	*(output + output_col) = 0;
}

///��ջ�����
