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
	// 게임 그리드 데이터에 블록이 있는지 확인
	int gameGridData[GRID_HEIGHT][GRID_WIDTH] = { 
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}, 
		{1, 1, 0, 0, 0, 0, 0}, 
		{1, 1, 0, 0, 0, 0, 0}, 
	};

	// 게임 블록의 크기 설정
	int userBlock[USERBLOCK_SIZE][USERBLOCK_SIZE] = {
		{1, 1, 1},
		{0, 0, 1},
		{0, 0, 1} 
		};

	// 블록의 위치 확인
	int blockx = 0;
	int blocky = 0;

	// 60프레임이 너무 빨라서 조절해주기 위한 함수
	float elapsed = 0.0f;
	
	void init() 
	{
		// 최초 게임 엔진 초기화 과정
	}

	void next(float dt, char keyboardInput)
	{
		// 메인함수 루프에서 매번 불려지는 함수
		elapsed = elapsed + dt;
		if (elapsed >= 0.5f)
		{
			blocky++;
			elapsed = elapsed - 0.5f;
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