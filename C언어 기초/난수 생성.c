// 난수를 만들 때 사용하는 함수
// 1. srand : 호출시 전달받는 인자를 기반으로 난수를 초기화 시킨다.
// 2. rand : srand로 인해 생성된 값을 바탕으로 난수를 생성한다.
// 3. time : 인자값으로 NULL을 넘기면 1970년 1월 1일 0시 이후부터 현재까지 흐른 초 수를 리턴해준다.
// 시간은 멈추지 않고 계속해서 흐르므로 time 함수로 구한 초 수를 기반으로 srand 함수를 이용하여 난수 기준값을 초기화한 다음, rand 함수를 호출하면 시간을 기반으로한 무작위 숫자가 생성된다.
#include <stdio.h>
#include <stdlib.h> // srand와 rand 포함
#include <time.h>// time 포함

int main()
{
	srand(time(NULL)); // rand 함수 호출 전에 선언하면 rand 함수에 무작위의 시드값을 준다.

	int random = rand();
  // rand 함수 사용법
  // 1. rand() % n : 0 ~ n-1 범위의 난수 생성
  // 2. (rand() % n) + 1 : 1 ~ n 범위의 난수 생성

	printf("%d", random);

	return 0;
}