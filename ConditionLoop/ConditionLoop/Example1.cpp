#include <cstdio>

int getinput() {
	int input = 0;
	printf("���ڸ� �����ּ��� : ");
	scanf_s("%d", &input);
	return input;
}


int main() {

	int input = 0;
	input = getinput();

	if (input <= 0) {
		printf("���ڸ� �߸� �Է��߽��ϴ�");
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
		printf("���ڸ� �߸� �Է��߽��ϴ�");
	}

	else {
		for (int i = 0; i < input; i++)
		{
			printf("B");
		}
	}


	return 0;
}