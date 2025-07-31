#ifndef __GAMEENGINE_H__
#define __GAMEENGINE_H__

#include "Header.h"

// 게임의 전반적인 플레이를 모두 관리하는 클래스
class GameEngine
{
public:
	// 게임의 종료 조건 설정
	enum class GameState
	{
		PLAYING, GAMEOVER,
	};
	GameState state = GameState::PLAYING;

	// 게임 그리드 데이터에 블록이 있는지 확인. 데이터 확인 변수
	int gameGridData[GRID_HEIGHT][GRID_WIDTH] = { 0, };

	// 게임에서 사용되는 블록의 크기 설정
	int userBlock[USERBLOCK_SIZE][USERBLOCK_SIZE] = { 0, };

	// 게임에서 사용되는 블록의 종류 설정
	int userblockvarious[3][USERBLOCK_SIZE][USERBLOCK_SIZE] = {
		{
			{0, 1, 0},
			{0, 1, 0},
			{0, 1, 0}
		},
		{
			{0, 0, 0},
			{0, 1, 1},
			{0, 1, 1}
		},
		{
			{0, 0, 0},
			{0, 1, 0},
			{1, 1, 0}
		},
	};

	// 블록의 위치 확인 변수
	int blockx = 0;
	int blocky = 0;

	// 60프레임이 너무 빨라서 조절해주기 위한 함수
	float elapsed = 0.0f;

	// 좌우 움직임 속도 조절
	float controlcheck = 0.0f;

	void init();

	void next(float dt, char keyboardInput);

	bool CanGoDown();

	bool CanGoLefet();

	bool CanGoRight();

	bool isLineFilled(int y);

	void eraseLine(int y);

	void drop(int y);

	void trans();

	bool gameoverDecision();

	void makeuserblock();

	void rotate();

	void makedisplaydata();

};

#endif // !__GAMEENGINE_H__


