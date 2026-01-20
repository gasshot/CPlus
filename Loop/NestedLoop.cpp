#include "NestedLoop.h"
#include <stdio.h>

void nestedLoop() 
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			printf("%d X %d = %02d\n", i, j, i * j);
		}
		printf("///구구단 %d단완료///\n", i);
	}

}