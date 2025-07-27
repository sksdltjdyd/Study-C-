#include "Header.h"
#define INTERVAL 1.0 / 60.0 // 60프레임으로 만들기 위해 인터벌을 1/60초로 설정

int main() {

	// 게임이 실행된 이후 지나는 시간을 지속적으로 체크
	float prev = (float)clock() / CLOCKS_PER_SEC;

	// 게임 화면 출력
	Display* display = new Display();
	showConsoleCursor(false);


	// 게임 엔진을 불러와서 관리
	GameEngine* gameengine = new GameEngine();

	while (true)
	{
		float cur = (float)clock() / CLOCKS_PER_SEC;

		// Delta time을 게임 실행 이후 시간과 루프 안에서의 시간을 뺴서 구하기
		float dt = cur - prev;

		if (dt < INTERVAL) continue; // 델타 타임이 1/60초보다 작으면 지속
		prev = cur;

		// 방향키 설정
		bool left = keyState('a');
		if (left = true) 
		{
			// 왼쪽으로 블록 이동
		}
		else 
		{
			// 블록 떨어짐
		}

		bool right = keyState('d');

		gameengine->next(dt, 0);

		// 화면 출력
		gameengine->makedisplaydata();
		display->draw();

		// 게임 상태 판별
		
	}

	return 0;
}