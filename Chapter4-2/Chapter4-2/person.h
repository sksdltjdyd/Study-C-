// #pragma once // Ŭ���� �ߺ����Ǹ� ���� ��ũ��. �׷��� ǥ�������� �ƴϴ�
// �ߺ��� �����ϴ� ��ũ�� ǥ�� �ڵ�
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


