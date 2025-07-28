#include "Header.h"

/*
열거형(Enumeration)
- 열거형이란 프로그래머가 프로그래밍을 할 때 가독성을 위해 탄생한 데이터 형태
- 흔히 우리가 int라고 하여 값을 줄 수 있지만 이는 굉장히 기계친화적이며 기계친화적이라 함은 사람에게는 굉장히 불편하는 것이다
*/

/*
enum의 종류
- 일반적인 전역적 enum
- 클래스 내부의 enum
- 강화된 enum class 타입의 enum
*/

// 열거형의 기본형태
// 이넘 클래스를 사용하는 이유는 똑같은 이름의 열거형 데이터가 두개의 이넘에서 존재할 시 컴퓨터가 인식을 제대로 못할 가능성이 있기 때문이다
enum class Day
{
	Sun, Mon, Tue, Wed, Thur, Fri, Sat
};

/*ㅏ
Enum과 Switch
- enum은 내부적으로 integer로 돌아가고 있기 때문에 switch구문과 밀접한 관계가 있다
- 특정상황에서는 enum과 switch를 활용하면 if~else 구문에 비해 더 편하고 깔끔한 개발을 할 수 있게 된다
*/
class Calender {
public:
	enum Month
	{
		JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
		// 숫자로 구분해줘도 괜찮다. 왜냐하면 내부적으로 integer로 돌아가고 있기 때문
	};

};



/*
상태를 나타내는 방법
- 비디오 게임은 여러가지 상태를 가질 수 있다
- 예를 들면 Playing, Paused, Win, Lose등 여러가지 상태가 있을 수 있고 이 상태를 나타내는 방법으로 enum을 많이 활용하게 된다
*/

enum Gender
{
	Male, Female
};
class Student
{
public:
	char name[10];
	int stu_num;
	Gender gender;

	Student(const char* name, int stu_num, Gender gender) {
		strcpy(this->name, name);
		this->stu_num = stu_num;
		this->gender = gender;

	}

	void print() {
		printf("이름 : %s\n", name);
		printf("학생번호 : %d\n", stu_num);
		printf("성별 : %s\n", gender == Gender::Male ? "남성" : "여성");
	}

};

int main() {
	
	// 열거형 데이터 클래스를 메인 함수에 가져오는 기본 형태
	Day d = Day::Mon;

	// 전역적인 이넘은 이넘 네임을 굳이 붙일 필요가 없다
	Gender gender = Male;

	Student* s = new Student("이서용", 1234, Gender::Male);
	s->print();

	// 클래스 내부에 존재하는 이넘을 사용할때 쓰는 코드
	Calender::Month m = Calender::Month::JAN;

	// 다음과 같이 작성하여 클래스 내부 이넘을 사용한다
	switch (m)
	{
	case Calender::Month::JAN:printf("1월입니다"); break;
	case Calender::Month::FEB:printf("2월입니다"); break;
	case Calender::Month::MAR:printf("3월입니다"); break;
	case Calender::Month::APR:printf("4월입니다"); break;
	case Calender::Month::MAY:printf("5월입니다"); break;
	case Calender::Month::JUN:printf("6월입니다"); break;
	case Calender::Month::JUL:printf("7월입니다"); break;
	case Calender::Month::AUG:printf("8월입니다"); break;
	case Calender::Month::SEP:printf("9월입니다"); break;
	case Calender::Month::OCT:printf("10월입니다"); break;
	case Calender::Month::NOV:printf("11월입니다"); break;
	case Calender::Month::DEC:printf("12월입니다"); break;
	default:
		break;
	}

	// enum은 내부적으로 integer로 돌아가기에 숫자로 나온다
	printf("\n%d", m);
	
	return 0;
}