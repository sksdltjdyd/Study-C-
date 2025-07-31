#include "GameEngine.h"

// ���� ���� ���� �ʱ�ȭ ����
void GameEngine::init()
{
	makeuserblock();
}

// �����Լ� while�������� �Ź� �ҷ����� � ������ ���� Ȯ���ϴ� �Լ�
void GameEngine::next(float dt, char keyboardInput)
{
	// �����Լ� �������� �Ź� �ҷ����� �Լ�
	if (state == GameState::GAMEOVER) return;

	elapsed = elapsed + dt;
	if (elapsed >= 0.5f)
	{
		if (CanGoDown()) {
			// can go down �Լ��� ���̸� ��� ��ġ�� ��� �������� ��������
			blocky++;
		}
		else
		{
			// userblock�� gamegrid data�� ����
			trans();
			// ���ӿ��� �Լ��� ���̸� ���ӿ��� ���� ����
			if (gameoverDecision()) state = GameState::GAMEOVER;
		}

		elapsed = elapsed - 0.5f;
	}

	controlcheck = controlcheck + dt;
	if (keyboardInput == 'a' && CanGoLefet() && controlcheck > 0.1) {
		blockx--;
		controlcheck = 0.0f;
	}
	if (keyboardInput == 'd' && CanGoRight() && controlcheck > 0.1) {
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
bool GameEngine::CanGoDown() {
	for (int i = 0; i < USERBLOCK_SIZE; i++)
	{
		for (int k = 0; k < USERBLOCK_SIZE; k++) {
			if (userBlock[i][k] == 1 && i + blocky + 1 >= GRID_HEIGHT) {
				// ����� �׸����� ����� �����ϰ� ����� y�� ��ġ + 1�� ����� �׸��� ���̺��� ũ�� �� �������� �ʴ´�
				return false;
			}
			if (userBlock[i][k] == 1 && gameGridData[i + blocky + 1][k + blockx] == 1) {
				//  ����� �׸����� ����� �����ϰ� ���� ����� �׸����� ��� �ٷ� �Ʒ��� ����� �ִٸ� �� �������� �ʴ´�
				return false;
			}
		}
	}
	// �ΰ��� ��찡 �ƴϸ� ��������
	return true;
}

// ����� �������� �� �� �ֳ�
bool GameEngine::CanGoLefet() {
	for (int i = 0; i < USERBLOCK_SIZE; i++)
	{
		for (int k = 0; k < USERBLOCK_SIZE; k++) {
			if (userBlock[i][k] == 1 && k + blockx - 1 < 0) {
				// ����� ������ ��ġ�� ����� �����ϰų� ��� ��ġ�� k������ 1 ������ 0���� ������ ����� �迭�� ����°ŹǷ� �����̸� �ȉ´�
				return false;
			}
			if (userBlock[i][k] == 1 && gameGridData[i + blocky][k + blockx - 1] == 1) {
				// ����� ������ ��ġ�� ����� �����ϰų� ����� �������� ��� ��ġ�� ���ʿ� ����� �ִٸ� ������ �� ����
				return false;
			}
		}
	}
	// �ΰ��� ��찡 �ƴϸ� �������� �����δ�
	return true;
}

// ����� ���������� �� �� �ֳ�
bool GameEngine::CanGoRight() {

	for (int i = 0; i < USERBLOCK_SIZE; i++)
	{
		for (int k = 0; k < USERBLOCK_SIZE; k++) {
			if (userBlock[i][k] == 1 && k + blockx + 1 > GRID_WIDTH - 1) {
				// ����� ������ ��ġ�� ����� �����ϰų� ��� ��ġ�� k������ 1 ���ߴ��� �迭�׸��� ���̿��� 1 ���ͺ��� ũ�� �迭�� ����°��̹Ƿ� ������ �� ����
				return false;
			}
			if (userBlock[i][k] == 1 && gameGridData[i + blocky][k + blockx + 1] == 1) {
				// ����� ������ ��ġ�� ����� �����ϰų� ����� �������� ��� ��ġ�� ����� �ִٸ� ������ �� ����
				return false;
			}
		}
	}
	// �ΰ��� ��찡 �ƴϸ� ���������� �����δ�
	return true;
}

// ���� �������ִ��� Ȯ��
bool GameEngine::isLineFilled(int y) {
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		// ���� �� �ִٸ� ��ĭ�̶� 0�̸� �ȵǱ⿡ �������� �ȉ´�
		if (gameGridData[y][i] == 0) return false;
	}
	return true;
}

// ������ �ִ� ������ �����
void GameEngine::eraseLine(int y) {
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		// y��° �� ������ ���� �����
		gameGridData[y][i] = 0;
	}
}

