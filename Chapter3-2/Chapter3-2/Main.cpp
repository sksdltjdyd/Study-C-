#include <cstdio>


/*
Inheritance(���)
- ��ü ���� ���α׷����� �ٽ� ���� �� �ϳ���, ���� Ŭ������ ������� ���ο� Ŭ������ �����ϴ� ����̴�
- ����� ���� ���� Ŭ������ �Ӽ��� �ൿ�� �����ϰ�, ���ο� �Ӽ��� �ൿ�� �߰��� �� �ִ�
- ����� �ڵ��� ���뼺�� ���̰�, ���������� �����ϰ� �Ѵ�
*/
struct Zerg
{
	int hp = 25;
	int atk = 5;
	int hprgeneration = 1; // ü�� ȸ�� �ӵ�
	float movement;
	char name[20];
	bool Burrow = false; // �ẹ ���� ����

	void attackto() {}
	// �̷��� �Ӽ��� �ൿ�� �����°��� Abstraction, �߻�ȭ�� �ϴµ� ��ü���� ���α׷����� �ٽ� ���� �� �ϳ��̴�
	// Abstraction�� ��ü�� �Ӽ��� �ൿ�� �����Ͽ� ��ü�� �ܼ�ȭ�ϰ�, �ٽ� ����(�ʿ��� �Ӽ�)�� ����Ͽ� ���⼺�� ���̴� ���� �ǹ��Ѵ�
};

struct Zergling : public Zerg // Zerg Ŭ������ ��ӹ��� Zergling Ŭ����
{
	int atkSpeed = 1; // ���� �ӵ�
	int atkRange = 1; // ���� ����
	void attackto() {} // Zergling�� ���� �ൿ
	void Hold() {} // Zergling�� ��� �ൿ
	// ����� ���� Zerg�� �Ӽ��� �ൿ�� �����ϰ�, ���ο� �Ӽ��� �ൿ�� �߰��� �� �ִ�
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