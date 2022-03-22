#include <stdio.h>

int main()
{
	int A[10][10] = {
		{ 2, 3, 4, 5, 6, },
		{ 2, 3, 4, 5, 6, },
		{ 2, 3, 4, 5, 6, },
		{ 2, 3, 4, 5, 6, },
		{ 2, 3, 4, 5, 6, },	
	};
	
	int B[10][10] = {
		{ 4, 1, 5, 3, 2, },
		{ 4, 1, 5, 3, 2, },
		{ 4, 1, 5, 3, 2, },
		{ 4, 1, 5, 3, 2, },
		{ 4, 1, 5, 3, 2, },		
	};
	
	int AB[10][10] = { 0, };
	
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			for(int k = 0; k < 5; k++)
			{
				AB[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	
	printf("AB = \n");
	for(int i = 0; i < 5 ; i++)
	{
		for(int j = 0; j < 5 ; j++)
		{
			printf("%d ", AB[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
