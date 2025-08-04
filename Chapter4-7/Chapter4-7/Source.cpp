#include <cstdio>
#include <string>

// STL  클래스 선언방법
template <typename T>
class Myclass {
public:
	// 나중에 변수의 타입을 설정
	T value;
};

// STL 함수 선언
template <typename T>
void swap(T& a, T& b) {
	
	T temp;
	temp = a;
	a = b;
	b = temp;

}
/*
**STL(Standard Template Library)**
- 프로그래밍에 필요한 자료구조와 알고리즘을 미리 만들어 모아놓은 강력한 라이브러리
- 간단히 말해, C++ 언어 차원에서 공식적으로 제공하는 '프로그래밍 전문가용 도구 상자'라고 생각할 수 있다. 직접 만들 필요 없이 이미 검증되고 최적화된 도구를 가져다 쓰기만 하면 된다

## STL의 3가지 핵심 구성 요소
STL은 크게 세 가지 요소가 유기적으로 결합하여 동작
1) 컨테이너 (Containers) - 데이터를 담는 그릇
- 다양한 방식으로 데이터를 저장하고 관리하는 자료구조 클래스. 어떤 그릇에 담느냐에 따라 데이터의 특징과 사용법이 달라진다
	- 시퀀스 컨테이너 (Sequence Containers): 데이터가 입력된 순서대로 저장
	- vector: 가장 많이 쓰이는 동적 배열. 맨 뒤에 데이터를 추가하거나 특정 위치의 데이터에 접근하는 속도가 매우 빠르다
	- list: 데이터의 추가와 삭제가 어느 위치에서든 매우 빠르지만, 특정 데이터를 찾아가는 속도는 느리다
	- deque: vector와 비슷하지만, 데이터의 맨 앞과 뒤 모두에서 추가/삭제가 빠르다
	- 연관 컨테이너 (Associative Containers): 키(key)를 기반으로 데이터를 자동 정렬하여 저장
	- set: 중복되지 않는 유일한 값(key)들을 정렬하여 저장
	- map: '키(key)-값(value)' 쌍을 키 기준으로 정렬하여 저장 (예: 이름-전화번호)
	- 컨테이너 어댑터 (Container Adapters): 기존 컨테이너를 특정 목적에 맞게 변형한 것
	- stack: LIFO(Last-In, First-Out). 가장 나중에 들어온 데이터가 가장 먼저 나간다
	- queue: FIFO(First-In, First-Out). 가장 먼저 들어온 데이터가 가장 먼저 나간다

2) 알고리즘 (Algorithms) - 데이터를 요리하는 도구
- 컨테이너에 저장된 데이터를 정렬, 탐색, 변경하는 등 다양한 작업을 수행하는 함수들
	- sort(): 데이터를 정렬
	- find(): 특정 데이터를 찾는다
	- copy(): 데이터를 복사
	- for_each(): 모든 데이터에 대해 특정 작업을 반복

3) 반복자 (Iterators) - 그릇과 도구를 연결하는 손
- 반복자는 컨테이너 속의 데이터 위치를 가리키는 '포인터'와 비슷한 객체
- 알고리즘이 특정 컨테이너에 종속되지 않고 범용적으로 동작할 수 있도록 컨테이너와 알고리즘을 연결하는 핵심적인 역할
- 알고리즘은 "어떤 vector를 정렬해줘"가 아니라, "여기(begin)부터 저기(end)까지의 데이터를 정렬해줘"라는 방식으로 동작한다
- 이때 '여기'와 '저기'를 알려주는 것이 바로 반복자다

## STL을 왜 사용할까요?
1) 생산성: 이미 만들어진 자료구조와 알고리즘을 사용하므로 개발 시간이 크게 단축
2) 성능: 수많은 전문가에 의해 최적화되어 있어 직접 만든 것보다 성능이 뛰어난 경우가 많다
3) 안정성: 오랜 기간 검증되어 버그가 거의 없고 안정적
4)가독성: std::vector, std::sort 등 표준화된 코드는 누가 보아도 그 의도를 쉽게 파악할 수 있다
*/

/*
STL - 가변 배열 클래스 작성
- STL의 방법을 활용하여 가변 배열 클래스를 작성한다
- 이를 통해 코드의 재사용성을 늘릴 수 있다
- 필요할때마다 그때그때 모든 코드를 하나하나 만드는것이 아닌 하나의 통합적인 자료관리 모델을 만들고 이를 활용하는 코드를 생산해본다
*/

/*
STL 선언과 정의 분리
- STL은 선언과 정의를 분리 할 수 있다
- 이유는 C++ 컴파일러가 그때그때 필요한 타입에 맞는 STL 클래스를 가져와서 그것을 이용해 STL 클래스 몸체를 만들거나 STL 함수를 만들기 때문이다
- 마치 전처리기(매크로)와 같은 동작을 하는것이 STL이기 때문이다
- 때문에 STL 클래스는 보통 헤더파일에만 존재하게 된다
*/
template <typename T>
class Myarray {
// 협업 시 바꾸기 싫은 변수를 접근 불가능하게 설정
private:
	T* arritem; // 배열 포인터
	int count = 0;
	int capacity = 8;

public:
	Myarray() {
		arritem = new T[capacity];
	}

	~Myarray()
	{
		delete[] arritem;
	}

	void putvalue(const T& value) {

		if (capacity <=count)
		{
			printf("배열의 capacity가 늘어났습니다\n");
			T* newarray = new T[capacity * 2];
			capacity = capacity * 2;
			for (int i = 0; i < count; i++)
			{
				newarray[i] = arritem[i];
			}
			delete[] arritem;
			arritem = newarray;
			
		}
		arritem[count] = value;
		count++;
	}

	// private 변수에 접근 하기 위해서 따로 만드는 함수
	int getcount() {
		return count;
	}

	T getvalue(int index) {
		return arritem[index];
	}
	
	bool contains(T value) {
		for (int i = 0; i < count; i++)
		{
			if (value == arritem[i]) return true;
		}
		return false;
	}
	void replace(int index, T value) {
		if (index < count) {
			arritem[index] = value;
		}
	}

	void erase(int index) {
		for (int i = index; i < count-1; i++)
		{
			arritem[i] = arritem[i + 1];
		}
		count--;
		
	}
};

int main() {

	// 변수의 타입을 설정
	Myclass<int>* m = new Myclass<int>();
	m->value = 100;

	// 같은 클래스라도 타입을 자유롭게 바꿀 수 있다
	Myclass<std::string>* ms = new Myclass<std::string>();
	ms->value = "Hello World";

	int v1 = 100;
	int v2 = 200;

	// 함수의 변수 타입 설정
	swap<int>(v1, v2);

	printf("v1 = %d\n", v1);
	printf("v2 = %d\n", v2);

	Myarray<int> ma = Myarray<int>();

	ma.putvalue(100);
	ma.putvalue(200);
	ma.putvalue(300);
	ma.putvalue(400);
	ma.putvalue(500);
	ma.putvalue(600);
	ma.putvalue(700);
	ma.putvalue(800);
	ma.putvalue(900);

	// private 변수 값을 가져올 수 있도록 설정
	for (int i = 0; i < ma.getcount(); i++)
	{
		printf("%d\n", ma.getvalue(i));
	}

	return 0; 
}