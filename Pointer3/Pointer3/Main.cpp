#include "Header.h"

struct Marine
{
	int hp = 0;
	int damage = 0;
	int mp = 0;
	char name[20];
};

Marine* foo() {
	Marine *m = (Marine*)malloc(sizeof(Marine)); // Marine 구조체 크기만큼 메모리를 동적으로 할당
	m->damage = 10;
	m->hp = 100;
	m->mp = 50; // 특별히 화살표로 표현할 수 있다
	strcpy(m->name, "Marine1");

	return m; // 지역변수 m의 주소를 반환
}

int main() {

	/*
	포인터와 배열
	- 포인터는 배열의 이름과 동일하게 동작한다
	- 배열의 이름은 배열의 첫 번째 요소를 가리키는 포인터로 해석된다
	*/

	int arr[5];
	int* par = arr; // 배열의 이름은 첫 번째 요소를 가리키는 포인터로 해석된다

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;

	printf("arr[0] = %d\n", arr[0]);
	printf("par[0] = %d\n", par[0]);
	// par는 arr의 첫 번째 요소를 가리키므로 동일한 값이 출력된다. 정확히 말하자면 다르지만 배열 변수명은 포인터로 해석되므로 같은 값이 출력된다.[]는 해당 주소값에서 몇번째 뒤에 있는 값을 가져오는지 나타낸다
	
	int value = 40;
	int* vp = &value; // value의 주소를 vp에 저장
	printf("value = %d\n", vp[0]);
	// vp는 value의 주소를 가리키므로 vp[0]은 value의 값을 출력한다. 포인터는 배열처럼 동작할 수 있다
	/*
	포인터 값을 가져오는것의 의미
	- *vp의 형태로 가져온다는것은 해당 주소값의 값을 가져오는 것이다
	- vp[0]의 형태로 가져온다는것은 해당 주소값에서 몇번째 뒤에 있는 값을 가져오는 것이다
	- 즉 결론적으로 *vp와 vp[0]은 동일한 값을 출력한다
	- 다만 정확히 같은 값은 아니다. 포인터는 주소값을 가지고 있고, 배열은 해당 주소값에서 몇번째 뒤에 있는 값을 가져오는 것이다. 동작원리가 동일하기 때문에 같은 값이 출력되는 것이다
	*/

	const char* str = "Hello, World!"; // 문자열은 문자 배열로 저장된다. const char*는 문자열을 박아버리는 형태로 사용된다. 값이 바뀌지 않도록 const를 붙인다
	printf("str = %s\n", str);


	/*
	메모리 동적 할당
	- 배열이나 데이터를 컴퓨터의 메모리중 Heap 영역에 할당하여 사용할 수 있다
	- Heap 영역은 프로그램이 실행되는 동안 동적으로 메모리를 할당하고 해제할 수 있는 영역이다
	- 프로그램 종료시까지 메모리를 유지할 수 있다
	- malloc() 함수를 사용하여 메모리를 동적으로 할당할 수 있다
	*/

	Marine* pM = foo(); // 동적으로 할당된 Marine 구조체의 포인터를 반환받는다
	printf("Marine Name: %s\n", pM->name);

	free(pM); // 동적으로 할당된 메모리를 해제한다. 메모리 누수를 방지하기 위해 반드시 해제해야 한다

	/*
	동적 메모리 할당 - 배열
	- 이는 근본적으로 배열이 포인터와 같은 원리이기 때문에 Malloc으로 할당될 메모리의 양만 더 크게 잡아주면 동적으로 "배열"을 만들 수 있다
	*/


	int* pArr = (int*)malloc(sizeof(int) * 5); // int형 배열을 동적으로 할당. 5개의 int형 요소를 가진 배열을 생성한다
	
	for (int i = 0; i < 5; i++) {
		pArr[i] = i + 1; // 배열에 값을 할당
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", pArr[i]);
	}
	
	free(pArr); // 동적으로 할당된 배열 메모리를 해제한다
	
	return 0;
}