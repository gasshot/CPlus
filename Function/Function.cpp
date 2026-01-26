#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add_Number(int* parr);
int print_Hello() 
{
	printf("Hello!!\n");
	return 500;
	printf("안보임!!\n");
}

int returnNum(int inputNum) 
{
	// 입력값, 출력(반환)값 함수
	// 입력값에 수정을 가한 후 입력값을 반환
	inputNum += 10;
	return inputNum;
}

int add(int num)
{
	printf("%d\n", num);
	return num;
}

char add(char num)
{
	printf("%c\n", num);
	return num;
}

float add(float num)
{
	printf("%f\n", num);
	return num;
}

int main() 
{
	//int arr[3];
	//for (int i = 0; i < 3; i++)
	//{
	//	scanf("%d", &arr[i]);
	//}

	//add_Number(arr);
	//printf("배열의 각 원소: %d, %d, %d", arr[0], arr[1], arr[2]);
	add(10);
	add('A');
	add(0.05f);

	return 0;
}

int add_Number(int* parr) 
{
	int i;
	for (i = 0; i < 3; i++)
	{
		parr[i]++;
	}
	return 0;
}