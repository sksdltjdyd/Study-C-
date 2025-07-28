#define _CRT_SECURE_NO_WARNINGS

#include "TetrisHelper.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

#define GRID_WIDTH 7
#define GRID_HEIGHT 10
#define USERBLOCK_SIZE 3

int displayData[GRID_HEIGHT][GRID_WIDTH] = { 0, };

class Display {
public:
	void draw() {
		for (int i = 0; i < GRID_HEIGHT; i++)
		{
			for (int k = 0; k < GRID_WIDTH; k++) 
			{
				// drawPosition(k, i, displayData[i][k] == 1); --> 같은 의미
				if (displayData[i][k] == 0) 
				{
					drawPosition(k, i, false);
				}
				else
				{
					drawPosition(k, i, true);
				}
			}
		}
	}

};

// 게임의 전반적인 플레이를 관리하는 클래스
class GameEngine 
{
public:
	enum class GameState
	{
		PLAYING, GAMEOVER, 
	};
	GameState state = GameState :: PLAYING;
	// 게임 그리드 데이터에 블록이 있는지 확인
	int gameGridData[GRID_HEIGHT][GRID_WIDTH] = { 0, };

	// 게임 블록의 크기 설정
	int userBlock[USERBLOCK_SIZE][USERBLOCK_SIZE] = { 0, };

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

	// 블록의 위치 확인
	int blockx = 0;
	int blocky = 0;

	// 60프레임이 너무 빨라서 조절해주기 위한 함수
	float elapsed = 0.0f;

	// 좌우 움직임 속도 조절
	float controlcheck = 0.0f;
	
	void init() 
	{
		// 최초 게임 엔진 초기화 과정
		makeuserblock();
	}

	void next(float dt, char keyboardInput)
	{
		// 메인함수 루프에서 매번 불려지는 함수
		if (state == GameState::GAMEOVER) return;

		elapsed = elapsed + dt;
		if (elapsed >= 0.5f)
		{
			if (CanGoDown()) {
				blocky++;
			}
			else
			{
				// userblock을 gamegrid data에 전사
				trans();
				if (gameoverDecision()) state = GameState::GAMEOVER;
			}
			
			elapsed = elapsed - 0.5f;
		}

		controlcheck = controlcheck + dt;
		if (keyboardInput == 'a' && CanGoLefet() && controlcheck > 0.1) {
			blockx--;
			controlcheck = 0.0f;
		}
		if (keyboardInput == 'd'&& CanGoRight() && controlcheck > 0.1) {
			blockx++;
			controlcheck = 0.0f;
		}
		if (keyboardInput == 's' && CanGoRight() && controlcheck > 0.1) {
			blocky++;
			controlcheck = 0.0f; 
		}
		if (keyboardInput == 'w' && controlcheck > 0.1) {
			rotate();
			controlcheck = 0.0f;
		}
	}

