#include "Header.h"

#define MYVALUE 100

// 소스파일에서 전역적인 변수 활용
int myint = 100;

int main() {

	/*
	const
	- const는 상수이다
	- 상수라는것은 프로그램이 시작하고 끝날때 까지 절대 변하지 않는 값을 의미한다
	- 하지만 진정한 의미로서의 const는 define 매크로이며, const 키워드를 이용해 만든 변수는 상수 이지만 '저장공간'을 갖고 있는 변수이며 실질적으로 프로그램 내부에 박혀있는 값은 아니다
	*/

	// 좌측은 변수, 오른쪽은 상수
	int value1 = MYVALUE;
	const int value2 = MYVALUE;

	printf("%d\n", value1);

	int input;
	printf("age : ");
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &input);

	Person* p = new Person(input);
	printf("age = %d\n", p->age);

	Myclass* c = new Myclass();
	// static 변수 불러와서 값 할당
	Myclass::b = 100;

	c->foo();
	// 정적 함수 출력 방법
	// c->goo();
	Myclass::goo(); // 이게 더 맞는 방법

	printf("%d", myint);

	return 0;
}

void Myclass::foo() {
		// 다이나믹 함수는 자기 자신의 인스턴스가 존재한다
		a = 100;
		this->a = 200;
		b = 300; // 다이나믹 함수는 static 변수에 마음데로 접근이 가능하다
		printf("foo\n");
	}

void Myclass::goo() {
	// 정적 함수는 그저 존재할 뿐이지 인스턴스가 필요하지는 않다
		// this 키워드가 필요 없다. 주체가 없기 때문이다
		// a = 100; --> 불가능. 주체가 되는 클래스 안에 인스턴스가 필요 없고 존재 하지 않기 떄문에
		// this->a = 200; --> 마찬가지
	b = 100; // static 변수에는 접근 가능
	printf("goo\n");
}

// 주의점 : static 변수는 따로 메인 파일에서 선언해줘야 한다
int Myclass::b = 100;