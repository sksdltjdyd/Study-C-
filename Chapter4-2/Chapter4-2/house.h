#ifndef __HOUSE_H__
#define __HOUSE_H__

// Ŭ���� ���� ���� : ��� �ִ����� ������ animal�̶� Ŭ������ ��� ����
class Animal;

class House
{
public:
	Animal* animal;

	void SetAnimal(Animal* a);
};

#endif // !__HOUSE_H__