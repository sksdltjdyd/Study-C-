#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>

#define VALUE1

class Person {
public:
	/*
	클래스 내부에서의 const 멤버
	- 이 const라는 것이 실제로 변수로서 저장공간을 갖고 있다는것을 확인하는 방법은 클래스 멤버를 const로 선언하는것이다
	- 이렇게  const로 선언된 클래스 멤버 변수는 선언과 동시에 초기화를 하거나, 클래스 생성자에서 초기화를 해줘야 한다
	- 생성자에서 초기화를 해줄 때에는 변수이름(초기값)과 같은 방법을 이용해 초기화 한다
	*/
	const int age;

	// 생성자에서 const 초기화 방법. 변수가 들어가는것도 가능하다
	Person(int n) : age(n) {

	}

};

/*
static
- static 이라는것은 '정적'이라는 뜻이다
- 정적인 어떤거라는 읨로 유일하고 독립적인 어떤 것을 의미한다
- 이 static은 class 내부에 존재할 경우 class 내부에서 유일하고 독립적인 멤버라는 뜻
- class 외부에 존재 할 경우 obj파일(오브젝트 파일) 내부에서 유일하고 독립적인 존재라는 뜻이 된다
- (글로벌이라는 뜻이 아니다. 절대로, 그렇게 생각하면 안된다)
*/

class Myclass {
public:
	int a;
	static int b;

	void foo();

	static void goo();
		

};

/*
extern
- extern키워드는 '외부에서 존재한다'는 뜻이다
- 어떻게 보면 c/c++에서 obj 파일로 링크가 되면서 만들어지는 진정한 전역 변수를 만들어 줄 수 있는 키워드라고 볼 수 있다
- 이 extern 키워드의 활용과 뜻은 굉장히 많지만 초보적인 내용에서는 '전역변수'를 만들어 준다 이정도로만 이해해도 충분하다
*/

// 전역적인 extern 변수 선언
extern int myint;