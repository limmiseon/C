#include <stdio.h>

int main()
{
	int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110};
	
	int sum = 0; //값은 항상 0으로 초기화 해줘야한다. 안하면 쓰레기값이 들어가 있음. 
	for(int i = 0; i < 10; i++)
	{
		sum += numArr[i];	
	}
	
	printf("%d", sum);
	return 0;
}
