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
				// drawPosition(k, i, displayData[i][k] == 1); --> ���� �ǹ�
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

// ������ �������� �÷��̸� �����ϴ� Ŭ����
class GameEngine 
{
public:
	// ���� �׸��� �����Ϳ� ����� �ִ��� Ȯ��
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

	// ���� ����� ũ�� ����
	int userBlock[USERBLOCK_SIZE][USERBLOCK_SIZE] = {
		{1, 1, 1},
		{0, 0, 1},
		{0, 0, 1} 
		};

	// ����� ��ġ Ȯ��
	int blockx = 0;
	int blocky = 0;

	// 60�������� �ʹ� ���� �������ֱ� ���� �Լ�
	float elapsed = 0.0f;
	
	void init() 
	{
		// ���� ���� ���� �ʱ�ȭ ����
	}

	void next(float dt, char keyboardInput)
	{
		// �����Լ� �������� �Ź� �ҷ����� �Լ�
		elapsed = elapsed + dt;
		if (elapsed >= 0.5f)
		{
			blocky++;
			elapsed = elapsed - 0.5f;
		}
	}

	void makedisplaydata()
	{
		// display data�� �������� ������ ���÷��� �����͸� �������ִ� �Լ�
		// ���� ���� �����͸� ȭ�鿡 ��� �� �� �ִ� ������
		for (int i = 0; i < GRID_HEIGHT; i++)
		{
			for (int k = 0; k < GRID_WIDTH; k++) 
			{
				// ���� �׸��� �����͸� �־��ִ°�
				displayData[i][k] = gameGridData[i][k];
			}
		}
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++) 
			{
				if (i + blocky <0 || i + blocky > GRID_HEIGHT) 
				{
					// �ƹ��͵� ���� �ʴ´�
				}
				else if (k + blockx < 0 || k + blockx > GRID_WIDTH) 
				{
					// �ƹ��͵� ���� �ʴ´�
				}
				else
				{
					int _x = k + blockx;
					int _y = i + blocky;
					//displayData[_y][_x] = userBlock[i][k] == 1 ? userBlock[i][k] : displayData[_y][_x];
					displayData[_y][_x] = userBlock[i][k] | displayData[_y][_x]; // ���� ǥ��
				}
			}
		}
	}

};