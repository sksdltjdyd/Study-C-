#include "Header.h"

int main() {
	
	int num1;
	int num2;

	int* pNum1 = &num1; // num1의 주소를 저장하는 포인터 변수
	int* pNum2 = &num2; // num2의 주소를 저장하는 포인터 변수

	*pNum1 = GetInput(); // pNum1이 가리키는 주소에 GetInput()의 반환값을 저장
	*pNum2 = GetInput(); // pNum2가 가리키는 주소에 GetInput()의 반환값을 저장

	int result = sum(num1, num2);
	printf("입력한 두 정수의 합: %d\n", result);

	return 0;
}

int GetInput() {
	int input;
	printf("정수를 입력하세요: ");
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &input);
	return input;
}

int sum(int a, int b) {
	return a + b;
}