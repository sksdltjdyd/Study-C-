#include "Header.h"
int countNum = 1;

class Employee {
public:
	
	int no;
	char* name;
	int gender;
	char* rank;

	Employee(char* name, int gender, char* rank) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->gender = gender;
		this->rank = new char[strlen(rank) + 1];
		strcpy(this->rank, rank);
		this->no = countNum;
		countNum++;
	}

	~Employee() {
		delete[] name;
		delete[] rank;
		printf("�Ҹ��� ȣ��\n");
	}

	void PrintInfo()
	{
		printf("��� ��ȣ : %d\n", no);
		printf("��� �̸� : %s\n", name);
		printf("��� ���� : %s\n", gender == 1 ? "����" : "����");
		printf("��� ���� : %s\n\n", rank);
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
char* GetString(const char* Prompt) {
	char* input = new char[100];
	printf("%s", Prompt);
	fseek(stdin, 0, SEEK_END);
	scanf("%99[^\n]s", input);
	return input;

}


int main() {
	// 1. ��� ����
	// 2. ��� �߰�
	// 3. ��� ����
	// 4. ���α׷� ����

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
			char* name = GetString("������� �Է����ּ��� : ");
			int gender = GetInt("������ �Է����ּ��� [1. ����, 2. ����] : ");
			char* rank = GetString("������ �Է����ּ��� : ");

			Employee* e = new Employee(name, gender, rank);
			delete[] name;
			delete[] rank;

			employee[count] = e;
			count++;
		}
		else if (input == 3)
		{
			int number = GetInt("��� ��ȣ�� �Է����ּ��� : ");
			int deleteindex = -1;
			for (int i = 0; i < count; i++)
			{
				if (number == employee[i]->no) {
					delete employee[i];
					deleteindex = i;
				}
			}
			if (deleteindex >= 0)
			{
				for (int i = deleteindex; i < count - 1; i++)
				{
					employee[i] = employee[i + 1];
				}
			}
			count--;
			printf("������ �Ϸ�ƽ��ϴ�");
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