#include <stdio.h>

int main()
{
	char ch = 'ab'; // ch = 'b'
	// char 자료형은 1바이트로 한 글자만 담을 수 있다. 만약 한 글자를 초과하면 마지막으로 입력한 문자가 변수에 담기게 된다.

	printf("ch 는 %c", ch);
	
	// 변수에 여러 글자 담기
	char arr1[5] = "abcd";
	printf("arr1 은 %s", arr1);
	// 여러 글자가 담긴 문자열을 출력할 때는 %c가 아닌 %s를 사용한다.

	// 배열의 크기가 4글자인데 5만큼 차지하는 이유는?
	// 종료 문자(0, NULL, \0)를 통해 어디까지 출력할 것인지를 컴퓨터에게 알려줘야 한다.

	char arr2[7] = { 'a', 'b', 'c', 'd', 0, 'e', 'f' };
	
	printf("arr2 는 %s", arr2); // abcd 까지만 출력됨.

	// 문자 입력받기
	char ch1;
	// 한 글자만 입력하는 경우 1개를 초과해서 입력하면 처음 글자만 변수에 담기게 된다.
	scanf("%c", &ch1); // ab 입력시 ch1 = a
	
	// 문자열 입력받기
	char arr3[201];

	printf("200 자 이내로 입력해주세요 : ");
	scanf("%s", arr3);
	// sacnf를 사용해서 문자열 배열의 값을 입력받는 경우 &를 쓰지 않고 그냥 변수 이름만 써주어도 된다. 배열의 경우, 배열의 이름에 주소를 담고 있기 때문이다. (포인터에서 더 자세히 다룸)

	return 0;
}