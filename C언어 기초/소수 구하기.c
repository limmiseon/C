#include <stdio.h>

int main()
{
  // 소수 구하기
  // 1. 소수란, 1과 자기 자신 외에는 나눠지지 않는 수를 말한다. 1은 소수가 아니다.
  // 2. 값을 입력받아서 입력받은 값 이하의 수 중 소수를 출력한다.
  // * 이중포문 이용
  // * 소수란, 나누어 떨어지는 수가 두개 있다. (1과 자기 자신)
	int num;
	scanf("%d", &num);
	
	for (int i=1; i<=num; i++)
	{
		int count = 0;		
		for (int j=1; j<=num; j++)
		{
			if (i % j == 0)
			{
				count++;
			}
		}
		
		if(count==2)
		{
			printf("%d ", i);
		}
	}

	return 0;
}