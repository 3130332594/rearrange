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
	char input[INPUT_MAX];//存放输入数据
	char output[INPUT_MAX];//存放输出数据
	int columns[COL_MAX];//存放列标区间
	int num;//存放columns的元素个数

	//输入列标
	printf("请依次输入单个数字，每个数字间以空格隔开，最后输入-1表示结束\n");
	num = read_column_numbers(columns, COL_MAX);
	//输入原始字符串
	gets(input);
	printf("原始输入为: %s\n", input);
	//按条件对输入字符串进行调整
	rearrange(input, output, columns, num);
	printf("最后输出为：%s", output);
	return EXIT_SUCCESS;
}

int read_column_numbers(int columns[], int max)
{
	int ch;//清楚输入缓冲区
	int num = 0;//储存数组元素个数
	int col=0;//columns数组下标

	//输入要用来表示范围的下标
	while(col < max && scanf("%d", &columns[col])==1 && columns[col] >= 0)
	{
		col++;
		num++;
	}
	//因为下标范围是成对的，故检查是否为偶数
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
	int col;//columns数组下标
	int len;//储存input的长度
	int nchars;//目标范围内的元素个数
	int output_col=0;//储存output列数

	len = strlen(input);
	//
	for (col = 0; col < num; col += 2)
	{
		nchars = columns[col + 1] - columns[col] + 1;
		//判断input是否小于nchars
		if (nchars > len&&output_col>INPUT_MAX)
		{
			break;
		}
		//按照范围进行拷贝
		strncpy(output + output_col, input + columns[col], nchars);
		output_col += nchars;
	}
	*(output + output_col) = 0;
}

///清空缓存区
