#include <cstdio>

int getinput() {

	int input;
	printf("숫자를 입력 하세요 : ");
	fseek(stdin, 0, SEEK_END);
	scanf_s("%d", &input);

	return input;
}

int getopper() {

	int input;
	printf("Operation 값을 입력 하세요 : ");
	fseek(stdin, 0, SEEK_END);
	scanf_s("%d", &input);

	return input;
}

int sum(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int pow(int a, int b) {
	int value = 1;
	for (int i = 0; i < b; i++)
	{
		value = value * a;
	}

	return value;
}

int main() {

	int input1 = 0;
	int input2 = 0;
	int operataion = 0;
	
	input1 = getinput();
	input2 = getinput();
	operataion = getopper();
	int value = 0;

	if (operataion == 0)
	{
		value = sum(input1, input2);
		printf("갑은 %d입니다", value);
	}

	else if (operataion == 1)
	{
		value = sub(input1, input2);
		printf("갑은 %d입니다", value);
	}

	else if (operataion == 2)
	{
		value = pow(input1, input2);
		printf("갑은 %d입니다", value);
	}

	else
	{
		printf("Operation값을 잘못 입력했습니다");
	}
	return 0;
}