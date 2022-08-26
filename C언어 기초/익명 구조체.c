// 구조체 이름을 굳이 적지 않아도 구조체를 선언하고 사용하는 것이 가능하다. 이렇게 구조체 이름을 따로 지정하지 않고 별칭만 사용하는 것을 익명 구조체라고 한다.ㅇㅇㅇㅇ
#include <stdio.h>

typedef struct { // 구조체 이름을 적지 않고 구조체를 선언
	int age;
	char phone_number[14];
} Student; // 별칭만 사용

int main(){
	Student goorm;
	
	printf("나이 : ");
	scanf("%d", &goorm.age);
	printf("번호 : ");
	scanf("%s", goorm.phone_number);
	
	printf("----\n나이 : %d\n번호 : %s\n----", goorm.age, goorm.phone_number);
	
	return 0;
}