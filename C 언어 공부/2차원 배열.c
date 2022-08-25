#include <stdio.h>

int main()
{
  // 2차원 배열 초기화와 출력
	int tarr[3][4] =
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};
	
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<4; j++)
		{
			printf("%d ", tarr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

#include <stdio.h>

int main()
{
  // 2차원 배열 문자열 입력
  // 문자열을 입력할 때에는 char의 일차원 배열을 이용한다. 한 가지 유의할 점은 문자열의 경우 마지막 자리에는 종료문자(\0, 0, NULL)이 들어간다는 것을 명심해야 한다.
	char tarr[3][10];
	
	printf("2차원 배열 문자열 입력\n");
  // 입력받고 출력할 때 이중 반복문이 아닌 일반 반복문을 사용한다. 2차원 배열을 선언했지만 문자열의 경우엔 기본적으로 일차원 배열이고 %s 라는 형식지정자가 있기 때문에 반복문 하나만으로도 입출력을 할 수 있다.
	for(int i=0; i<3; i++)
	  {
	    printf("10자 이내의 문자열을 입력해주세요 : ");
	    scanf("%s", tarr[i]);
	  }

  // 2차원 배열 문자열 출력
	  printf("\n2차원 배열 문자열 출력\n");
	  for(int i=0; i<3; i++)
	  {
	    printf("%s\n", tarr[i]);
	  }

	  return 0;
}
