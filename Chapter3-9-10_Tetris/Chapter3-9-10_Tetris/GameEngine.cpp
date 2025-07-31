#include "GameEngine.h"

void GameEngine::init()
{
	// 최초 게임 엔진 초기화 과정
	makeuserblock();
}

// 메인함수 while루프에서 매번 불러져서 어떤 동작을 할지 확인하는 함수
void GameEngine::next(float dt, char keyboardInput)
{
	// 메인함수 루프에서 매번 불려지는 함수
	if (state == GameState::GAMEOVER) return;

	elapsed = elapsed + dt;
	if (elapsed >= 0.5f)
	{
		if (CanGoDown()) {
			// can go down 함수가 참이면 블록 위치가 계속 더해져서 내려간다
			blocky++;
		}
		else
		{
			// userblock을 gamegrid data에 전사
			trans();
			// 게임오버 함수가 참이면 게임오버 상태 설정
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

// 블록이 아래로 내려갈 수 있나
bool GameEngine::CanGoDown() {
	for (int i = 0; i < USERBLOCK_SIZE; i++)
	{
		for (int k = 0; k < USERBLOCK_SIZE; k++) {
			if (userBlock[i][k] == 1 && i + blocky + 1 >= GRID_HEIGHT) {
				// 전사된 그리드의 블록이 존재하고 블록의 y축 위치 + 1이 전사된 그리드 높이보다 크면 더 내려가지 않는다
				return false;
			}
			if (userBlock[i][k] == 1 && gameGridData[i + blocky + 1][k + blockx] == 1) {
				//  전사된 그리드의 블록이 존재하고 현재 전사된 그리드의 블록 바로 아래에 블록이 있다면 더 내려가지 않는다
				return false;
			}
		}
	}
	// 두가지 경우가 아니면 내려간다
	return true;
}

// 블록이 왼쪽으로 갈 수 있나
bool GameEngine::CanGoLefet() {
	for (int i = 0; i < USERBLOCK_SIZE; i++)
	{
		for (int k = 0; k < USERBLOCK_SIZE; k++) {
			if (userBlock[i][k] == 1 && k + blockx - 1 < 0) {
				// 블록이 움직인 위치에 블록이 존재하거나 블록 위치를 k축으로 1 뺐더니 0보다 작으면 전사된 배열을 벗어나는거므로 움직이면 안됀다
				return false;
			}
			if (userBlock[i][k] == 1 && gameGridData[i + blocky][k + blockx - 1] == 1) {
				// 블록이 움직인 위치에 블록이 존재하거나 전사된 데이터의 블록 위치의 왼쪽에 블록이 있다면 움질일 수 없다
				return false;
			}
		}
	}
	// 두가지 경우가 아니면 왼쪽으로 움직인다
	return true;
}

// 블록이 오른쪽으로 갈 수 있나
bool GameEngine::CanGoRight() {

	for (int i = 0; i < USERBLOCK_SIZE; i++)
	{
		for (int k = 0; k < USERBLOCK_SIZE; k++) {
			if (userBlock[i][k] == 1 && k + blockx + 1 > GRID_WIDTH - 1) {
				// 블록의 움직인 위치에 블록이 존재하거나 블록 위치를 k축으로 1 더했더니 배열그리드 넓이에서 1 뺀것보다 크면 배열을 벗어나는것이므로 움직일 수 없다
				return false;
			}
			if (userBlock[i][k] == 1 && gameGridData[i + blocky][k + blockx + 1] == 1) {
				// 블록의 움직인 위치에 블록이 존재하거나 전사된 데이터의 블록 위치에 블록이 있다면 움질일 수 없다
				return false;
			}
		}
	}
	// 두가지 경우가 아니면 오른쪽으로 움직인다
	return true;
}

// 줄이 가득차있는지 확인
bool GameEngine::isLineFilled(int y) {
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		// 가득 차 있다면 한칸이라도 0이면 안되기에 지워지면 안됀다
		if (gameGridData[y][i] == 0) return false;
	}
	return true;
}

// 가득차 있는 라인을 지운다
void GameEngine::eraseLine(int y) {
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		// y번째 줄 라인을 전부 지운다
		gameGridData[y][i] = 0;
	}
}

// 라인을 지운 뒤 y 좌표를 기준으로 한칸씩 아래로 내림
void GameEngine::drop(int y) {
	for (int i = y; i >= 0; i--)
	{
		for (int k = 0; k < GRID_WIDTH; k++) {
			// 전사된 블록에 i - 1 위치에 넣었는데 그 값이 0보다 작다면 배열 그리드를 벗어나는것이므로 그냥 0을 넣고 그게 아니라면 한칸씩 땡긴 값을 넣는다
			gameGridData[i][k] = i - 1 < 0 ? 0 : gameGridData[i - 1][k];
		}
	}
}

// 유저블록을 그리드에 전사하는 함수
void GameEngine::trans() {
	for (int i = 0; i < USERBLOCK_SIZE; i++)
	{
		for (int k = 0; k < USERBLOCK_SIZE; k++) {
			int _x = k + blockx;
			int _y = i + blocky;
			// 둘다 아닐 시, 유저블록이 게임 화면 안에 있는것이므로 데이터를 넣어준다
			// 디스플레이데이터 x,y좌표가 기존에 0인지 1인지 판단을 해서 1이면 유저블록 x,y좌표를 넣어주고 0이면 새로운 블록 데이터를 넣어준다
			// gameGridData[i + blocky][k + blockx] = userBlock[i][k] == 1 ? userBlock[i][k] : gameGridData[i + blocky][k + blockx];
			gameGridData[_y][_x] = userBlock[i][k] | gameGridData[_y][_x];
		}
	}
	// 한 줄이 가득차 있는지 확인
	for (int i = 0; i < GRID_HEIGHT; i++)
	{
		if (isLineFilled(i)) {
			// 라인이 가득차면 가득 찬 라인을 지우고 블록을 한칸씩 떙긴다
			eraseLine(i);
			drop(i);
		}
	}
	// 블록 생성
	makeuserblock();
}

// 게임 종료 조건 설정
bool GameEngine::gameoverDecision() {
	for (int i = 0; i < USERBLOCK_SIZE; i++)
	{
		for (int k = 0; k < USERBLOCK_SIZE; k++) {
			if (userBlock[i][k] == 1 && gameGridData[i + blocky][k + blockx] == 1) {
				// 유저블록의 위치에 블록이 있고 전사된 그리드 데이터에 블록이 존재하면 참 
				return true;
			}
		}
	}
	return false;
}

// 새로운 블록 생성
void GameEngine::makeuserblock() {
	// 블록이 최초 생성되는 위치 설정
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

void GameEngine::rotate() {
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

// display data를 전역으로 설정한 디스플레이 데이터를 전사해주는 함수
	// 실제 게임 데이터를 화면에 출력 할 수 있는 데이터로 바꿔주는 함수
	// 게임 그리드 데이터와 유저들이 사용하는 블록의 데이터로 정해진다
void GameEngine::makedisplaydata()
{
	for (int i = 0; i < GRID_HEIGHT; i++)
	{
		for (int k = 0; k < GRID_WIDTH; k++)
		{
			// 게임 그리드 데이터를 넣어주는것
			displayData[i][k] = gameGridData[i][k];
		}
	}

	// 유저블록의 데이터를 넣어주는 루프
	for (int i = 0; i < USERBLOCK_SIZE; i++)
	{
		for (int k = 0; k < USERBLOCK_SIZE; k++)
		{
			if (i + blocky < 0 || i + blocky > GRID_HEIGHT)
			{
				// 유저블록의 y좌표가 0보다 작거나 설정한 그리드 높이보다 크면 화면을 넘어서는것이므로 아무것도 하지 않는다
			}
			else if (k + blockx < 0 || k + blockx > GRID_WIDTH)
			{
				// 유저블록의 x좌표가 0보다 작거나 설정한 그리드 넓이보다 크면 화면을 넘어서는것이므로 아무것도 하지 않는다
			}
			else
			{
				// 둘다 아닐 시, 유저블록이 게임 화면 안에 있는것이므로 데이터를 넣어준다
				// 디스플레이데이터 x,y좌표가 기존에 0인지 1인지 판단을 해서 1이면 유저블록 x,y좌표를 넣어주고 0이면 새로운 블록 데이터를 넣어준다
				int _x = k + blockx;
				int _y = i + blocky;
				//displayData[_y][_x] = userBlock[i][k] == 1 ? userBlock[i][k] : displayData[_y][_x];
				displayData[_y][_x] = userBlock[i][k] | displayData[_y][_x]; // 같은 표현
			}
		}
	}
}
