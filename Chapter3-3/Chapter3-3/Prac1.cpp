#include "Header.h"

int Number = 1;

class Employee {
public:
	int no;
	char name[20];
	int gender;
	char rank[20];

	Employee(char* name, int gender, char* rank) {
		strcpy(this->name, name);
		this->gender = gender;
		strcpy(this->rank, rank);
		this->no = Number;
		Number++;
	}

	void PrintInfo()
	{
		printf("��� ��ȣ : %d\n", no);
		printf("��� �̸� : %s\n", name);
		printf("��� ���� : %s\n", gender == 1 ? "����" : "����");
		printf("��� ��ȣ : %s\n\n", rank);

	
	}
};

int GetInt(const char* Prompt) {
	int input;
	printf("%s", Prompt);
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &input);
	return input;
}

//�Լ� ���� �� �޸� ����
char* GetChar(const char* Prompt) {
	char* input = new char[100];
	printf("%s", Prompt);
	fseek(stdin, 0, SEEK_END);
	scanf("99[^\n]s", input);

	return input;

}

// 1. ��� ����
// 2. ��� �߰�
// 3. ��� ����
// 4. ���α׷� ����
int main() {

	Employee* employee[100];
	int count = 0;

	while (true)
	{
		int input;
		printf("����� �Է��ϼ���\n");
		printf("1. ������� 2. ����߰� 3. ������� 4.���α׷� ���� : ");
		fseek(stdin, 0, SEEK_END);
		scanf("%d", &input);

		if (input == 1)
		{
			for (int i = 0; i < count; i++)
			{
				employee[i]->PrintInfo();
			}
		}
		else if (input == 2)
		{
			char* name = GetChar("������� �Է����ּ��� : ");
			int gender = GetInt("������ �Է����ּ��� [1. ����, 2. ����] : ");
			char* rank = GetChar("������ �Է����ּ��� : ");

			Employee* e = new Employee(name, gender, rank);
			delete[] name;
			delete[] rank;

			employee[count] = e;
			count++;
		}
		else if (input == 3)
		{

		}
		else if (input == 4)
		{
			printf("���α׷��� �����մϴ�\n");
			break;
		}
		else
		{
			printf("�߸� �Է��߽��ϴ�\n");
		}
	}
	

	return 0;
}