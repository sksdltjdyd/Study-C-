#include "Header.h"

/*
�����ε�(Overload)
- ������ �̸��� ���� ������ �ٸ� ������ �ϰ� ����°�. ��ǥ������ �Լ� �����ε尡 �ִ�
- �Լ� �����ε带 ���� �̸��� ������ ���� �ٸ� �Ķ���Ϳ� ���� ������ ������ ���� �������� �� �ִ�
*/

/*
�������̵�(Override)
- ��������Ʈ �Ǵ� �������̵��� �θ�Ŭ������ �Լ��� ���Ǹ� �ڽ� Ŭ�������� ���� ����°��� �ǹ��Ѵ�
*/

/*
Ŭ���������� �Լ� �����ε�
- �̴� Ŭ���� ����Լ������� �����ϰ� �ۿ��ϰ� �ȴ�. 
- ���� Ŭ���� �����ڿ� ���ؼ��� �����ϰ� �ۿ��Ҽ� �ִµ� Ŭ���� �����ڵ� ����� �Լ��� �� �� �ְ� Ŭ���� �����ڵ� �Ķ������ Ÿ�԰� ������ ���� � �����ڸ� ȣ���� �� ������ ������ �� �ֱ� �����̴�
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

	// �������̵��� ����. �����̸��� �Լ��� ����� ������ ������ �ϴ°�
	void print() {
		printf("%d", c);
	}
};

/*
�����ڿ����� �����ε�
- ������ ���� �����ε��� �� �� �ִµ� ���� Ŭ������ �ƴ� Stack ��� Ŭ���� �ν��Ͻ��� �����ϴ� �����ڸ� �����ε� �� �� �ִ�
- ������ �����ε��� ���� ���� ���� ������ �����ε��� ���� �츮�� ���Ǽ��迡�� ���°Ͱ� ���� ǥ���� ��ǻ�Ϳ��� �Է� �� �� �ִٴ� ���̴�
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

// ������ �����ε� ����
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

// �Լ��� �Լ���� �Լ� �Ķ���͸� ��� ������ ���̴�
int foo(int a) {

	return 0;
}

// �Լ����� ������ ������ �ִ� �Ķ���� ������ ���� �ٸ� �Լ��� ������. �̰��� �Լ� �����ε��̴�
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
	// ������ �����ε��� �����߱⿡ ��� �����ϴ�
	Vector v3 = v1 + v2;

	v3.prinf();

	Vector3 v = Vector3(10, 20, 30);
	Vector3 result = v * 10;
	result.print();

	return 0;
}