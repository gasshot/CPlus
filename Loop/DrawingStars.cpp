#include "DrawingStars.h"
#include <stdio.h>

void drawingStars(int a) 
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

void reverseDrawingStars() 
{
	for (int i = 0; i < 9; i++)
	{
		for (int k = 0; k < 9 - i; k++)
		{
			printf(" ");
		}
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void drawingTriangle() 
{
	for (int i = 0; i < 9; i++)
	{
		for (int k = 9 - 1; k > i; k--)
		{
			printf(" ");
		}
		for (int j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void reverseDrawingTriangle()
{
	for (int i = 0; i < 9; i++)
	{
		for (int k = 0; k < i; k++)
		{
			printf(" ");
		}
		for (int j = 2 * 9 - 1; j > 2 * i; j--)
		{
			printf("*");
		}
		printf("\n");
	}
}