#include "Header.h"
#define INTERVAL 1.0 / 60.0 // 60���������� ����� ���� ���͹��� 1/60�ʷ� ����

int main() {

	// ������ ����� ���� ������ �ð��� ���������� üũ
	float prev = (float)clock() / CLOCKS_PER_SEC;

	// ���� ȭ�� ���
	Display* display = new Display();
	showConsoleCursor(false);


	// ���� ������ �ҷ��ͼ� ����
	GameEngine* gameengine = new GameEngine();

	while (true)
	{
		float cur = (float)clock() / CLOCKS_PER_SEC;

		// Delta time�� ���� ���� ���� �ð��� ���� �ȿ����� �ð��� ���� ���ϱ�
		float dt = cur - prev;

		if (dt < INTERVAL) continue; // ��Ÿ Ÿ���� 1/60�ʺ��� ������ ����
		prev = cur;

		// ����Ű ����
		bool left = keyState('a');
		if (left = true) 
		{
			// �������� ��� �̵�
		}
		else 
		{
			// ��� ������
		}

		bool right = keyState('d');

		gameengine->next(dt, 0);

		// ȭ�� ���
		gameengine->makedisplaydata();
		display->draw();

		// ���� ���� �Ǻ�
		
	}

	return 0;
}