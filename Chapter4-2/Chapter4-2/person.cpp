#include "main_header.h"
#include "person.h"

Person::Person(const char* Number, const char* person_name) : Animal(2, person_name)
{
	strcpy(this->Number, Number);
}

void Person::printinfo() {
	printf("사람 이름 : %s\n", name);
	printf("고유 번호 : %s\n", Number);

}