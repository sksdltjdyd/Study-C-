#include <cstdio>

int main() {

	/*
	조건문 : 어떤 조건이 맞으면 조건에 따른 값이 나오는 코드
	반복문 : 조건만 맞으면 구문을 반복
	*/

	/*
	논리 연산자
	&& : And 연산자. 모든 조건이 맞아야 하는 연산자
	|| : Or 연산자. 둘 중 하나의 조건만 맞아도 되는 연산자

	비교 연산자
	a == b : 두 값이 같다면 참
	a != b : 두 값이 다르면 참
	a > b : a가 더 크면 참
	a < b : b가 더 크면 참
	a >= b : a가 더 크거나 같으면 참
	a <= b : b가 더 크거나 같으면 참
	*/

	// 참 : true, 거짓 : false

	int v1 = 3;
	int v2 = 4;
	int v3 = 30;
	int v4 = 35;

	if (/*조건*/ v1 > v2 && v3 == v4)
	{
		// 조건이 참이면 실행
		printf("if true");
	}
	else if (/*조건*/ v1 == v2 || v3 < v4) {
		// if 구문이 참이 아닌데 여기서 조건이 참이면 실행
		// else if 구문은 if 구문과 else 구문 사이에 여러개 나올 수도 있고 없을수도 있다
		printf("else if true");
	}
	else {
		// 위의 조건문이 모두 참이 아닐때 실행
		printf("else true");
	}

	/*
	반복문은 크게 while과 for 구문이 있다
	while 구문은 자주 사용하진 않는다
	*/

	while (/*조건*/v1 == v2)
	{
		// 조건이 참일 시, 반복해서 실행. 반복할 코드
		printf("while true");
	}

	int count = 0;
	for (/*시작시 실행 구문; 조건; 반복 마지막에 실행구문;*/ int i = 0; i < 100; i++)
	{
		// 코드
		count = count + 10;
	}
	printf("\n%d", count);

	return 0;
}