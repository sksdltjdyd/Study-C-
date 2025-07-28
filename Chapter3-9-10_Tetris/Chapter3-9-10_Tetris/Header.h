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
	enum class GameState
	{
		PLAYING, GAMEOVER, 
	};
	GameState state = GameState :: PLAYING;
	// ���� �׸��� �����Ϳ� ����� �ִ��� Ȯ��
	int gameGridData[GRID_HEIGHT][GRID_WIDTH] = { 0, };

	// ���� ����� ũ�� ����
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

	// ����� ��ġ Ȯ��
	int blockx = 0;
	int blocky = 0;

	// 60�������� �ʹ� ���� �������ֱ� ���� �Լ�
	float elapsed = 0.0f;

	// �¿� ������ �ӵ� ����
	float controlcheck = 0.0f;
	
	void init() 
	{
		// ���� ���� ���� �ʱ�ȭ ����
		makeuserblock();
	}

	void next(float dt, char keyboardInput)
	{
		// �����Լ� �������� �Ź� �ҷ����� �Լ�
		if (state == GameState::GAMEOVER) return;

		elapsed = elapsed + dt;
		if (elapsed >= 0.5f)
		{
			if (CanGoDown()) {
				blocky++;
			}
			else
			{
				// userblock�� gamegrid data�� ����
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

	// ����� �Ʒ��� ������ �� �ֳ�
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

	// ����� �������� �� �� �ֳ�
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
	
	// ����� ���������� �� �� �ֳ�
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

	// ���� �������ִ��� Ȯ��
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

	// y ��ǥ�� �������� ��ĭ�� �Ʒ��� ����
	void drop(int y) {
		for (int i = y; i >= 0; i--)
		{
			for (int k = 0; k < GRID_WIDTH; k++) {
				gameGridData[i][k] = i - 1 < 0 ? 0 : gameGridData[i - 1][k];
			}
		}
	}

	// ��������� �׸��忡 �����ϴ� �Լ�
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
		// �� ���� ������ �ִ��� Ȯ��
		for (int i = 0; i < GRID_HEIGHT; i++)
		{
			if (isLineFilled(i)) {
				eraseLine(i);
				drop(i);
			}
		}
		// ��� ����
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

	// ���ο� ��� ����
	void makeuserblock() {
		blockx = GRID_WIDTH / 2 - USERBLOCK_SIZE / 2;
		blocky = 0;
		
		// �������� ��� ����
		int various = rand() % 3;
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				userBlock[i][k] = userblockvarious[various][i][k];
			}
		}
	}
	
	void rotate() {
		// 1. ȸ���� ����� �ӽ÷� ������ �迭 ����
		int tempBlock[USERBLOCK_SIZE][USERBLOCK_SIZE] = { 0, };

		// 2. ����� �ð� �������� 90�� ȸ������ �ӽ� �迭�� ����
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				tempBlock[i][k] = userBlock[USERBLOCK_SIZE - 1 - k][i];
			}
		}

		// 3. ȸ������ �� �浹�� �߻��ϴ��� Ȯ��
		bool canRotate = true;
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				if (tempBlock[i][k] == 1) {
					int _x = k + blockx;
					int _y = i + blocky;

					// ���� ȭ�� ������ �������� Ȯ��
					if (_x < 0 || _x >= GRID_WIDTH || _y < 0 || _y >= GRID_HEIGHT) {
						canRotate = false;
						break;
					}
					// �ٸ� ��ϰ� ��ġ���� Ȯ��
					if (gameGridData[_y][_x] == 1) {
						canRotate = false;
						break;
					}
				}
			}
			if (!canRotate) break;
		}


		// 4. �浹�� ������, ���� ��Ͽ� ȸ���� ��� ����
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