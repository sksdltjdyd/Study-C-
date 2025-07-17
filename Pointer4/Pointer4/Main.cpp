#include "Header.h"

struct Marine
{
	int hp = 40;
	int mp = 0;
};

/*
�Լ� �Ķ������ ������
- �Ķ������ �����ʹ� �ܼ��� ������ �ּҰ��� �ޱ� ������ �� ������ �迭 ������ �ޱ� ������ ���� �ִ�
- �����ϴ� ����� ���� �迭�� ��� �迭�� ������ �˷��ִ� ������ ���� �޴´�
*/

void foo(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = i * 10; // �迭�� �� ��ҿ� ���� �Ҵ�
	}
}

void goo(int* arr) {
	// �ܼ� ���� �����ϴ� �Լ�
}

void hoo(const char* str) {
	// const char*�� ���ڿ��� �б� �������� ���
	// str[0] = 'A'; // ���� �߻�: const�� ����� ���ڿ��� ������ �� ����.
	printf("String: %s\n", str);
}

int main() {
	
	int* p = 0; // 0���� �ʱ�ȭ. C++11���� nullptr�� ����ϴ� ���� ����.
	int* P = nullptr; // nullptr�� �ʱ�ȭ. ������ �����Ҷ� ���� �Ҵ����� ������ �����Ⱚ�� ���Ƿ� �����ؾ� �Ѵ�.

	p = (int*)malloc(sizeof(int)); // malloc�� ����Ͽ� �޸� �Ҵ�. C++������ new�� ����ϴ� ���� ����.
	*p = 10; // �Ҵ�� �޸𸮿� �� �Ҵ�. p�� ����Ű�� �޸𸮿� 10�� �����Ѵ�.
	free(p); // �Ҵ�� �޸� ����. C++������ delete�� ����ϴ� ���� ����.

	/*
	�迭 �ʱ�ȭ
	- �迭�� ��� ���� 0���� �ʱ�ȭ�Ϸ��� ������ ���� �� �� �ִ�.
	- int arr[10] = { 0, }; -> �迭�� ��� ���� 0���� �ʱ�ȭ
	- int arr[10] = {}; -> �迭�� ��� ���� 0���� �ʱ�ȭ
	- int* arr[10] = { nullptr, }; -> ������ �迭�� ��� ���� nullptr�� �ʱ�ȭ
	*/
	
	int* arr[10] = { nullptr, };

	Marine* marine[40] = { nullptr, };
	
	for (int i = 0; i < 40; i++)
	{
		marine[i] = (Marine*)malloc(sizeof(Marine));
		marine[i]->hp = 40;
		marine[i]->mp = 10;
	}

	for (int i = 0; i < 40; i++)
	{
		printf("Marine[%d] - HP: %d, MP: %d\n", i, marine[i]->hp, marine[i]->mp);
		free(marine[i]); // �Ҵ�� �޸� ����
	}

	/*
	�������� ������
	- �������� �����ʹ� �����͸� ����Ű�� �������̴�.
	- �������� �����͸� ����ϸ� ������ �迭�̳� ���� �Ҵ�� �迭�� ���� ������ �� �ִ�
	- �������� �����ʹ� ���� �����ϸ� ������ �迭�� ����ϴ�.
	- ���� ���, Marine** marinePtr;�� Marine* marinePtr[20];�� ����ϴ�
	*/

	Marine** marinePtr = (Marine**)malloc(sizeof(Marine*) * 40); // Marine ������ �迭�� ���� �Ҵ�
	for (int i = 0; i < 40; i++)
	{
		marinePtr[i] = (Marine*)malloc(sizeof(Marine)); // �� Marine �����Ϳ� ���� �޸� �Ҵ�
		marinePtr[i]->hp = 50;
		marinePtr[i]->mp = 10;
	}

	hoo("Hello, World!"); // ���ڿ��� �б� �������� ���
	
	char* str = (char*)malloc(20 * sizeof(char)); // ���� �Ҵ�� ���ڿ�
	strcpy(str, "Hello, Pointer!"); // ���ڿ� ����
	hoo(str); // ���ڿ��� �б� �������� ���

	// void* : ���̵� ������. ���̵� �����ʹ� � Ÿ���� �����͵��� ���� �� �ִ� �������̴�. 
	return 0;
}