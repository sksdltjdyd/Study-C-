#include <cstdio>

/*
함수[Function]
- 입력을 받아 어떤 값을 만들어내는 동작을 하는 구문이 사용자로부터 받는 입력이 아니라 프로그램 내부에서 파라미터(parameter)로 받는 입력을 말한다. 즉, 입력을 받아서 어떤 값을 만들어내는 것을 말한다
- 반복해야 하는 코드를 함수로 만들 수도 있다

함수명 규칙
변수 이름 규칙과 동일하다. 같은 이름을 갖는 함수는 존재할수 없지만 대소문자는 구별한다
*/

int inputFunc() {
	int input;
	printf("값을 입력하세요 : ");
	scanf_s("%d", &input);
	printf("값은 %d입니다\n", input);
	
	return input;
}


int reture() {

	return 100; // 함수가 끝날떄 100값이 리턴된다
}


/*
파라미터(parameter)
함수로 입력되는 값(사용자가 지정하여 입력한 값이 아님)
파라미터는 함수 내부에서 변수처럼 동작한다
*/
int addFunc(int a, int b) {
	return a + b;
}


int main() {

	/*
	연산
	+ : 더하기
	- : 빼기
	* : 곱하기
	/ : 나누기
	*/

	int v1 = 4 + 3;
	int v2 = 4 - 4;
	int v3 = 4 * 3;
	int v4 = 4 / 2;
	printf("%d, %d, %d, %d", v1, v2, v3, v4);

	/*
	연산자의 종류
	- 이항 연산자 : 피연산자가 두개 (a + b, a / b)
	- 단항 연산자 : 피연산자가 한개 (a++, b--)
	*/

	int vadd = 11;
	vadd++;
	printf("\n%d", vadd);

	int vsub = 9;
	vsub--;
	printf("\n%d\n", vsub);

	/*
	사용자 입력 - scanf(...);
	c/c++에서는 사용자로부터 입력을 받기 위해 scanf라는 구문을 활용한다
	활용법은 printf와 비슷하지만, 변수의 앞에 &(앰퍼샌드)를 꼭 붙여줘야 한다
	

	int input;
	printf("값을 입력하세요 : ");
	scanf_s("%d", &input); // 윈도우에서는 활용시 scanf_s라 작성하거나 define 소스코드를 써야 한다
	printf("값은 %d입니다", input);
	*/

	inputFunc();
	inputFunc();
	inputFunc();

	// 함수 내 파라미터 개수는 맞춰서 작성해줘야 한다
	int v6 = addFunc(3, 4);
	printf("%d", v6);

	return 0;
}