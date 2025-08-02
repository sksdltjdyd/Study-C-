#include "main_header.h"
#include "Animal.h"

// 클래스와 멤버 함수 분리 예시
Animal::Animal(int legs, const char* name)
 {
	 this->legs = legs;
	 strcpy(this->name, name);
	}

void Animal::printinfo()
{
	printf("다리 : %d\n", legs);
	printf("이름 : %s\n", name);
}