#include <stdio.h>

int main()
{
		int num1 = 10, num2 = 20, num3 = 30;
    // 포인터 배열은 참조 연산자를 붙인다는 것만 빼면 일반 배열과 똑같이 선언하며, 대입할 때는 변수의 주소값을 넣는다.
		int *parr[3];

		parr[0] = &num1;
		parr[1] = &num2;
		parr[2] = &num3;

		for(int i=0; i<3; i++)
		{
			printf("parr[%d] : %d\n", i, *parr[i]);
		}

		return 0;
}