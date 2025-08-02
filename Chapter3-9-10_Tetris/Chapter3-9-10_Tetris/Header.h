#ifndef __MAINHEADER_H__
#define __MAINHEADER_H__


#define _CRT_SECURE_NO_WARNINGS

#include "TetrisHelper.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

// ���� ���� ������ ����
#define GRID_WIDTH 7
#define GRID_HEIGHT 10

// 3x3 ũ���� ��� ��� ������ ����
#define USERBLOCK_SIZE 3

// ���� ����� ȭ�鿡 �ߴ� ���� ȭ�� ũ�� ����
extern int displayData[GRID_HEIGHT][GRID_WIDTH];

#endif // !__MAINHEADER_H__