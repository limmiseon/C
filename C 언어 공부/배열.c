#include <stdio.h>

int main()
{
	// 배열의 크기 구하기
	int arr1[] = {1, 2, 3, 4, 5};

	// sizeof는 메모리상에서 차지하고 있는 용량에 대해서 알려준다.
	// 전체 배열의 크기를 배열 중 하나의 요소의 크기로 나누면 배열의 크기를 알 수 있다.
	printf("%d\n", sizeof(arr1) / sizeof(arr1[0]));
	// 배열의 요소 대신 자료형을 넣어도 됨.
	int length = sizeof(arr1) / sizeof(int);

	return 0; 
}
