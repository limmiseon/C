// 학생 정보를 저장하는 구조체를 만들어서 수십 수백명의 정보를 저장해야 한다면, 일반 변수처럼 구조체도 일일히 선언하는 것보다 배열을 쓰는 것이 훨씬 편리하다.
// 구조체 배열을 선언하는 방법은 일반적인 배열을 선언하는 방법과 같다.
#include <stdio.h>

typedef struct {
	char name[30];
	int age;
} Student;

int main(){
	Student goorm[3] = { {.name = "해리 포터"}, {.name = "헤르미온느 그레인저"}, {.name = "론 위즐리"} };
  // 구조체도 문자열은 선언할 때만 초기화 할 수 있으므로 선언과 동시에 초기화를 해주고, 나이는 선언 후에 값을 대입한다.
	
	goorm[0].age = 10;
	goorm[1].age = 10;
	goorm[2].age = 10;
	
	printf("이름 : %s / 나이 : %d\n", goorm[0].name, goorm[0].age);
	printf("이름 : %s / 나이 : %d\n", goorm[1].name, goorm[1].age);
	printf("이름 : %s / 나이 : %d\n", goorm[2].name, goorm[2].age);
	
	return 0;
}