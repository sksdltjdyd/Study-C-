#include "Header.h"

int main() {
	char input1[100];

	fseek(stdin, 0, SEEK_END);
	printf("input1 문자열을 입력하세요 : ");
	scanf("%99[^\n]s", input1); // 사용자로부터 첫 번째 문자열 입력 받기

	int index = 0;
	for (int i = 0 ;; i++)
	{
		if (input1[i] == '\0') {
			index = i;
			break; // 문자열의 끝에 도달하면 루프 종료
		}
	}

	for (int i = index - 1; i >= 0; i--)
	{
		printf("%c", input1[i]); // 역순으로 첫 번째 문자열 출력
	}

	return 0;
}