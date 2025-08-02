#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

/*
	Bitwise 연산
	**비트 연산(Bitwise Operation)**은 숫자를 십진수가 아닌, 컴퓨터가 실제로 데이터를 저장하는 단위인 비트(bit) 수준에서 직접 조작하는 연산
	- 쉽게 말해, 숫자 13을 1101이라는 0과 1의 조합으로 보고, 각 자리의 비트를 하나씩 제어하는 방식.이는 매우 빠르고 메모리를 효율적으로 사용할 수 있어 저수준 프로그래밍이나 최적화에 필수
	- 비트를 기준으로 논리연산을 하는것을 비트와이즈 연산이라고 한다
	- 비트와이즈 and : & 연산자를 활용한다
	- 비트와이즈 or : | 연산자를 활용한다
	- 왼쪽 쉬프트 : << 연산자를 활용한다
	- 오른쪽 쉬프트 : >> 연산자를 활용한다
	*/

/*
순수(pure) 함수
- 몸체가 없는 가상 함수를 의미
- 선언만 존재하고 구 동작을 자식 클래스에서 구현해야 한다
*/

/*
프로그램의 실행 구조
- 프로그램은 실행될때 stack과 Haep 메모리가 존재하며 stack 영역에 존재하는 값들은 '정해진' 즉, 정적인 존재가 되며(함수 콜 스택에 따라 정해진 생명을 갖는다)
- Heap 영역에 존재하는 값들은 '유동적인' 즉, 동적인 존재가 된다(생명주기가 해제될때까지 유지된다)
*/

class Animal
{
public:
	char name[100];

	Animal(const char* name) {
		strcpy(this->name, name);
	}

	// 순수 가상 함수 선언
	virtual int getlegs() = 0;

	void printinfo() {
		// 순수 가상 함수 값 출력
		printf("%s, %d\n", name, getlegs());
	}
};

class Person : public Animal {
public:
	Person(const char* name) : Animal(name) {}
	
	// 순수 가상함수 정의
	virtual int getlegs() {
		return 2;
	}
};

class Dog : public Animal {
public:
	Dog() : Animal("개") {}
	
	// 순수 가상함수 정의
	virtual int getlegs() {
		return 4;
	}
};


int main() {

	int v1 = 1;
	int v2 = 3;

	// 두 8비트 숫자를 비교했을때 나오는 숫자. or 연산을 하면 1, 0 중 아무거나 나와도 상관없으니 1이 나온다
	// 두 비트가 모두 1일 때만 결과가 1
	// 용도: 마스킹(Masking). 특정 비트가 켜져 있는지(1인지) 확인할 때 주로 사용
	int bitwise_or = v1 | v2;
	printf("%d\n", bitwise_or);

	// 두 8비트 숫자를 비교했을때 나오는 숫자. and 연산을 하면 1, 0 겹치는 부분이 없어 0이 나오게 된다
	// 두 비트 중 하나라도 1이면 결과가 1
	// 용도: 비트 켜기. 특정 위치의 비트를 1로 만들 때 사용
	int bitwise_and = v1 & v2;
	printf("%d\n", bitwise_and);

	// 비트를 지정한 횟수만큼 왼쪽 또는 오른쪽으로 이동
	// << (왼쪽 시프트): 비트를 왼쪽으로 이동
	// a << n은 a * 2ⁿ와 거의 동일한 효과
	int shif_l = v2 << 1;
	printf("%d\n", shif_l);

	// >> (오른쪽 시프트): 비트를 오른쪽으로 이동
	// a >> n은 a / 2ⁿ와 거의 동일한 효과
	int shift_r = v2 >> 1;
	printf("%d\n", shift_r);

	Person* p = new Person("서용");
	p->printinfo();

	Dog* d = new Dog();
	d->printinfo();

	return 0;
}