#include "Header.h"

int main() {
	/*
	문자열
	문자의 배열이라는 개념으로, 문자열은 문자들의 순서 있는 집합이다
	일반적으로 두가지 방법을 사용한다
	1. C 스타일 문자열
	- 문자 배열의 끝에 널 문자('\0')를 추가하여 문자열의 끝을 표시한다
	- 예: char str[] = "Hello";
	- 포인터 사용 : const char* str = "Hello";*/

	char myString[100]; // C 스타일 문자열을 사용하여 문자열 입력

	strcpy(myString, "Hello, World!"); // 문자열 복사

	printf("C 스타일 문자열: %s\n", myString); // 문자열 출력

	fseek(stdin, 0, SEEK_END);
	scanf("%99[^\n]s", myString);
	// 사용자로부터 문자열 입력 받기. 오른쪽 변수에 &기호를 붙이지 않는 이유는 myString이 이미 배열의 시작 주소를 가지고 있기 때문. 실전에서 활용 시 %s대신 "%99[^\n]s"와 같이 입력받을 최대 길이를 지정하는 것이 좋다.

	printf("사용자 입력 문자열: %s\n", myString); // 입력받은 문자열 출력

	// strcpy,strcmp 사용 예시
	char strl[100];
	strcpy(strl, "Hello, World!"); // 문자열 복사
	strcmp(strl, myString) == 0 ? printf("두 문자열이 같습니다.\n") : printf("두 문자열이 다릅니다.\n"); // 문자열 비교

	//Null terminated string : 문자열의 끝을 나타내는 널 문자('\0')가 있어야 한다. C 스타일 문자열은 널 문자로 끝나야 한다. 그렇지 않으면 문자열 함수들이 제대로 작동하지 않을 수 있다.

	return 0;
}	