#include "Header.h"

int main() {
	float value1 = inputValue();
	float value2 = inputValue();
	char word = getWord();

	float result = 0.0f;
	bool valid = true;
	srand(time(0));
	int randnum = rand() % 5; // Random number generation, but not used in this context
	switch (word)
	{
	case 'p':
		result = pow(value1, value2);
		break;
	case 'x':
		valid = false;
		break;
	case 'r':
		if (randnum == 0) {
			result = add(value1, value2);
		}
		else if (randnum == 1)
		{
			result = sub(value1, value2);
		}
		else if (randnum == 2) 
		{
			result = mul(value1, value2);
		}
		else if (randnum == 3)
		{
			if (value2 != 0) {
				result = div(value1, value2);
			}
			else {
				printf("에러 : 0으로 나누기는 불가능합니다.\n");
				valid = false;
			}
		}
		else if (randnum == 4) 
		{
			if ((int)value2 != 0) {
				result = mod(value1, value2);
			}
			else {
				printf("에러 : 0으로 나누기는 불가능합니다.\n");
				valid = false;
			}
		}
		break;
	default:
		printf("잘못된 입력입니다.\n");
		valid = false;
		break;
	}

	if (valid == true) {
		printf("Result: %.3f\n", result);
	}
	else {
		printf("프로그램을 종료합니다.\n");
	}
	return 0;
}

float inputValue() {
	float value;
	printf("Enter a value: ");
	fseek(stdin, 0, SEEK_END);
	scanf_s("%f", &value);
	return value;
}

float add(float a, float b) {
	return a + b;
}

float sub(float a, float b) {
	return a - b;
}

float mul(float a, float b) {
	return a * b;
}

float div(float a, float b) {
	return a / b;
}

float mod(float a, float b) {
	return (int)a % (int)b;
}

char getoper() {
	char oper;
	printf("Enter an operator (+, -, *, /, %%): ");
	fseek(stdin, 0, SEEK_END);
	scanf_s(" %c", &oper, 1);
	return oper;
}

char getWord() {
	char input;
	fseek(stdin, 0, SEEK_END);
	printf("Enter a word (p, x, r): ");
	scanf_s("%c", &input);
	return input;
}