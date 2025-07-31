#ifndef __MAINHEADER_H__
#define __MAINHEADER_H__


#define _CRT_SECURE_NO_WARNINGS

#include "TetrisHelper.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

// 게임 공간 사이즈 설정
#define GRID_WIDTH 7
#define GRID_HEIGHT 10

// 3x3 크기의 사용 블록 사이즈 설정
#define USERBLOCK_SIZE 3

// 게임 실행시 화면에 뜨는 게임 화면 크기 설정
extern int displayData[GRID_HEIGHT][GRID_WIDTH];

#endif // !__MAINHEADER_H__