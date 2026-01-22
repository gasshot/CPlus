#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Array.h"

// 배열 생성 + 길이 계산 + 출력까지 담당
void printFixedArray(void)
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int length = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < length; i++)
	{
		printf("Array의 %d번째 요소는 %d\n", i + 1, arr[i]);
	}
}


void calculateItemPrices()
{
	int arr[5];
	int i, ave = 0;

	int length = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < length; i++)
	{
		printf("%d 번째 아이템 가격은 ", i + 1);
		(void)scanf("%d", &arr[i]);
	}

	for (i = 0; i < length; i++)
	{
		ave += arr[i];
	}
	printf("\n");
	printf("전체 아이템 가격의 총합과 평균\n");
	printf("총합 : %d\n", ave);
	printf("평균 : %d", ave / length);

}
void printArrayValues(int arr[3][4])
{
	//int (*p)[3][4] = &arr; 	//*((*p) + 1)
	//printf("2행 3열의 수: %d", (*p)[1][2]);

	printf("2행 3열의 수: %d\n", arr[1][2]);
	printf("1행 2열의 수: %d\n", arr[0][1]);

}

int main()
{
	//printFixedArray();
	//calculateItemPrices();

	int arr[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};


	printArrayValues(arr);

	return 0;
}

