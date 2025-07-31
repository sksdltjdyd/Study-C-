#include "Display.h"

void Display::draw() {
	for (int i = 0; i < GRID_HEIGHT; i++)
	{
		for (int k = 0; k < GRID_WIDTH; k++)
		{
			// drawPosition(k, i, displayData[i][k] == 1); --> 같은 의미
			if (displayData[i][k] == 0)
			{
				// 해당 좌표에 값이 없으면 빈 네모를 그린다
				drawPosition(k, i, false);
			}
			else
			{
				// 그렇지 않으면 색깔 네모를 그린다
				drawPosition(k, i, true);
			}
		}
	}
}