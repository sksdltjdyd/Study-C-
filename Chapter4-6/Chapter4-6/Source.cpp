#include "Header.h"

#define MYVALUE 100

// �ҽ����Ͽ��� �������� ���� Ȱ��
int myint = 100;

int main() {

	/*
	const
	- const�� ����̴�
	- �����°��� ���α׷��� �����ϰ� ������ ���� ���� ������ �ʴ� ���� �ǹ��Ѵ�
	- ������ ������ �ǹ̷μ��� const�� define ��ũ���̸�, const Ű���带 �̿��� ���� ������ ��� ������ '�������'�� ���� �ִ� �����̸� ���������� ���α׷� ���ο� �����ִ� ���� �ƴϴ�
	*/

	// ������ ����, �������� ���
	int value1 = MYVALUE;
	const int value2 = MYVALUE;

	printf("%d\n", value1);

	int input;
	printf("age : ");
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &input);

	Person* p = new Person(input);
	printf("age = %d\n", p->age);

	Myclass* c = new Myclass();
	// static ���� �ҷ��ͼ� �� �Ҵ�
	Myclass::b = 100;

	c->foo();
	// ���� �Լ� ��� ���
	// c->goo();
	Myclass::goo(); // �̰� �� �´� ���

	printf("%d", myint);

	return 0;
}

void Myclass::foo() {
		// ���̳��� �Լ��� �ڱ� �ڽ��� �ν��Ͻ��� �����Ѵ�
		a = 100;
		this->a = 200;
		b = 300; // ���̳��� �Լ��� static ������ �������� ������ �����ϴ�
		printf("foo\n");
	}

void Myclass::goo() {
	// ���� �Լ��� ���� ������ ������ �ν��Ͻ��� �ʿ������� �ʴ�
		// this Ű���尡 �ʿ� ����. ��ü�� ���� �����̴�
		// a = 100; --> �Ұ���. ��ü�� �Ǵ� Ŭ���� �ȿ� �ν��Ͻ��� �ʿ� ���� ���� ���� �ʱ� ������
		// this->a = 200; --> ��������
	b = 100; // static �������� ���� ����
	printf("goo\n");
}

// ������ : static ������ ���� ���� ���Ͽ��� ��������� �Ѵ�
int Myclass::b = 100;