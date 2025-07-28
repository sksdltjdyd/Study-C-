#include "Header.h"
#define INTERVAL 1.0 / 60.0 // 60���������� ����� ���� ���͹��� 1/60�ʷ� ����

int main() {

	srand(time(0));
	// ������ ����� ���� ������ �ð��� ���������� üũ
	float prev = (float)clock() / CLOCKS_PER_SEC;

	// ���� ȭ�� ���
	Display* display = new Display();
	showConsoleCursor(false);


	// ���� ������ �ҷ��ͼ� ����
	GameEngine* gameengine = new GameEngine();
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
			gameengine->next(dt, 'd');
		}
		else if (down == true) {
			gameengine->next(dt, 's');
		}
		else if (rotate == true) {
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