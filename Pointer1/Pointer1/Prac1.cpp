#include "Header.h"

int main() {
	
	int num1;
	int num2;

	int* pNum1 = &num1; // num1�� �ּҸ� �����ϴ� ������ ����
	int* pNum2 = &num2; // num2�� �ּҸ� �����ϴ� ������ ����

	*pNum1 = GetInput(); // pNum1�� ����Ű�� �ּҿ� GetInput()�� ��ȯ���� ����
	*pNum2 = GetInput(); // pNum2�� ����Ű�� �ּҿ� GetInput()�� ��ȯ���� ����

	int result = sum(num1, num2);
	printf("�Է��� �� ������ ��: %d\n", result);

	return 0;
}

int GetInput() {
	int input;
	printf("������ �Է��ϼ���: ");
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &input);
	return input;
}

int sum(int a, int b) {
	return a + b;
}