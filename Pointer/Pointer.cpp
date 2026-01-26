#include <stdio.h>
#include "Pointer.h"

void address_operator()
{
	int a;
	a = 2;

	printf("%d \n", a);
	printf("%p \n", &a);// & 주소연산자
}

void pointer_operator()
{
	int* p;
	int a;
	p = &a;
	a = 2;

	printf("포인터 p에 들어있는 값 : %p \n", p);
	printf("a의 값 : %d \n", a);
	printf("p의 값 : %d \n", *p);

	// a변수의 주소를 p 포인터 변수에 대입
	// * 역참조 연산자로 역참조하여 해당 데이터에 접근 가능
}

void  swap(int a, int b) 
{
	int temp = a;
	a = b;
	b = temp;
}


int main()
{
	//address_operator();
	//pointer_operator();

	//NewFunction();

	int arr[10] = { 10, 20, 30,40, 50,60 ,70, 80, 90, 100 };
	int* ptr;

	ptr = arr;

	printf("포인터의 주소:%p\n", ptr);
	printf("포인터의 값:%d\n", *ptr);

	ptr += 2;

	printf("포인터의 주소:%p\n", ptr);
	printf("포인터의 값:%d\n", *ptr);

	return 0;
}

void NewFunction()
{
	int a = 5;
	int b = 10;
	printf("값 교환 전 : a=%d, b=%d\n", a, b);
	swap(a, b);
	printf("값 교환 후 : a=%d, b=%d\n", a, b);
}
