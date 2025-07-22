#include "Header.h"



class Employee {
public:
	int countNum = 1;
	int no;
	char name[20];
	int gender;
	char rank[20];

	Employee(char* name, int gender, char* rank) {
		strcpy(this->name, name);
		this->gender = gender;
		strcpy(this->rank, rank);
		this->no = countNum;
		countNum++;
	}

	void PrintInfo()
	{
		printf("사원 번호 : %d\n", no);
		printf("사원 이름 : %s\n", name);
		printf("사원 성별 : %s\n", gender == 1 ? "남자" : "여자");
		printf("사원 번호 : %s\n\n", rank);

	
	}
};

int GetInt(const char* Prompt) {
	int input;
	printf("%s", Prompt);
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &input);
	return input;
}

//함수 실행 후 메모리 해제
char* GetChar(const char* Prompt) {
	char* input = new char[100];
	printf("%s", Prompt);
	fseek(stdin, 0, SEEK_END);
	scanf("99[^\n]s", input);
	return input;

}

// 1. 사원 보기
// 2. 사원 추가
// 3. 사원 삭제
// 4. 프로그램 종료
int main() {

	Employee* employee[100];
	int count = 0;

	while (true)
	{
		int input;
		printf("명령을 입력하세요\n");
		printf("1. 사원보기 2. 사원추가 3. 사원삭제 4.프로그램 종료 : ");
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
			char* name = GetChar("사원명을 입력해주세요 : ");
			int gender = GetInt("성별을 입력해주세요 [1. 남자, 2. 여자] : ");
			char* rank = GetChar("직급을 입력해주세요 : ");

			Employee* e = new Employee(name, gender, rank);
			delete[] name;
			delete[] rank;

			employee[count] = e;
			count++;
		}
		else if (input == 3)
		{
			int number = GetInt("사원 번호를 입력해주세요 : ");
			int deleteindex = -1;
			for (int = 0; i < count; i++)
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
			printf("삭제가 완료됐습니다");
		}
		else if (input == 4)
		{
			printf("프로그램을 종료합니다\n");
			break;
		}
		else
		{
			printf("잘못 입력했습니다\n");
		}
	}
	

	return 0;
}