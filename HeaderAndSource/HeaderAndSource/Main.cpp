#include "Header.h" // Header.h 파일을 포함한다. 이 파일에는 함수 선언이 포함되어 있다

int main() {

	int v1 = pow(2, 3); // 2의 3제곱을 계산하는 함수 호출. pow 함수는 <cmath> 헤더에 정의되어 있다
	printf("2의 3제곱은 %d입니다.\n", v1); // 결과를 출력하는 printf 함수 호출

	srand(time(0)); // srand 함수는 <cstdlib> 헤더에 정의되어 있다. 현재 시간을 시드로 사용하여 난수 생성기를 초기화한다
	printf("%d", rand() % 10); // rand() 함수는 <cstdlib> 헤더에 정의되어 있다. 랜덤한 정수를 생성하여 출력한다. % 10을 사용하여 0부터 9까지의 난수를 생성한다

	return 0;
}

int add(int a, int b) { // add 함수 정의. 두 정수를 더하는 함수
	return a + b; // 두 정수를 더한 결과를 반환한다. 함수 선언은 header.h 파일에 있으며 이 파일 마지막에 정의되어 있다
}