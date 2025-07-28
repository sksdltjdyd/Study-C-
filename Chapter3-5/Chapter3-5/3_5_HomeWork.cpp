#include "Header.h"

class Matrix {
public:
	float x1;
	float x2;
	float x3;
	float y1;
	float y2;
	float y3;
	float z1;
	float z2;
	float z3;

	Matrix() {
		x1 = 0;
		x2 = 0;
		x3 = 0;
		y1 = 0;
		y2 = 0;
		y3 = 0;
		z1 = 0;
		z2 = 0;
		z3 = 0;
	}

	Matrix(float x1, float x2, float x3, float y1, float y2, float y3, float z1, float z2, float z3) {
		this->x1 = x1;
		this->x2 = x2;
		this->x3 = x3;
		this->y1 = y1;
		this->y2 = y2;
		this->y3 = y3;
		this->z1 = z1;
		this->z2 = z2;
		this->z3 = z3;
	}

	void print() {
		printf("%.2f, %.2f, %.2f\n", x1, x2, x3);
		printf("%.2f, %.2f, %.2f\n", y1, y2, y3);
		printf("%.2f, %.2f, %.2f\n", z1, z2, z3);
	}
};

Matrix operator+(Matrix& v1, Matrix& v2) {
	return Matrix(v1.x1 + v2.x1, v1.x2 + v2.x2, v1.x3 + v2.x3, v1.y1 + v2.y1, v1.y2 + v2.y2, v1.y3 + v2.y3, v1.z1 + v2.z1, v1.z2 + v2.z2, v1.z3 + v2.z3);
}

int main() {

	Matrix m1 = Matrix(1, 2, 3, 4, 5, 6, 7, 8, 9);
	Matrix m2 = Matrix(4, 5, 6, 7, 8, 9, 10, 11, 12);

	Matrix m3 = m1 + m2;
	m3.print();

	return 0;
}