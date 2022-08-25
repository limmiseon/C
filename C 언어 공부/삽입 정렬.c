#include <stdio.h>

int main()
{  
  // 삽입 정렬은 차례차례 범위를 늘려가면서 정렬하는 알고리즘으로, 하나의 값을 선정하고 해당 값을 자신보다 작은 요소를 찾을 때까지 이동하면서 자리를 교환한다. 삽입 정렬은 배열이 길어질수록 효율이 떨어지지만 버블 정렬에 비해 좀 더 빠르며, 버블 정렬과 마찬가지로 구현이 단순하다.
	int arr[10] = {9, 17, 5, 6, 124, 112, 1, 3, 87, 55};
	int length = sizeof(arr) / sizeof(int);

	int j;
	int temp;
	for(int i=1; i<length; i++)
	{
		temp = arr[i];
		j = i-1; // 배열에서 선정된 값 아래로 비교를 하기 때문에 i-1로 설정한다.
		while(j>=0 && temp < arr[j])
		{
			arr[j+1] = arr[j]; // 큰 수가 뒤로 가도록 바꾸어 준다. temp에 들어있는 값이 비교하는 변수보다 작을 경우에는 temp보다 큰 변수를 찾거나, 위치가 제일 처음으로 갈 때까지 while문을 돌게 된다.
			j--;
		}
		arr[j+1] = temp; // 위에서 j--를 해 주었으므로 다시 +1을 더한 자리에 temp 값을 대입한다.
		}
	
	for(int i=0; i<length; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}