// ������ ���� �� y ��ǥ�� �������� ��ĭ�� �Ʒ��� ����
void GameEngine::drop(int y) {
	for (int i = y; i >= 0; i--)
	{
		for (int k = 0; k < GRID_WIDTH; k++) {
			// ����� ��Ͽ� i - 1 ��ġ�� �־��µ� �� ���� 0���� �۴ٸ� �迭 �׸��带 ����°��̹Ƿ� �׳� 0�� �ְ� �װ� �ƴ϶�� ��ĭ�� ���� ���� �ִ´�
			gameGridData[i][k] = i - 1 < 0 ? 0 : gameGridData[i - 1][k];
		}
	}
}

// ��������� �׸��忡 �����ϴ� �Լ�
void GameEngine::trans() {
	for (int i = 0; i < USERBLOCK_SIZE; i++)
	{
		for (int k = 0; k < USERBLOCK_SIZE; k++) {
			int _x = k + blockx;
			int _y = i + blocky;
			// �Ѵ� �ƴ� ��, ��������� ���� ȭ�� �ȿ� �ִ°��̹Ƿ� �����͸� �־��ش�
			// ���÷��̵����� x,y��ǥ�� ������ 0���� 1���� �Ǵ��� �ؼ� 1�̸� ������� x,y��ǥ�� �־��ְ� 0�̸� ���ο� ��� �����͸� �־��ش�
			// gameGridData[i + blocky][k + blockx] = userBlock[i][k] == 1 ? userBlock[i][k] : gameGridData[i + blocky][k + blockx];
			gameGridData[_y][_x] = userBlock[i][k] | gameGridData[_y][_x];
		}
	}
	// �� ���� ������ �ִ��� Ȯ��
	for (int i = 0; i < GRID_HEIGHT; i++)
	{
		if (isLineFilled(i)) {
			// ������ �������� ���� �� ������ ����� ����� ��ĭ�� �����
			eraseLine(i);
			drop(i);
		}
	}
	// ��� ����
	makeuserblock();
}

// ���� ���� ���� ����
bool GameEngine::gameoverDecision() {
	for (int i = 0; i < USERBLOCK_SIZE; i++)
	{
		for (int k = 0; k < USERBLOCK_SIZE; k++) {
			if (userBlock[i][k] == 1 && gameGridData[i + blocky][k + blockx] == 1) {
				// ��������� ��ġ�� ����� �ְ� ����� �׸��� �����Ϳ� ����� �����ϸ� �� 
				return true;
			}
		}
	}
	return false;
}

// ���ο� ��� ����
void GameEngine::makeuserblock() {
	// ����� ���� �����Ǵ� ��ġ ����
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

void GameEngine::rotate() {
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

// display data�� �������� ������ ���÷��� �����͸� �������ִ� �Լ�
	// ���� ���� �����͸� ȭ�鿡 ��� �� �� �ִ� �����ͷ� �ٲ��ִ� �Լ�
	// ���� �׸��� �����Ϳ� �������� ����ϴ� ����� �����ͷ� ��������
void GameEngine::makedisplaydata()
{
	for (int i = 0; i < GRID_HEIGHT; i++)
	{
		for (int k = 0; k < GRID_WIDTH; k++)
		{
			// ���� �׸��� �����͸� �־��ִ°�
			displayData[i][k] = gameGridData[i][k];
		}
	}

	// ��������� �����͸� �־��ִ� ����
	for (int i = 0; i < USERBLOCK_SIZE; i++)
	{
		for (int k = 0; k < USERBLOCK_SIZE; k++)
		{
			if (i + blocky < 0 || i + blocky > GRID_HEIGHT)
			{
				// ��������� y��ǥ�� 0���� �۰ų� ������ �׸��� ���̺��� ũ�� ȭ���� �Ѿ�°��̹Ƿ� �ƹ��͵� ���� �ʴ´�
			}
			else if (k + blockx < 0 || k + blockx > GRID_WIDTH)
			{
				// ��������� x��ǥ�� 0���� �۰ų� ������ �׸��� ���̺��� ũ�� ȭ���� �Ѿ�°��̹Ƿ� �ƹ��͵� ���� �ʴ´�
			}
			else
			{
				// �Ѵ� �ƴ� ��, ��������� ���� ȭ�� �ȿ� �ִ°��̹Ƿ� �����͸� �־��ش�
				// ���÷��̵����� x,y��ǥ�� ������ 0���� 1���� �Ǵ��� �ؼ� 1�̸� ������� x,y��ǥ�� �־��ְ� 0�̸� ���ο� ��� �����͸� �־��ش�
				int _x = k + blockx;
				int _y = i + blocky;
				//displayData[_y][_x] = userBlock[i][k] == 1 ? userBlock[i][k] : displayData[_y][_x];
				displayData[_y][_x] = userBlock[i][k] | displayData[_y][_x]; // ���� ǥ��
			}
		}
	}
}
