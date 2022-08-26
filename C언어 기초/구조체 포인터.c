// 구조체 포인터에서 기억해야 할 점
// int형 포인터는 int *ptr; 형식으로 선언했다. 구조체는 struct [구조체 이름]이 자료형이나 마찬가지이다. 따라서 struct student *ptr; 과 같이 선언해야 한다. 이 때 ptr은 구조체를 가리키는 포인터일뿐 절대 구조체가 아니다!

// 구조체 포인터 선언 code
#include <stdio.h>

typedef struct {
	int s_id;
	int age;
} Student;

int main(){
	Student goorm;
	Student *ptr;
	
	ptr = &goorm;
	
	(*ptr).s_id = 1004;
  // 구조체 포인터를 사용할 때 *ptr.age처럼 바로 사용하는 것이 아니라 (*ptr).age와 같이 괄호를 이용해야 한다. 온점도 연산자의 일종이기 대문에 *ptr.age를 이용하면 구조체가 아닌 포인터 변수를 구조체처럼 참조하려고 하기 때문에 오류가 발생한다. 따라서 구조체 포인터를 사용하기 위해서는 항상 괄호를 사용해야 한다.

  // 하지만 매번 구조체 포인터를 사용할 때마다 괄호를 쓰려면 귀찮기 때문에 -> 라는 기호를 대신 쓸 수 있다. 이 기호를 이용하면 괄호를 사용하지 않아도 알아서 주소로 찾아가서 구조체를 참조한다.

	(*ptr).age = 20;
	
	printf("goorm의 학번 : %d, 나이: %d\n", goorm.s_id, goorm.age);
}

// 화살표 기호를 활용한 code
#include <stdio.h>

typedef struct {
    int s_id;
    int age;
} Student;

int main(){
    Student goorm;
    Student *ptr;
    
    ptr = &goorm;
    
    (*ptr).s_id = 1004;
    ptr->age = 20;
    
    printf("goorm의 학번 : %d, 나이: %d\n", goorm.s_id, goorm.age);
}