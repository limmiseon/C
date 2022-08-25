#include <stdio.h>

int main()
{
	int *p = NULL; 
	int num = 15;

	p = &num;
	printf("포인터 p가 가리키는 값 : %d\n", *p); // p = 15
	printf("num의 값 : %d\n\n", num); // num = 15

	*p += 5;
	printf("포인터 p가 가리키는 값 : %d\n", *p); // p = 20
	printf("num 값 : %d\n\n", num);// num = 20

  // 증감연산자 주의
	(*p)++;
	printf("포인터 p가 가리키는 값 : %d\n", *p); // p = 21
	printf("num 값 : %d\n\n", num); // num = 21

  // 증감연산자가 참조연산자보다 우선순위가 높기 때문에 *p++의 경우, 주소를 먼저 찾아가지 않고 주소값이 들어있는 변수 p를 먼저 증가시키게 된다. 그러면 포인터 변수에 들어있는 주소값이 증가하게 되어, 증가한 그 주소에는 아무것도 선언되어 있지 않으므로 쓰레기값이 출력된다.
	*p++;
	printf("포인터 p가 가리키는 값 : %d\n", *p); // p = 쓰레기값
	printf("num 값 : %d\n", num); // num = 21

	return 0;
}