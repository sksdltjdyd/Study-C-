#include "Header.h"

/*
C++의 많은 개념
- C++에는 많은 개념이 있지만 실제로 사용되는 개념은 많이 없다
- 따라서 현대 많은 프로그래밍 언어는 이중에서 많이 쓰고 필수적인 개념만 차용하여 프로그래밍 언어를 구성하고 있으며 C++을 사용하여 개발하는 개발자도 복잡하고 굳이 필요없는 개념을 활용하여 개발하지 않는다
- 대표적인것이 상속 접근지정자(private, protected...)와 다중상속이다
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

	
	virtual ~Animal()
	{
		delete[] name;
	}
	
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

	
	virtual ~Human()
	{
		delete[] legitnum;
	}
	
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
	delete a2;

	return 0;
}