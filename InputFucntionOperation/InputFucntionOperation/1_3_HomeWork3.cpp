#include <cstdio>

int inputv() {
	int input;
	printf("���� �Է��ϼ��� : ");
	scanf_s("%d", &input);
	return input;
}

int square(int a) {
	return a * a;

}

int main() {

	int value = inputv();
	value = square(value);

	printf("���� %d�Դϴ�", value);

	return 0;
}