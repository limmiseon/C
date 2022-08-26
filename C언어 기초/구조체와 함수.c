// 구조체를 함수에 전달하는 방법
// 1. 포인터로 전달
// 2. 구조체 그대로 전달

// 포인터를 사용하지 않고 넘겨주게 되면 매개변수에 복사되는 것이므로 원본 값에는 영향을 끼치지 않는다. 따라서 어떤 변수의 값을 가져와서 출력을 한다거나, 원본 값을 수정할 필요가 없는 경우에는 포인터를 사용하지 않고 그냥 복사해서 넘겨주었다.
// 하지만 구조체의 경우는 조금 다르다. 구조체는 여러가지 자료형을 묶어서 새로운 자료형으로 만든 것이기 때문에, 구조체 크기가 커질 수록 복사할 공간이 더 필요하게 된다. 따라서 공간이 낭비되어 비효율적이기 때문에, 값을 바꿀 필요가 없는 경우에도 매개변수로 구조체를 전달할 때에는 보통 포인터를 사용한다.

// 포인터 없이 구조체를 인자로 전달하는 code
#include <stdio.h>

typedef struct {
	int s_id;
	int age;
} Student;

void print_student(Student s){
	s.s_id = 2000;
	s.age = 25;
	
	printf("학번 : %d, 나이 : %d\n", s.s_id, s.age); // 함수 내에서는 바뀐 값으로 출력됨
}

int main(){
	Student s;

	s.s_id = 1000;
	s.age = 20;
	
	print_student(s);
    
	printf("학번 : %d, 나이: %d\n", s.s_id, s.age);// 원래의 값 출력
}

// 포인터로 전달 code
#include <stdio.h>

typedef struct {
	int s_id;
	int age;
} Student;

void print_student(Student *s){
	s->s_id = 2000;
	s->age = 25;
	
	printf("학번 : %d, 나이 : %d\n", s->s_id, s->age);
}

int main(){
	Student s;

	s.s_id = 1000;
	s.age = 20;
	
	print_student(&s);
    
	printf("학번 : %d, 나이: %d\n", s.s_id, s.age);
}