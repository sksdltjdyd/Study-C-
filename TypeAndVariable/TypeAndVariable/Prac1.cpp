#include "Header.h"

int main() {
	float value1 = inputValue();
	float value2 = inputValue();
	char oper = getoper();

	float result = 0.0f;
	bool valid = true;
	switch (oper)
	{
	case '+':
		result = add(value1, value2);
		break;
	case '-':
		result = sub(value1, value2);
		break;
	case '*':
		result = mul(value1, value2);
		break;
	case '/':
		if (value2 != 0) {
			result = div(value1, value2);
		} else {
			printf("Error: Division by zero is not allowed.\n");
			valid = false;	
		}
		break;
	case '%':
		if ((int)value2 != 0) {
			result = mod(value1, value2);
		} else {
			printf("Error: Division by zero is not allowed.\n");
			valid = false;
		}
		break;
	default:
		printf("Error: Invalid operator.\n");
		valid = false;
		break;
	}

	if (valid == true) {
		printf("Result: %.3f\n", result);
	}
	else {
		printf("Calculation failed due to invalid input.\n");
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