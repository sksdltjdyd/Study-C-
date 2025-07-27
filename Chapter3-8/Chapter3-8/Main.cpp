#include "Header.h"

/*
������(Enumeration)
- �������̶� ���α׷��Ӱ� ���α׷����� �� �� �������� ���� ź���� ������ ����
- ���� �츮�� int��� �Ͽ� ���� �� �� ������ �̴� ������ ���ģȭ���̸� ���ģȭ���̶� ���� ������Դ� ������ �����ϴ� ���̴�
*/

/*
enum�� ����
- �Ϲ����� ������ enum
- Ŭ���� ������ enum
- ��ȭ�� enum class Ÿ���� enum
*/

// �������� �⺻����
// �̳� Ŭ������ ����ϴ� ������ �Ȱ��� �̸��� ������ �����Ͱ� �ΰ��� �̳ѿ��� ������ �� ��ǻ�Ͱ� �ν��� ����� ���� ���ɼ��� �ֱ� �����̴�
enum class Day
{
	Sun, Mon, Tue, Wed, Thur, Fri, Sat
};

/*��
Enum�� Switch
- enum�� ���������� integer�� ���ư��� �ֱ� ������ switch������ ������ ���谡 �ִ�
- Ư����Ȳ������ enum�� switch�� Ȱ���ϸ� if~else ������ ���� �� ���ϰ� ����� ������ �� �� �ְ� �ȴ�
*/
class Calender {
public:
	enum Month
	{
		JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
		// ���ڷ� �������൵ ������. �ֳ��ϸ� ���������� integer�� ���ư��� �ֱ� ����
	};

};



/*
���¸� ��Ÿ���� ���
- ���� ������ �������� ���¸� ���� �� �ִ�
- ���� ��� Playing, Paused, Win, Lose�� �������� ���°� ���� �� �ְ� �� ���¸� ��Ÿ���� ������� enum�� ���� Ȱ���ϰ� �ȴ�
*/

enum Gender
{
	Male, Female
};
class Student
{
public:
	char name[10];
	int stu_num;
	Gender gender;

	Student(const char* name, int stu_num, Gender gender) {
		strcpy(this->name, name);
		this->stu_num = stu_num;
		this->gender = gender;

	}

	void print() {
		printf("�̸� : %s\n", name);
		printf("�л���ȣ : %d\n", stu_num);
		printf("���� : %s\n", gender == Gender::Male ? "����" : "����");
	}

};

int main() {
	
	// ������ ������ Ŭ������ ���� �Լ��� �������� �⺻ ����
	Day d = Day::Mon;

	// �������� �̳��� �̳� ������ ���� ���� �ʿ䰡 ����
	Gender gender = Male;

	Student* s = new Student("�̼���", 1234, Gender::Male);
	s->print();

	// Ŭ���� ���ο� �����ϴ� �̳��� ����Ҷ� ���� �ڵ�
	Calender::Month m = Calender::Month::JAN;

	// ������ ���� �ۼ��Ͽ� Ŭ���� ���� �̳��� ����Ѵ�
	switch (m)
	{
	case Calender::Month::JAN:printf("1���Դϴ�"); break;
	case Calender::Month::FEB:printf("2���Դϴ�"); break;
	case Calender::Month::MAR:printf("3���Դϴ�"); break;
	case Calender::Month::APR:printf("4���Դϴ�"); break;
	case Calender::Month::MAY:printf("5���Դϴ�"); break;
	case Calender::Month::JUN:printf("6���Դϴ�"); break;
	case Calender::Month::JUL:printf("7���Դϴ�"); break;
	case Calender::Month::AUG:printf("8���Դϴ�"); break;
	case Calender::Month::SEP:printf("9���Դϴ�"); break;
	case Calender::Month::OCT:printf("10���Դϴ�"); break;
	case Calender::Month::NOV:printf("11���Դϴ�"); break;
	case Calender::Month::DEC:printf("12���Դϴ�"); break;
	default:
		break;
	}

	// enum�� ���������� integer�� ���ư��⿡ ���ڷ� ���´�
	printf("\n%d", m);
	
	return 0;
}