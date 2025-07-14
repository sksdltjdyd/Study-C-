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

	strcmp(input1, input2) == 0 ? printf("두 문자열이 같습니다.\n") : printf("두 문자열이 다릅니다.\n"); // 두 문자열 비교

	return 0;
}