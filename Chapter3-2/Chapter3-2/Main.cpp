#include <cstdio>

struct Zerg
{
	int hp = 25;
	int atk = 5;
	float movement;
	char name[20];

	void print() {}
	void work() {}
	// 이렇게 속성과 행동을 나누는것을 Abstraction, 추상화라 하는데 객체지향 프로그래밍의 핵심 개념 중 하나이다
	// Abstraction은 객체의 속성과 행동을 정의하여 객체를 단순화하고, 핵심 내용(필요한 속성)만 사용하여 복잡성을 줄이는 것을 의미한다
};

struct Marine
{
	int hp = 40;
	int atk = 6;
	float movement;
	char name[20];
	void attackto() {}
	void Hold() {}
	// Marine은 Zerg과는 다른 속성과 행동을 가지며, 객체지향 프로그래밍에서는 이러한 객체를 클래스로 정의한다
	// 클래스는 객체의 속성과 행동을 정의하는 틀(template)로, 객체를 생성할 때 사용된다

int main() {
	/*
	OOP
	- Object-Oriented Programming으로 객체 지향 프로그래밍을 의미한다.
	- 객체 지향 프로그래밍은 객체를 중심으로 프로그램을 구성하는 프로그래밍 패러다임이다.
	*/
	return 0;
}