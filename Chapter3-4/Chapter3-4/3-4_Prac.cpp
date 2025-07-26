#include "Header.h"

class Monster {
public:
	char* name;
	int hp;
	int atk;
	int range;
	int speed;

	Monster(const char* name, int hp, int atk, int range, int speed) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->hp = hp;
		this->atk = atk;
		this->range = range;
		this->speed = speed;
	}
	
	~Monster()
	{
		delete[] name;
	}

	void Print() {
		printf("이름 : %s\n", name);
		printf("체력 : %d\n", hp);
		printf("공격력 : %d\n", atk);
		printf("사정거리 : %d\n", range);
		printf("이동속도 : %d\n\n", speed);
	}

};

class Goblin : public Monster {
public:
	Goblin() : Monster("고블린", 60, 5, 10, 10) {

	}
};

class Oak : public Monster {
public:
	Oak() : Monster("오크", 80, 10, 12, 10) {

	}
};

class Slime : public Monster {
public:
	Slime() : Monster("슬라임", 100, 3, 5, 4) {

	}
};

class SkullArcher : public Monster {
public:
	SkullArcher() : Monster("해골궁수", 60, 20, 50, 3) {

	}
};

int main() {
	
	Monster* M[10];
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		switch (rand() % 4) {
		case 0:
			M[i] = new Goblin();
			break;
		case 1:
			M[i] = new Oak();
			break;
		case 2:
			M[i] = new Slime();
			break;
		case 3:
			M[i] = new SkullArcher();
			break;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		M[i]->Print();
	}
	return 0;
}