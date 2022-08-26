// 구조체란? 하나 이상의 변수를 묶어서 좀 더 편리하게 사용할 수 있도록 도와주는 도구이다.
// 구조체를 사용하면 편리하게 여러 개의 변수를 사용하고 관리할 수 있다. 사용자가 직접 만드는 자료형인 셈이다.
#include <stdio.h>

// 주소록을 만들기 위한 학생 구조체 정의
// 구조체는 새로운 자료형을 만드는 것과 같다고 할 수 있기 때문에 보통 main 함수 전에 선언한다.

// 구조체의 형태
// struct 구조체 이름 { 구조체 멤버들 };
struct student
{
	char name[15];
	int s_id;
	int age;
	char phone_number[14];
};

int main()
{
	struct student goorm;
	// 구조체를 사용하기 위해서는 main 함수 안에서 따로 선언을 해주어야 한다.
	// goorm의 자료형 : student 구조체
	
	printf("이름 : ");
	scanf("%s", goorm.name);
	printf("학번 : ");
	scanf("%d", &goorm.s_id);
	printf("나이 : ");
	scanf("%d", &goorm.age);
	printf("번호 : ");
	scanf("%s", goorm.phone_number);
	
	printf("이름 : %s, 학번 : %d, 나이 : %d, 번호 : %s\n", goorm.name, goorm.s_id, goorm.age, goorm.phone_number);
	
	return 0;
}


// 구조체 멤버의 초기화
#include <stdio.h>

struct student
{
	int age;
	char phone_number[14];
	int s_id;
};

int main()
{
	// 구조체 멤버를 초기화 할 때에는 멤버 연산자 . 와 중괄호를 사용한다. 구조체는 배열처럼 멤버 전체를 초기화 할 수도 있고, 원하는 변수만을 초기화할 수도 있다.
	struct student goorm = { .age = 20, .phone_number = "010-1234-5678", 10 };
	// 초기화 할 때는 { .멤버이름 = 값 } 과 같은 형태로 초기화 할수도 있으며, 멤버이름을 적지 않고 초기화 할 수도 있다. 멤버 이름을 적지 않을 때는 구조체를 정의했던 순서대로 값이 들어간다. 또한 값을 따로 넣어주지 않은 멤버는 0으로 초기화 된다.
	struct student codigm = { 22, "010-8765-4321"};

	printf("나이 : %d, 번호 : %s, 학번 : %d\n", goorm.age, goorm.phone_number, goorm.s_id);
	printf("나이 : %d, 번호 : %s, 학번 : %d\n", codigm.age, codigm.phone_number, codigm.s_id);

	return 0;
}