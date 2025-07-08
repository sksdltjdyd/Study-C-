#include <cstdio>

int inputv() {
	int input;
	printf("값을 입력하세요 : ");
	scanf_s("%d", &input);
	return input;
}

int square(int a) {
	return a * a;

}

int main() {

	int value = inputv();
	value = square(value);

	printf("값은 %d입니다", value);

	return 0;
}