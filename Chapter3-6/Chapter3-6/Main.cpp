#include "Header.h"

/*
C++에서 이해하기 어려운 동작
- C++에서 이해하기 어려운 동작이 있는 이유는 거의 대부분 '성능'때문에 그런 동작을 보이게 된다
*/

/*
가상함수
- 오버라이딩 할때, 부모클래스의 함수에서 Virtual 키워드를 추가하게 되면 정상적으로 우리가 원하는 오버라이드된 함수를 찾아가서 실행하게 된다
- 이렇게 Virtual을 추가해주어야 하는 이유는 함수가 Virtual이 아닐 때 더 빠른 실행속도가 보장되기 떄문이다
*/

class Animal
{
public:
	int legs;
	char* name;
	Animal(int legs, const char* name) {
		this->legs = legs;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	// 소멸자 앞에 버추얼을 붙이는 이유는 오버라이딩시 생기는 메모리 누수와 같은 문제를 해결하기 위해서다. 무조건 붙여야 한다. 이게 관행이다
	virtual ~Animal()
	{
		delete[] name;
	}
	// 버추얼을 붙임으로써 메인 함수에서 실행하려는 의도를 정확하게 찾아낸다. 버추얼 키워드가 없을 시 주소값(실제값)의 변화가 없어서 실행이 제대로 안될 가능성이 있다
	virtual void printinf() {
		printf("이름 : %s\n", name);
		printf("다리개수 : %d\n", legs);
	}

};

class Human : public Animal {
public:
	char* legitnum;
	Human(const char* legitnum) : Animal(2, "사람") {
		this->legitnum = new char[strlen(legitnum) + 1];
		strcpy(this->legitnum, legitnum);
	}

	// 소멸자 앞에 버추얼을 붙이는 이유는 오버라이딩시 생기는 메모리 누수와 같은 문제를 해결하기 위해서다. 무조건 붙여야 한다. 이게 관행이다
	virtual ~Human()
	{
		delete[] legitnum;
	}
	// 버추얼을 붙임으로써 메인 함수에서 실행하려는 의도를 정확하게 찾아낸다. 버추얼 키워드가 없을 시 주소값(실제값)의 변화가 없어서 실행이 제대로 안될 가능성이 있다
	virtual void printinf() {
		printf("이름 : %s\n", name);
		printf("주민번호 : %s\n", legitnum);
	}

};

int main() {

	Human* h = new Human("1234-5678");
	Animal* a = h;

	Animal* a2 = new Human("345322-23423");
	a->printinf();
	// 자식 클래스의 소멸자가 호출되지 않는 문제 발생 가능성이 있다
	delete a2;

	return 0;
}