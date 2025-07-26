#include "Header.h"

/*
C++�� ���� ����
- C++���� ���� ������ ������ ������ ���Ǵ� ������ ���� ����
- ���� ���� ���� ���α׷��� ���� ���߿��� ���� ���� �ʼ����� ���丸 �����Ͽ� ���α׷��� �� �����ϰ� ������ C++�� ����Ͽ� �����ϴ� �����ڵ� �����ϰ� ���� �ʿ���� ������ Ȱ���Ͽ� �������� �ʴ´�
- ��ǥ���ΰ��� ��� ����������(private, protected...)�� ���߻���̴�
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

	
	virtual ~Human()
	{
		delete[] legitnum;
	}
	
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
	delete a2;

	return 0;
}