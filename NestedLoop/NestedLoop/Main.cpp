#include <cstdio>

int main() {

	// break : �ݺ����� Ż���ϰ� �ϴ� ����
	// continue : �ݺ����� ó������ �ǵ��ư��� �ϴ� ����

	// ;;�� ���� �ݺ� ����
	for (;;) {
		printf("�ݺ����Դϴ�. ���ڸ� �Է��ϼ��� : ");
		int input;
		fseek(stdin, 0, SEEK_END);
		scanf_s("%d", &input);

		if (input == 0) {
			continue;
		}

		else if (input == 1) {
			break;
		}
		printf("�ݺ����� �������Դϴ�\n");
	}

	printf("���α׷��� �����մϴ�/n");

	/*
	��ø�� �ݺ���

	�ݺ����� �������� ��ø�� �� �ִ�.

	for(����){
		for(����){

		...}
	}
	*/

	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < k; k++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}