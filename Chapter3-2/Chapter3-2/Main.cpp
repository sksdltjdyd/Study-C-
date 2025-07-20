#include <cstdio>


/*
Inheritance(상속)
- 객체 지향 프로그래밍의 핵심 개념 중 하나로, 기존 클래스를 기반으로 새로운 클래스를 정의하는 방법이다
- 상속을 통해 기존 클래스의 속성과 행동을 재사용하고, 새로운 속성과 행동을 추가할 수 있다
- 상속은 코드의 재사용성을 높이고, 유지보수를 용이하게 한다
*/
struct Zerg
{
	int hp = 25;
	int atk = 5;
	int hprgeneration = 1; // 체력 회복 속도
	float movement;
	char name[20];
	bool Burrow = false; // 잠복 상태 여부

	void attackto() {}
	// 이렇게 속성과 행동을 나누는것을 Abstraction, 추상화라 하는데 객체지향 프로그래밍의 핵심 개념 중 하나이다
	// Abstraction은 객체의 속성과 행동을 정의하여 객체를 단순화하고, 핵심 내용(필요한 속성)만 사용하여 복잡성을 줄이는 것을 의미한다
};

struct Zergling : public Zerg // Zerg 클래스를 상속받은 Zergling 클래스
{
	int atkSpeed = 1; // 공격 속도
	int atkRange = 1; // 공격 범위
	void attackto() {} // Zergling의 공격 행동
	void Hold() {} // Zergling의 대기 행동
	// 상속을 통해 Zerg의 속성과 행동을 재사용하고, 새로운 속성과 행동을 추가할 수 있다
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