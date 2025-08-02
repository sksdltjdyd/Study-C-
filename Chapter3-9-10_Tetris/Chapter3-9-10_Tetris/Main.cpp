#include "Header.h"
#include "Display.h"
#include "GameEngine.h"


// 60���������� ����� ���� ���͹��� 1/60�ʷ� ����. 0.017��
#define INTERVAL 1.0 / 60.0

// ���� ����� ȭ�鿡 �ߴ� ���� ȭ�� ũ�� ����
int displayData[GRID_HEIGHT][GRID_WIDTH] = { 0, };

int main() {

	// ���� ����� �����ϱ� ���� ���� ����
	srand(time(0));

	// ������ ����� ���� ������ �ð��� ���������� üũ
	float prev = (float)clock() / CLOCKS_PER_SEC;

	// ���� ȭ�� ���
	Display* display = new Display();

	// Ŀ���� ����� ��ɾ�
	showConsoleCursor(false);


	// ���� ������ �ҷ��ͼ� ����
	GameEngine* gameengine = new GameEngine();
	// ���� �ʱ�ȭ ����
	gameengine->init();

	while (true)
	{
		float cur = (float)clock() / CLOCKS_PER_SEC;

		// Delta time�� ���� ���� ���� �ð��� ���� �ȿ����� �ð��� ���� ���ϱ�
		float dt = cur - prev;

		if (dt < INTERVAL) continue; // ��Ÿ Ÿ���� 1/60�ʺ��� ������ ����
		prev = cur;

		// ����Ű ����
		bool left = keyState('a');
		bool right = keyState('d');
		bool down = keyState('s');
		bool rotate = keyState('w');
		if (left == true)
		{
			// �������� ��� �̵�
			gameengine->next(dt, 'a');
		}
		else if (right == true) {
			// ���������� ��� �̵�
			gameengine->next(dt, 'd');
		}
		else if (down == true) {
			// ��� �Ʒ��� �̵�
			gameengine->next(dt, 's');
		}
		else if (rotate == true) {
			// ��� ȸ��
			gameengine->next(dt, 'w');
		}
		else
		{
			// ��� ������
			gameengine->next(dt, 0);
		}





		// ȭ�� ���
		gameengine->makedisplaydata();
		display->draw();

		// ���� ���� �Ǻ�
		if (gameengine->state == GameEngine::GameState::GAMEOVER) break;

	}

	return 0;
}