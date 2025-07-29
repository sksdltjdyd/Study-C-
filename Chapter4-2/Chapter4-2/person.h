// #pragma once // 클래스 중복정의를 막는 매크로. 그러나 표준형식은 아니다
// 중복을 방지하는 매크로 표준 코드
#ifndef __PERSON_H__
#define __PERSON_H__

#include "Animal.h"

class Person :Animal
{
public:
	int legs;
	char person_name[50];
	char Number[10];

	Person(const char* Number, const char* person_name);

	void printinfo();
};

#endif // !__Person_H__


