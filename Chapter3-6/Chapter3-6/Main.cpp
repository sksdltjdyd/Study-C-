#include "Header.h"

/*
C++���� �����ϱ� ����� ����
- C++���� �����ϱ� ����� ������ �ִ� ������ ���� ��κ� '����'������ �׷� ������ ���̰� �ȴ�
*/

/*
�����Լ�
- �������̵� �Ҷ�, �θ�Ŭ������ �Լ����� Virtual Ű���带 �߰��ϰ� �Ǹ� ���������� �츮�� ���ϴ� �������̵�� �Լ��� ã�ư��� �����ϰ� �ȴ�
- �̷��� Virtual�� �߰����־�� �ϴ� ������ �Լ��� Virtual�� �ƴ� �� �� ���� ����ӵ��� ����Ǳ� �����̴�
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

	// �Ҹ��� �տ� ���߾��� ���̴� ������ �������̵��� ����� �޸� ������ ���� ������ �ذ��ϱ� ���ؼ���. ������ �ٿ��� �Ѵ�. �̰� �����̴�
	virtual ~Animal()
	{
		delete[] name;
	}
	// ���߾��� �������ν� ���� �Լ����� �����Ϸ��� �ǵ��� ��Ȯ�ϰ� ã�Ƴ���. ���߾� Ű���尡 ���� �� �ּҰ�(������)�� ��ȭ�� ��� ������ ����� �ȵ� ���ɼ��� �ִ�
	virtual void printinf() {
		printf("�̸� : %s\n", name);
		printf("�ٸ����� : %d\n", legs);
	}

};

class Human : public Animal {
public:
	char* legitnum;
	Human(const char* legitnum) : Animal(2, "���") {
		this->legitnum = new char[strlen(legitnum) + 1];
		strcpy(this->legitnum, legitnum);
	}

	// �Ҹ��� �տ� ���߾��� ���̴� ������ �������̵��� ����� �޸� ������ ���� ������ �ذ��ϱ� ���ؼ���. ������ �ٿ��� �Ѵ�. �̰� �����̴�
	virtual ~Human()
	{
		delete[] legitnum;
	}
	// ���߾��� �������ν� ���� �Լ����� �����Ϸ��� �ǵ��� ��Ȯ�ϰ� ã�Ƴ���. ���߾� Ű���尡 ���� �� �ּҰ�(������)�� ��ȭ�� ��� ������ ����� �ȵ� ���ɼ��� �ִ�
	virtual void printinf() {
		printf("�̸� : %s\n", name);
		printf("�ֹι�ȣ : %s\n", legitnum);
	}

};

int main() {

	Human* h = new Human("1234-5678");
	Animal* a = h;

	Animal* a2 = new Human("345322-23423");
	a->printinf();
	// �ڽ� Ŭ������ �Ҹ��ڰ� ȣ����� �ʴ� ���� �߻� ���ɼ��� �ִ�
	delete a2;

	return 0;
}