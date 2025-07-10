#include <cstdio>

int getinput() {
	int input = 0;
	printf("숫자를 적어주세요 : ");
	scanf_s("%d", &input);
	return input;
}


int main() {

	int input = 0;
	input = getinput();

	if (input <= 0) {
		printf("숫자를 잘못 입력했습니다");
	}
	
	else {
		for (int i = 0; i < input; i++)
		{
			printf("A");
		}
	}
	printf("\n");

	input = getinput();

	if (input <= 0) {
		printf("숫자를 잘못 입력했습니다");
	}

	else {
		for (int i = 0; i < input; i++)
		{
			printf("B");
		}
	}


	return 0;
}