// #pragma once // 클래스 중복정의를 막는 매크로. 그러나 표준형식은 아니다

// 중복을 방지하는 매크로 표준 코드
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