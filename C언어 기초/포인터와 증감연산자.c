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

	*p++;
	// 증감연산자가 참조연산자보다 우선순위가 높기 때문에 *p++의 경우, 주소를 먼저 찾아가지 않고 주소값이 들어있는 변수 p를 먼저 증가시키게 된다. 그러면 포인터 변수에 들어있는 주소값이 증가하게 되어, 증가한 그 주소에는 아무것도 선언되어 있지 않으므로 쓰레기값이 출력된다.

	printf("포인터 p가 가리키는 값 : %d\n", *p); // p = 쓰레기값
	printf("num 값 : %d\n", num); // num = 21

	return 0;
}

#include <stdio.h>

int main()
{
	int arr[5] = { 1, 3, 5, 7, 9};
	double arr2[5] = { 1.1, 3.2, 5.3, 7.4, 9.5 };
	int *arrPtr = arr;
	double *arrPtr = arr2;

	(*arrPtr)++; // 포인터가 가리키는 값 1에서 ++ 증가.
	*arrPtr2++; // 포인터의 주소값에서 1 증가 (double형은 8비트이므로 주소값 + 8, 즉 가리키는 값이 3.2가 됨)

	printf("%d %lf %d\n", *arrPtr, *arrPtr2, arrPtr, arrPtr2)
	// 출력값 : 2 3.200000 1000 2008

	// %lf에 대하여..
	// 1. 값을 scanf()로 입력받을 때
	// float형에 저장할 것이라면 %f로 받고, double형에 저장할 것이라면 %lf로 받아야 한다.
	
	// 2. 값을 printf()로 출력할 때
	// %f로 출력해도 float형이나 double형 모두 출력 가능.
	// why? 원래 printf는 double형이든 float 형이든 %f 하나밖에 없었는데 %lf가 추가됐다. 결국 %f와 %lf는 처리방식이 동일하다. 즉, printf에서 float 값이 전달되면 기본 인자 진급을 통해 자동으로 double 형으로 진급한다.
	// 하지만 포인터는 진급대상에서 제외이니 구분에서 써 주도록 하자. scanf 에서는 인수로 포인터를 받으니 (메모리 주소로 입력) 전달 받는 포인터의 자료형을 알 수가 없고 이를 명시해주기 위해 구분을 하는 것이다.
	
	return 0;
}

