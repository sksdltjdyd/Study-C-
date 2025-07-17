#include "Header.h"

struct Marine
{
	int hp = 40;
	int mp = 0;
};

/*
함수 파라미터의 포인터
- 파라미터의 포인터는 단순히 변수의 주소값을 받기 위함일 수 있지만 배열 변수를 받기 위함일 수도 있다
- 구분하는 방법은 보통 배열의 경우 배열의 갯수를 알려주는 변수를 따로 받는다
*/

void foo(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = i * 10; // 배열의 각 요소에 값을 할당
	}
}

void goo(int* arr) {
	// 단순 값만 변경하는 함수
}

void hoo(const char* str) {
	// const char*는 문자열을 읽기 전용으로 사용
	// str[0] = 'A'; // 오류 발생: const로 선언된 문자열은 수정할 수 없다.
	printf("String: %s\n", str);
}

int main() {
	
	int* p = 0; // 0으로 초기화. C++11부터 nullptr를 사용하는 것이 좋다.
	int* P = nullptr; // nullptr로 초기화. 변수를 선언할때 값을 할당하지 않으면 쓰레기값이 들어가므로 주의해야 한다.

	p = (int*)malloc(sizeof(int)); // malloc을 사용하여 메모리 할당. C++에서는 new를 사용하는 것이 좋다.
	*p = 10; // 할당된 메모리에 값 할당. p가 가리키는 메모리에 10을 저장한다.
	free(p); // 할당된 메모리 해제. C++에서는 delete를 사용하는 것이 좋다.

	/*
	배열 초기화
	- 배열의 모든 값을 0으로 초기화하려면 다음과 같이 할 수 있다.
	- int arr[10] = { 0, }; -> 배열의 모든 값을 0으로 초기화
	- int arr[10] = {}; -> 배열의 모든 값을 0으로 초기화
	- int* arr[10] = { nullptr, }; -> 포인터 배열의 모든 값을 nullptr로 초기화
	*/
	
	int* arr[10] = { nullptr, };

	Marine* marine[40] = { nullptr, };
	
	for (int i = 0; i < 40; i++)
	{
		marine[i] = (Marine*)malloc(sizeof(Marine));
		marine[i]->hp = 40;
		marine[i]->mp = 10;
	}

	for (int i = 0; i < 40; i++)
	{
		printf("Marine[%d] - HP: %d, MP: %d\n", i, marine[i]->hp, marine[i]->mp);
		free(marine[i]); // 할당된 메모리 해제
	}

	/*
	포인터의 포인터
	- 포인터의 포인터는 포인터를 가리키는 포인터이다.
	- 포인터의 포인터를 사용하면 다차원 배열이나 동적 할당된 배열을 쉽게 관리할 수 있다
	- 포인터의 포인터는 쉽게 생각하면 다차원 배열과 비슷하다.
	- 예를 들어, Marine** marinePtr;은 Marine* marinePtr[20];와 비슷하다
	*/

	Marine** marinePtr = (Marine**)malloc(sizeof(Marine*) * 40); // Marine 포인터 배열을 동적 할당
	for (int i = 0; i < 40; i++)
	{
		marinePtr[i] = (Marine*)malloc(sizeof(Marine)); // 각 Marine 포인터에 대해 메모리 할당
		marinePtr[i]->hp = 50;
		marinePtr[i]->mp = 10;
	}

	hoo("Hello, World!"); // 문자열을 읽기 전용으로 사용
	
	char* str = (char*)malloc(20 * sizeof(char)); // 동적 할당된 문자열
	strcpy(str, "Hello, Pointer!"); // 문자열 복사
	hoo(str); // 문자열을 읽기 전용으로 사용

	// void* : 보이드 포인터. 보이드 포인터는 어떤 타입의 포인터든지 받을 수 있는 포인터이다. 
	return 0;
}