// 상수 포인터 : 주소값을 바꿀 수 없는 상수 포인터
#include <stdio.h>

int main()
{
  // 포인터가 가리키는 변수를 상수화
	int num = 10;
	int *ptr1 = &num;
.
	const int *ptr2 = &num;
  // const를 가장 앞에 사용하게 되면, 이 포인터를 "이용해" 변수의 값을 변경하는 것을 막는다.
	*ptr1 = 20;
	num = 30;

	*ptr2 = 40; // 에러. 상수화된 ptr2를 이용해 변수의 값을 변경할 수 없다. 그렇다고 변수 num 자체가 상수가 된 것은 아니라서, num의 값을 변경하는 것은 가능하다.

	return 0;
}

#include <stdio.h>

int main()
{
  // 포인터 상수화
	int num1 = 10, num2 = 20;
	int *ptr1 = &num1;
	int* const ptr2 = &num1;
	// 자료형 다음에 const를 선언하게 되면 포인터 변수 자체가 상수화 된다. 즉, 주소값을 변경할 수 없다. 여기서 주의할 점은, 포인터를 상수화 시킬때에는 const 전에 * 연산자를 써주어야 한다. 만약 int const * ptr 처럼 사용한다면 const를 제일 앞에 써준것과 같은 효과가 난다.

	ptr1 = &num2;
	
	*ptr2 = 30; // 포인터를 이용해서 값을 변경하는 것은 가능
	ptr2 = &num2; // 에러. 포인터가 가리키고 있는 주소값을 변경하는 것은 불가능하다. 따라서 "이 포인터가 오로지 num1 변수만을 가리키며, 절대 다른 변수를 가리키지 않겠다" 라고 생각한다면 위와 같이 선언하면 되는 것이다.
	
	return 0;
}

#include <stdio.h>

int main()
{
	int num = 10, num2 = 20;
	int *ptr1 = &num;
	const int* const ptr2 = &num;
  // 포인터를 통해 값을 변경하는 것도, 다른 변수를 가리키는 것도 불가능하게 하고 싶다면, const를 두번 써주는 것도 가능하다.
	
  ptr1 = &num2;

	*ptr2 = 30; // 에러
	ptr2 = &num2; // 에러

	return 0;
}