#include "main_header.h"
#include "Animal.h"

// Ŭ������ ��� �Լ� �и� ����
Animal::Animal(int legs, const char* name)
 {
	 this->legs = legs;
	 strcpy(this->name, name);
	}

void Animal::printinfo()
{
	printf("�ٸ� : %d\n", legs);
	printf("�̸� : %s\n", name);
}