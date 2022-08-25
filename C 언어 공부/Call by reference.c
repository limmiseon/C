// call by value
// 기본적으로 C언어에서 지원하는 방식이다. 함수에서 값을 복사해서 전달하는 방식으로, 인자로 전달되는 변수를 함수의 매개변수에 복사한다. 이렇게 복사되면 인자로 전달한 변수와는 별개의 변수가 되며, 매개변수를 변경해도 원래의 변수에는 영향을 미치지 않는다. 따라서 원본 값을 바꿀 필요가 없는 경우에는 call by value 방식을 이용한다.
#include <stdio.h>

void swap(int a, int b)
{
	int temp;
	
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a, b;
	
	a = 10;
	b = 20;
	
	printf("swap 전 : %d %d\n", a, b); // a = 10, b = 20
	
	swap(a, b);
	
	printf("swap 후 : %d %d\n", a, b);// a = 10, b = 20
	
	return 0;
  // call by value 형식으로는 swap을 진행해도 매개변수가 바뀌는 것일뿐 원래 변수인 a, b의 값은 변하지 않는다.
}

// call by reference
// 함수에서 값을 전달하는 대신 주소값을 전달하는 방식이다.
// 만약 포인터를 사용해서 주소값을 넣어주게 된다면 call by reference 방식일까? 엄밀히 따지자면 C언어에서의 방식은 주소값 자체를 복사해서 넘겨주는 것이므로 call by value이다. 또한 이렇게 주소값을 복사해서 넘겨주는 것을 call by address 방식이라고 한다. C언어에서는 call by reference를 공식적으로 지원하지 않는다. 그러나 의미적, 결과적으로 call by address를 이용해서 call by reference와 같이 사용할 수 있기 때문에 일반적으로 C언어에서 포인터를 이용해 주소값을 넘겨주는 방식을 call by reference라고 설명하는 곳도 많다.
#include <stdio.h>

// 포인터를 이용한 swap code
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a, b;

	a = 10;
	b = 20;

	printf("swap 전 : %d %d\n", a, b); // a = 10, b = 20

	swap(&a, &b);

	printf("swap 후 : %d %d\n", a, b); // a = 20, b = 10

	return 0;
}