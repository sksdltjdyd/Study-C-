#include "Header.h"

int main() {
	char input1[100];

	fseek(stdin, 0, SEEK_END);
	printf("input1 ���ڿ��� �Է��ϼ��� : ");
	scanf("%99[^\n]s", input1); // ����ڷκ��� ù ��° ���ڿ� �Է� �ޱ�

	int index = 0;
	for (int i = 0 ;; i++)
	{
		if (input1[i] == '\0') {
			index = i;
			break; // ���ڿ��� ���� �����ϸ� ���� ����
		}
	}

	for (int i = index - 1; i >= 0; i--)
	{
		printf("%c", input1[i]); // �������� ù ��° ���ڿ� ���
	}

	return 0;
}