#include "Header.h"

int main() {
	char input1[100];
	char input2[100];

	fseek(stdin, 0, SEEK_END);
	printf("input1 ���ڿ��� �Է��ϼ��� : ");
	scanf("%99[^\n]s", input1); // ����ڷκ��� ù ��° ���ڿ� �Է� �ޱ�
	fseek(stdin, 0, SEEK_END);
	printf("input2 ���ڿ��� �Է��ϼ��� : ");
	scanf("%99[^\n]s", input2); // ����ڷκ��� �� ��° ���ڿ� �Է� �ޱ�

	strcmp(input1, input2) == 0 ? printf("�� ���ڿ��� �����ϴ�.\n") : printf("�� ���ڿ��� �ٸ��ϴ�.\n"); // �� ���ڿ� ��

	return 0;
}