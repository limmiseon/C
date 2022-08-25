#include <stdio.h>

int main()
{
  // 두 변수의 값을 바꾸려면 두 변수로는 부족하고, 또다른 제 3의 변수가 필요하다. 이름은 보통 temp라고 짓는다.
	int a;
	scanf("%d", &a);
	int b;
	scanf("%d", &b);	
	int temp;

	temp = a;
	a = b;
	b = temp;

	printf("a : %d\n", a);
	printf("b : %d", b);	

	return 0;
}