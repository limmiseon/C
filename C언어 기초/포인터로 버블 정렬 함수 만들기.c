#include <stdio.h>

void bubbleSort(int *arr)
{
	int temp;	
	for(int i=0; i<10 - 1; i++)
	{
		for(int j=0; j<10 - 1 - i; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}		
	}
}

int main()
{
	int arr[10];
	for(int i=0; i<10; i++)
	{
		scanf("%d", &arr[i]);
	}

	bubbleSort(arr); // & 붙여도 되고 안 붙여도 됨

	for(int i=0; i<10; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}