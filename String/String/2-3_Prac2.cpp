#include "Header.h"

int main() {
	char input1[100];
	char input2[100];

	fseek(stdin, 0, SEEK_END);
	printf("input1 문자열을 입력하세요 : ");
	scanf("%99[^\n]s", input1); // 사용자로부터 첫 번째 문자열 입력 받기
	fseek(stdin, 0, SEEK_END);
	printf("input2 문자열을 입력하세요 : ");
	scanf("%99[^\n]s", input2); // 사용자로부터 두 번째 문자열 입력 받기

	for (int i = 0 ;; i++)
	{
		if (input1[i] == '\0' || input2[i] == '\0') {
			break; // 문자열의 끝에 도달하면 루프 종료
		}
		if (input1[i] != input2[i]) {
			printf("두 문자열은 다릅니다.\n");
			return 0; // 문자열이 다르면 프로그램 종료
		}
		else
		{
			printf("두 문자열은 같습니다.\n");
			return 0; // 문자열이 같으면 프로그램 종료
		}
	
	}

	return 0;
}