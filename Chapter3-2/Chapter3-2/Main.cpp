#include <cstdio>

struct Zerg
{
	int hp = 25;
	int atk = 5;
	float movement;
	char name[20];

	void print() {}
	void work() {}
	// �̷��� �Ӽ��� �ൿ�� �����°��� Abstraction, �߻�ȭ�� �ϴµ� ��ü���� ���α׷����� �ٽ� ���� �� �ϳ��̴�
	// Abstraction�� ��ü�� �Ӽ��� �ൿ�� �����Ͽ� ��ü�� �ܼ�ȭ�ϰ�, �ٽ� ����(�ʿ��� �Ӽ�)�� ����Ͽ� ���⼺�� ���̴� ���� �ǹ��Ѵ�
};

struct Marine
{
	int hp = 40;
	int atk = 6;
	float movement;
	char name[20];
	void attackto() {}
	void Hold() {}
	// Marine�� Zerg���� �ٸ� �Ӽ��� �ൿ�� ������, ��ü���� ���α׷��ֿ����� �̷��� ��ü�� Ŭ������ �����Ѵ�
	// Ŭ������ ��ü�� �Ӽ��� �ൿ�� �����ϴ� Ʋ(template)��, ��ü�� ������ �� ���ȴ�

int main() {
	/*
	OOP
	- Object-Oriented Programming���� ��ü ���� ���α׷����� �ǹ��Ѵ�.
	- ��ü ���� ���α׷����� ��ü�� �߽����� ���α׷��� �����ϴ� ���α׷��� �з������̴�.
	*/
	return 0;
}