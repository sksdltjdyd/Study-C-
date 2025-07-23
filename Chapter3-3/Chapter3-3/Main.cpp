#include "Header.h"

/*
Class
- class 키워드를 이용해 클래스를 생성할 수 있다
- class는 struct를 대체하기 때문에 struct을 대체한다고 보면 된다
- 이 클래스 내부에는 꼭 public:이라는 키워드가 있어야 한다
*/



class Student
{
public:
	int student_no;
	char* name;
	int gender; // 0 = 남자, 1 = 여자

	/*
	생성자(Constructor)
	- 클래스는 생성자를 통해 초기 행동을 지정해줄 수 있다
	- 생성자는 클래스명(파라미터들...)로 선언 가능하다
	- 생성자는 리턴타입을 갖지 않는다
	*/
	// 인스턴스 : 클래스는 정의만으로는 존재할 수 없다. 여지껏 '클래스의 변수'라고 말해왔던 것을 클래스 인스턴스라고 생각하면 편하다
	Student(int student_no, const char* name, int gender) 
	{
		// this 키워드는 자기자신의 인스턴스(포인터타입)을 가져올 수 있다. 클래스 멤버함수를 호출하기 위해서는 호출한 주체인 어떤 클래스 인스턴스가 존재하는데 그 호출 주체가 this이다
		this->student_no = student_no; 
		this->name = new char[strlen(name) + 1]; //파라미터로 문자열을 입력받아 문자열의 길이를 반환
		strcpy(this -> name, name);
		this->gender = gender;

	}

	/*
	소멸자(Destructor)
	- 클래스는 소멸자를 통해 메모리에서 해제될 떄의 행동을 지정할 수 있다. 이를 소멸자라 한다
	- 소멸자는 ~클래스명()으로 선언할 수 있으며 소멸자도 리턴타입이 존재하지 않는다
	*/

	/*
	소멸자 호출의 필요성
	- 모든 동적 메모리를 수동으로 관리해줘야 하는 C++특성상 클래스 멤버 변수에 동적 메모리가 할당된 개체가 있다고 할 경우 소멸자에서 처리 하지 않으면 하나 하나 클래스 외부에서 메모리를 해제해야 한다
	- 이는 굉장히 불편함과 불합리함을 초래하게 되는데 이를 해결할 수 있는것이 소멸자이다
	*/
	~Student()
	{
		delete[] name; // 메모리에 동적 할당된 데이터를 삭제 해주는 키워드. free()와 개념이 같다
		printf("%d의 소멸자 호출을 완료했습니다\n", student_no);
	}
	

	void PrintStudentInfo() {
		printf("학생 번호 : %d\n", student_no);
		printf("학생 이름 : %s\n", name);
		printf("성별 : %s\n", gender == 0 ? "남자" : "여자");// 인라인 조건절 : 인라인 조건절을 이용해 생성되는 값을 지정할 수 있다

	}
};

int main() {

	Student s = Student(1234, "이서용", 0);
	s.PrintStudentInfo();

	Student s2 = Student(3456, "박현정", 1);
	s2.PrintStudentInfo();

	Student* ps = new Student(78910, "이새아", 0);
	ps->PrintStudentInfo();

	delete ps;
	/*
	클래스 인스턴스간 차이
	- new 키워드를 이용해 클래스를 만들게 되면 클래스의 실제 값이 Heap영역에 저장되는것이 큰 차이이다
	- Heap 영역에 저장되는 클래스의 인스턴스 값은 함수의 실행주기(라이프사이클)에 관계없이 유지된다
	*/

	return 0;
}