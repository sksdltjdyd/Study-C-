// #pragma once // Ŭ���� �ߺ����Ǹ� ���� ��ũ��. �׷��� ǥ�������� �ƴϴ�

// �ߺ��� �����ϴ� ��ũ�� ǥ�� �ڵ�
#ifndef __ANIMAL_H__
#define __ANIMAL_H__



class Animal
{
public:
	int legs;
	char name[50];
	Animal(int legs, const char* name);

	void printinfo();
};

#endif // !__ANIMAL_H__