#include <stdio.h>

int main() 
{
	int a; // 4Byte 
	a = 99;

	float float_pi = 3.141592f; // 4Byte
	double double_pi = 3.141592; // 8Byte

	char c = 'C'; // 1Byte

	printf("a는 %d \n", a);
	printf("b는 %f \n", float_pi);
	printf("c는 %c \n", c);

	return 0;
}