	// 블록이 아래로 내려갈 수 있나
	bool CanGoDown() {
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				if (userBlock[i][k] == 1 && i + blocky + 1 >= GRID_HEIGHT) {
					return false;
				}
				if (userBlock[i][k] == 1 && gameGridData[i + blocky + 1][k + blockx] == 1) {
					return false;
				}
			}
		}
		return true;
	}

	// 블록이 왼쪽으로 갈 수 있나
	bool CanGoLefet() {
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				if (userBlock[i][k] == 1 && k + blockx - 1 < 0) {
					return false;
				}
				if (userBlock[i][k] == 1 && gameGridData[i + blocky][k + blockx - 1] == 1) {
					return false;
				}
			}
		}
		return true;
	}
	
	// 블록이 오른쪽으로 갈 수 있나
	bool CanGoRight() {

		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				if (userBlock[i][k] == 1 && k + blockx + 1 > GRID_WIDTH - 1) {
					return false;
				}
				if (userBlock[i][k] == 1 && gameGridData[i + blocky][k + blockx + 1] == 1) {
					return false;
				}
			}
		}
		return true;
	}

	// 줄이 가득차있는지 확인
	bool isLineFilled(int y) {
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			if (gameGridData[y][i] == 0) return false;
		}
		return true;
	}

	void eraseLine(int y) {
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			gameGridData[y][i] = 0;
		}
	}

	// y 좌표를 기준으로 한칸씩 아래로 내림
	void drop(int y) {
		for (int i = y; i >= 0; i--)
		{
			for (int k = 0; k < GRID_WIDTH; k++) {
				gameGridData[i][k] = i - 1 < 0 ? 0 : gameGridData[i - 1][k];
			}
		}
	}

	// 유저블록을 그리드에 전사하는 함수
	void trans() {
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				int _x = k + blockx;
				int _y = i + blocky;
				// gameGridData[i + blocky][k + blockx] = userBlock[i][k] == 1 ? userBlock[i][k] : gameGridData[i + blocky][k + blockx];
				gameGridData[_y][_x] = userBlock[i][k] | gameGridData[_y][_x];
			}
		}
		// 한 줄이 가득차 있는지 확인
		for (int i = 0; i < GRID_HEIGHT; i++)
		{
			if (isLineFilled(i)) {
				eraseLine(i);
				drop(i);
			}
		}
		// 블록 생성
		makeuserblock();
	}
	
	bool gameoverDecision() {
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				if (userBlock[i][k] == 1 && gameGridData[i + blocky][k + blockx] == 1) {
					return true;
				} 
			}
		}
		return false;
	}

	// 새로운 블록 생성
	void makeuserblock() {
		blockx = GRID_WIDTH / 2 - USERBLOCK_SIZE / 2;
		blocky = 0;
		
		// 랜덤으로 블록 생성
		int various = rand() % 3;
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				userBlock[i][k] = userblockvarious[various][i][k];
			}
		}
	}
	
	void rotate() {
		// 1. 회전된 블록을 임시로 저장할 배열 생성
		int tempBlock[USERBLOCK_SIZE][USERBLOCK_SIZE] = { 0, };

		// 2. 블록을 시계 방향으로 90도 회전시켜 임시 배열에 저장
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				tempBlock[i][k] = userBlock[USERBLOCK_SIZE - 1 - k][i];
			}
		}

		// 3. 회전했을 때 충돌이 발생하는지 확인
		bool canRotate = true;
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				if (tempBlock[i][k] == 1) {
					int _x = k + blockx;
					int _y = i + blocky;

					// 게임 화면 밖으로 나가는지 확인
					if (_x < 0 || _x >= GRID_WIDTH || _y < 0 || _y >= GRID_HEIGHT) {
						canRotate = false;
						break;
					}
					// 다른 블록과 겹치는지 확인
					if (gameGridData[_y][_x] == 1) {
						canRotate = false;
						break;
					}
				}
			}
			if (!canRotate) break;
		}


		// 4. 충돌이 없으면, 실제 블록에 회전된 모양 적용
		if (canRotate) {
			for (int i = 0; i < USERBLOCK_SIZE; i++)
			{
				for (int k = 0; k < USERBLOCK_SIZE; k++) {
					userBlock[i][k] = tempBlock[i][k];
				}
			}
		}
	}

	void makedisplaydata()
	{
		// display data를 전역으로 설정한 디스플레이 데이터를 전사해주는 함수
		// 실제 게임 데이터를 화면에 출력 할 수 있는 데이터
		for (int i = 0; i < GRID_HEIGHT; i++)
		{
			for (int k = 0; k < GRID_WIDTH; k++) 
			{
				// 게임 그리드 데이터를 넣어주는것
				displayData[i][k] = gameGridData[i][k];
			}
		}
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++) 
			{
				if (i + blocky <0 || i + blocky > GRID_HEIGHT) 
				{
					// 아무것도 하지 않는다
				}
				else if (k + blockx < 0 || k + blockx > GRID_WIDTH) 
				{
					// 아무것도 하지 않는다
				}
				else
				{
					int _x = k + blockx;
					int _y = i + blocky;
					//displayData[_y][_x] = userBlock[i][k] == 1 ? userBlock[i][k] : displayData[_y][_x];
					displayData[_y][_x] = userBlock[i][k] | displayData[_y][_x]; // 같은 표현
				}
			}
		}
	}

};