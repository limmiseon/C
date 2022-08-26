#include <stdio.h>

int main()
{
	// 내림차순 정렬
	int arr[10] = {9, 17, 5, 6, 124, 112, 1, 3, 87, 55};
	int temp; // 두 값을 바꿀 때 사용할 변수
	int length = sizeof(arr) / sizeof(int); // 배열의 크기 구하기
	
  // 배열의 가장 마지막은 비교할 수 없으므로 length - 1
	for (int i=0; i < length - 1; i++)
	{
    // length - 1 - i 로 해주면 이미 정렬된 숫자는 비교하지 않는다.
		for (int j=0; j < length - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	
	for (int k=0; k < length; k++) {
		printf("%d ", arr[k]);
	}

	return 0;
}