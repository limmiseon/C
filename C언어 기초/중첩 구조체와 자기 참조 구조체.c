// 중첩 구조체 : 구조체 안에 구조체를 선언한다.
#include <stdio.h>

typedef struct {
	char name[15];
	int age;
} Teacher;

typedef struct {
	char name[15];
	int age;
	Teacher teacher; // 다른 구조체를 멤버로 포함
} Student;

int main(){
	Student Student;
	Teacher Teacher;
	
	Student.teacher.age = 30;
  // Student안의 Teacher 구조체를 이용하고 싶으면 Student.Teacher.age와 같이 연속으로 멤버를 참조해야 사용할 수 있다.
	Teacher.age = 40;
	
	return 0;
}

// 자기 참조 구조체 : 자기 자신을 참조하도록 자기와 똑같은 타입의 구조체를 멤버로 가질 수 있다.
typedef struct {
	char name[15];
	int age;
	struct Student *ptr; // 자기 자신을 가리키는 포인터를 멤버로 가질 수 있다.
} Student;
// 중첩 구조체처럼 어떠한 정보를 저장하는 것도 아니고, 자기 자신을 가리키는 이유?
// 자기 참조 구조체는 연결 리스트나 트리를 만들 때 사용된다.