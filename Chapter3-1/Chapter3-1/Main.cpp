#include <cstdio>
#include <iostream>

struct Marine
{
	int hp;
};

int main() {
	std::cout << "Hello, World!" << std::endl;

	Marine* m = new Marine;// c++에서는 new 연산자를 사용하여 객체를 동적으로 생성한다
	delete m; // 동적으로 생성한 객체는 반드시 delete로 메모리를 해제해야 한다

	int* arr = new int[10]; // 동적 배열 생성
	delete[] arr; // 동적 배열은 delete[]로 메모리를 해제해야 한다

	return 0;
}