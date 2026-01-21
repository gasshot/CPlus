#include "DrawingStars.h"
#include <stdio.h>

void DrawingStars(int a) 
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
}