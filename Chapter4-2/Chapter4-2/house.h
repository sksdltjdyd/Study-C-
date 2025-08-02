#ifndef __HOUSE_H__
#define __HOUSE_H__

// 클래스 전방 선언 : 어디 있는지는 모르지만 animal이란 클래스가 어딘가 존재
class Animal;

class House
{
public:
	Animal* animal;

	void SetAnimal(Animal* a);
};

#endif // !__HOUSE_H__