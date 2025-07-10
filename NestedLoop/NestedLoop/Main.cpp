#include <cstdio>

int main() {

	// break : 반복문을 탈출하게 하는 구문
	// continue : 반복문의 처음으로 되돌아가게 하는 구문

	// ;;는 무한 반복 구문
	for (;;) {
		printf("반복문입니다. 숫자를 입력하세요 : ");
		int input;
		fseek(stdin, 0, SEEK_END);
		scanf_s("%d", &input);

		if (input == 0) {
			continue;
		}

		else if (input == 1) {
			break;
		}
		printf("반복문의 마지막입니다\n");
	}

	printf("프로그램을 종료합니다");

	/*
	중첩된 반복문

	반복문은 여러개가 중첩될 수 있다.

	for(조건){
		for(조건){
		
		...}
	}
	*/

	return 0;
}