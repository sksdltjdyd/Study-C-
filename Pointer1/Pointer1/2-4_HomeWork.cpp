#include "Header.h"



int main() {
	
	int a;
	int b;
	int result;
	bool valid = true;

	int* pA = &a;
	int* pB = &b;
	int* pResult = &result;

	*pA = GetInput();
	*pB = GetInput();
	char oper = GetOper();

	switch (oper)
	{
		case '+':
		*pResult = sum(*pA, *pB);
		break;
		case '-':
			*pResult = sub(*pA, *pB);
			break;
		case '*':
			*pResult = mul(*pA, *pB);
			break;
		case '/':
			*pResult = Div(*pA, *pB);
			break;
	default:
		printf("�߸��� �������Դϴ�.\n");
		valid = false;
		break;
	}

	if (valid == true) {
		printf("%d %c %d = %d\n", *pA, oper, *pB, *pResult);
	} else {
		printf("����� ������ �� �����ϴ�.\n");
	}

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

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int Div(int a, int b) {
	if (b == 0) {
		printf("0���� ���� �� �����ϴ�.\n");
		return 0;
	}
	return a / b;
}

char GetOper() {
	char oper;
	printf("�����ڸ� �Է��ϼ��� (+, -, *, /): ");
	fseek(stdin, 0, SEEK_END);
	scanf(" %c", &oper);
	return oper;
}