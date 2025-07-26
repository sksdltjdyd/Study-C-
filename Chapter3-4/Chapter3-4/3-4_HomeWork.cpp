#include "Header.h"

class Weapon {
public:
	char* name;
	int atk;
	int range;
	int price;

	Weapon(const char* name, int atk, int range, int price) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->atk = atk;
		this->range = range;
		this->price = price;
	}

	~Weapon()
	{
		delete[] name;
	}

	void Print() {
		printf("�̸� : %s\n", name);
		printf("���ݷ� : %d\n", atk);
		printf("�����Ÿ� : %d\n", range);
		printf("���� : %d\n\n", price);
	}

};

class ShotSword : public Weapon {
public:
	ShotSword() : Weapon("���ҵ�", 10, 5, 500) {

	}
};

class LongSword : public Weapon {
public:
	LongSword() : Weapon("�ռҵ�", 20, 10, 2000) {

	}
};

class Hammer : public Weapon {
public:
	Hammer() : Weapon("�ظ�", 30, 7, 3000) {

	}
};
int main() {

	Weapon* W[10];
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		switch (rand() % 3) {
		case 0:
			W[i] = new ShotSword();
			break;
		case 1:
			W[i] = new LongSword();
			break;
		case 2:
			W[i] = new Hammer();
			break;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		W[i]->Print();
	}
	return 0;
}