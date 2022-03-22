#include <stdio.h>

int main()
{
	int decimal = 0;
	int binary[4] = { 1, 1, 0, 1 };
	
	for(int index = 0; index <= 3; index++)
	{
		if(binary[index] == 1)
		{
			int result = 1 ;
			for(int n = 3; n > index; n--)
			{
				result *= 2;
			}
			decimal += result;
		}
	}
	printf("%d ", decimal);
	return 0;
}
