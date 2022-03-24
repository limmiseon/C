#include <stdio.h>

int plus(int a, int b){
	int result;
	result = a + b;
	return result;
}

int minus(int a, int b){
	int result;
	result = a - b;
	return result;
}

int mul(int a, int b){
	int result;
	result = a * b;
	return result;
}

int div(int a, int b){
	int result;
	result = a / b;
	return result;
}

int powA(int a, int b){
	int result = 1;
	for(int i = 0; i < b; i++){
		result *= a;
	}
	return result;
}

int main (){
	int returnData;
	returnData = powA(2, 1);
	printf("%d", returnData);
	return 0;
}

