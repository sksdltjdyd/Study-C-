#ifndef __GAMEENGINE_H__
#define __GAMEENGINE_H__

#include "Header.h"

// ������ �������� �÷��̸� ��� �����ϴ� Ŭ����
class GameEngine
{
public:
	// ������ ���� ���� ����
	enum class GameState
	{
		PLAYING, GAMEOVER,
	};
	GameState state = GameState::PLAYING;

	// ���� �׸��� �����Ϳ� ����� �ִ��� Ȯ��. ������ Ȯ�� ����
	int gameGridData[GRID_HEIGHT][GRID_WIDTH] = { 0, };

	// ���ӿ��� ���Ǵ� ����� ũ�� ����
	int userBlock[USERBLOCK_SIZE][USERBLOCK_SIZE] = { 0, };

	// ���ӿ��� ���Ǵ� ����� ���� ����
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

	// ����� ��ġ Ȯ�� ����
	int blockx = 0;
	int blocky = 0;

	// 60�������� �ʹ� ���� �������ֱ� ���� �Լ�
	float elapsed = 0.0f;

	// �¿� ������ �ӵ� ����
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


