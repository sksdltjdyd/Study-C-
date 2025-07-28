#include "Header.h"

/*
오버로드(Overload)
- 동일한 이름을 갖고 있지만 다른 동작을 하게 만드는것. 대표적으로 함수 오버로드가 있다
- 함수 오버로드를 통해 이름은 같지만 서로 다른 파라미터에 대해 각각의 동작을 따로 지정해줄 수 있다
*/

/*
오버라이드(Override)
- 오버라이트 또는 오버라이딩은 부모클래스의 함수의 정의를 자식 클래스에서 새로 덮어쓰는것을 의미한다
*/

/*
클래스에서의 함수 오버로딩
- 이는 클래스 멤버함수에서도 동일하게 작용하게 된다. 
- 또한 클래스 생성자에 대해서도 동일하게 작용할수 있는데 클래스 생성자도 어찌보면 함수라 할 수 있고 클래스 생성자도 파라미터의 타입과 갯수를 통해 어떤 생성자를 호출할 수 있을지 결정할 수 있기 때문이다
*/
class Student
{
public:
	int a = 3;
	int b = 4;
	int value;
	Student(){
		a = b;
		value = a + b;
	}

	Student(int a, int b) {
		this->a = a;
		this->b = b;
		value = a + b;
	}

	void print() {

		printf("%d\n", value);
	}


};

class vas : public Student {
public:
	int c = 3;

	vas(int c) : Student(2, 4){
		this->c = c;
	}

	// 오버라이드의 예시. 같은이름의 함수를 만들고 내용을 재정의 하는것
	void print() {
		printf("%d", c);
	}
};

/*
연산자에서의 오버로딩
- 연산자 또한 오버로딩을 할 수 있는데 동적 클래스가 아닌 Stack 기반 클래스 인스턴스에 동작하는 연산자를 오버로딩 할 수 있다
- 연산자 오버로딩의 가장 좋은 점은 연산자 오버로딩을 통해 우리가 현실세계에서 쓰는것과 같은 표현을 컴퓨터에게 입력 할 수 있다는 점이다
*/
class Vector {
public:
	float x;
	float y;

	Vector(float x, float y) {
		this->x = x;
		this->y = y;
	}

	Vector() {
		x = 0.0f;
		y = 0.3f;
	}

	void prinf(){

		printf("%.2f, %.2f\n", x, y);
	}
};

// 연산자 오버로딩 예시
Vector operator+(Vector& v1, Vector& v2) {
	return Vector(v1.x + v2.x, v1.x + v2.y);
}

class Vector3 {
public:
	float x; 
	float y;
	float z;

	Vector3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;

	}

	Vector3() {
		x = 0;
		y = 0;
		z = 0;
	}

	void print() {
		printf("%.2f, %.2f, %.2f", x, y, z);
	}

};

Vector3 operator*(Vector3& v1, float s) {
	return Vector3(v1.x * s, v1.y * s, v1.z * s);
}

// 함수는 함수명과 함수 파라미터를 모두 포함한 것이다
int foo(int a) {

	return 0;
}

// 함수명이 같더라도 가지고 있는 파라미터 개수에 따라 다른 함수로 읽힌다. 이것이 함수 오버로딩이다
int sum(int a, int b) {

	return a + b;
}

int sum(int a, int b, int c) {
	return a + b + c;
}

int sum(int a, int b, int c, int d) {
	return a + b + c + d;
}


int main() {

	Student* s1 = new Student();
	Student* s2 = new Student(5, 8);

	s1->print();
	s2->print();

	Vector v1 = Vector(100, 200);
	Vector v2 = Vector(1, 3);
	// 연산자 오버로딩을 지시했기에 사용 가능하다
	Vector v3 = v1 + v2;

	v3.prinf();

	Vector3 v = Vector3(10, 20, 30);
	Vector3 result = v * 10;
	result.print();

	return 0;
}