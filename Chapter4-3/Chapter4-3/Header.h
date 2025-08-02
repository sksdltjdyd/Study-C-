#ifndef __MAINHEADER_H__
#define __MAINHEADER_H__

/*
매크로의 컴파일
- 매크로는 소스파일당 한번만 유효하다
- 매크로가 소스파일 전체에 걸쳐있는것이 아니라 include 되어 포함되거나, 혹은 소스파일 그 자체에 있는 매크로가 소스파일 단위로 동작하게 된다
- 즉, 이에 따라 ifndef 헤더 파일 가드 같은것도 소스파일별로 이루어지게 된다
*/
#define _CRT_SECURE_NO_WARNINGS

#include "TetrisHelper.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>


/*
소스파일 - 오브젝트 파일
- 소스파일은 컴파일이 될 때 소스파일 하나하나가 오브젝트 파일을 생성하게 된다[cpp -> obj]
- 맥이나 리눅스의 경우 .o 파일이 된다
- C++의 컴파일은 이렇게 만들어진 obj 파일을 묶어서 하나의 실행파일을 만들어내게 된다
*/

/*
## LNK 에러
- C++에서 LNK로 시작하는 오류는 컴파일은 성공했지만, 여러 코드 조각들을 최종 실행 파일(.exe)로 합치는 링크(Link) 단계에서 문제가 발생했다는 신호
- 쉽게 비유하자면, 개별 부품(소스 파일)을 만드는 데는 성공했지만, 이 부품들을 조립(링크)하여 완성품(실행 파일)을 만드는 과정에서 부품이 없거나, 맞지 않거나, 중복되는 등의 문제가 생긴 것

## LNK 오류의 핵심 원리
- C++ 빌드는 크게 컴파일과 링크 두 단계로 이루어진다
- 컴파일(Compile): 각 소스 파일(.cpp)을 기계어로 번역하여 목적 파일(.obj)을 만든다. 이때 컴파일러는 헤더 파일(.h)의 **선언(declaration)**만 보고 "이런 함수가 어딘가에 있겠지"라고 믿고 넘어간다
- 링크(Link): 컴파일러가 만든 모든 목적 파일(.obj)과 라이브러리 파일(.lib)을 모아 서로에게 필요한 함수나 변수의 **정의(definition)**를 찾아 연결하고, 하나의 실행 파일(.exe)로 묶는다
- LNK 오류는 바로 이 2단계, 링크 과정의 실패를 의미
*/

/*
에러 코드 고치는법
- 에러 코드를 천천히 보면 함수 이름이 반드시 나온다. 그 함수를 따라가서 고치면 반드시 해결이 된다
- 
*/

// 게임 공간 사이즈 설정
#define GRID_WIDTH 7
#define GRID_HEIGHT 10

// 3x3 크기의 사용 블록 사이즈 설정
#define USERBLOCK_SIZE 3

// 게임 실행시 화면에 뜨는 게임 화면 크기 설정
extern int displayData[GRID_HEIGHT][GRID_WIDTH];

#endif // !__MAINHEADER_H__