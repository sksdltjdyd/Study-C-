#include <cstdio>
#include <iostream>

struct Marine
{
	int hp;
};

int main() {
	std::cout << "Hello, World!" << std::endl;

	Marine* m = new Marine;// c++������ new �����ڸ� ����Ͽ� ��ü�� �������� �����Ѵ�
	delete m; // �������� ������ ��ü�� �ݵ�� delete�� �޸𸮸� �����ؾ� �Ѵ�

	int* arr = new int[10]; // ���� �迭 ����
	delete[] arr; // ���� �迭�� delete[]�� �޸𸮸� �����ؾ� �Ѵ�

	return 0;
}