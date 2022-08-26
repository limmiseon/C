// typedef 키워드는 C언어에서 자료형을 새롭게 이름을 붙일 때 쓰는 키워드이다. typedef를 이용하면 main 함수에서 구조체를 선언할 때 매번 struct를 써줄 필요가 없다.
// typedef를 사용할 때에는 구조체 별칭이 필요한데, 구조체 별칭은 구조체를 정의할 때 중괄호 뒤에 써주면 된다.
#include <stdio.h>

typedef struct _Student { // 구조체 이름 앞에 _
	int age;
	char phone_number[14];
} Student; // 별칭

int main(){
	Student goorm; // 별칭만 써도 구조체 선언이 가능하다.
  // 구조체 별칭은 구조체 이름과 동일하게 써주어도 무관하지만, 일반적으로 구조체 이름과 별칭을 둘 다 쓸 때는 구조체 이름 앞에 _를 붙여준다.
	
	printf("나이 : ");
	scanf("%d", &goorm.age);
	printf("번호 : ");
	scanf("%s", goorm.phone_number);
	
	printf("----\n나이 : %d\n번호 : %s\n----", goorm.age, goorm.phone_number);
	
	return 0;
}