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

	for (int i = 0 ;; i++)
	{
		if (input1[i] == '\0' || input2[i] == '\0') {
			break; // ���ڿ��� ���� �����ϸ� ���� ����
		}
		if (input1[i] != input2[i]) {
			printf("�� ���ڿ��� �ٸ��ϴ�.\n");
			return 0; // ���ڿ��� �ٸ��� ���α׷� ����
		}
		else
		{
			printf("�� ���ڿ��� �����ϴ�.\n");
			return 0; // ���ڿ��� ������ ���α׷� ����
		}
	
	}

	return 0;
}