#include "main_header.h"
#include "person.h"

Person::Person(const char* Number, const char* person_name) : Animal(2, person_name)
{
	strcpy(this->Number, Number);
}

void Person::printinfo() {
	printf("��� �̸� : %s\n", name);
	printf("���� ��ȣ : %s\n", Number);

}