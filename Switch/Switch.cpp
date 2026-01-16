#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 

int main()
{
	char input;
	printf("알파벳을 입력해 주세요.");
	(void)scanf("%c", &input);

	switch (input)
	{
	case 'a':
		printf("a의 아스키코드는 : %d", input);
		break;
	case 'b':
		printf("b의 아스키코드는 : %d", input);
		break;
	case 'c':
		printf("c의 아스키코드는 : %d", input);
		break;
	}
}



