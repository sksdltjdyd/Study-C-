#include "Header.h"

/*
클래스의 상속(Inheritance)
- 어떤 상위 개념을 가지고 더 디테일한 하위 개념을 만드는것
- 클래스를 상속하게 되면 상속하는 클래스와 상속받는 클래스가 존재
- 상속하는 클래스를 부모클래스, 상속받는 클래스를 자식 클래스라 한다
*/

/*
접근 지정자
- Public:
	- 이 키워드 안에 있는 멤버는 클래스 내외부에서 자유롭게 접근 가능
- Protected:
	- 이 키워드 안에 있는 멤버는 상속된 클래스에서만 자유롭게 접근 가능
- Private:
	- 이 키워드 안에 있는 멤버는 클래스 자신에게서만 자유롭게 접근 가능
*/

/*
멤버변수와 멤버함수
- 자식 클래스는 부모클래스의 상속받은 모든 멤버변수와 멤머함수를 활용할 수 있으며 외부에서도 활용할 수 있다
*/

class Animal {
public:
	int legs;
	
	/*
	파라미터가 있는 생성자
	- 파라미터가 있는 생성자를 지정해주게 되면 자식클래스에서는 부모클래스의 생성자를 호출해줘야 한다
	- 부모클래스의 생성자를 실행하려면 파라미터가 있어야 하기 때문이다
	*/
	Animal(int legs) {
		this->legs = legs;
	}

	void print() {
		printf("다리 개수 : %d\n", legs);
	}
};

class Person : public Animal {
	// 상속 받을시 다음과 같이 작성
public:
	char name[20];

	/*
	생성자의 실행순서
	- 자식클래싀의 생성자를 호출하게 되면 자식클래스는 기본적으로 부모클래스의 '기본 생성자'를 호출하게 된다
	- 자식클래스의 생성자가 호출되기 직전 자동으로 호출되며 부모클래스의 생성자가 호출된 이후 자식 클래스의 생성자가 호출된다
	*/
	Person() : Animal(2){
		strcpy(name, "이서용");
	}
	
};

/*
클래스의 다형성(Polymorphism)
- 다형성은 '여러 가지 형태를 가질 수 있는 능력'을 의미
- OOP에서는 하나의 인터페이스(함수 이름)가 서로 다른 객체에서 각기 다른 방식으로 동작하는 것을 말한다
- 주로 오버라이딩(Overriding) 과 오버로딩(Overloading) 을 통해 구현됨
	- 오버라이딩(Overriding): 부모 클래스의 메서드를 자식 클래스에서 재정의하는 것
	- 오버로딩(Overloading): 같은 이름의 함수를 매개변수의 타입이나 개수를 다르게 하여 여러 개 정의하는 것

*/
class Dog : public Animal {
public:

	Dog() : Animal(4) {

	}
};

int main() {

	Person* p = new Person;
	p->print();

	Dog* d = new Dog;
	d->print();
	
	p = (Person*)d; // 형변환 예시
	p->print();

	return 0;
}