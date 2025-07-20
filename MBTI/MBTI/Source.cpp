#include "Header.h"

int main() {

	int i_e;
	int s_n;
	int t_f;
	int j_p;

	printf("MBTI 검사를 시작합니다.\n");

	i_e = GetQuestion("나는 처음 보는 사람에게 자신을 소개하는것이 두렵지 않다", -3, -1, 1, 3);
	i_e = i_e + GetQuestion("내가 스트레스 푸는 방법은 사람들을 만나는 것이다", -3, -1, 1, 3);
	i_e = i_e + GetQuestion("맞장구 치는것보다 대화를 시작하는걸 좋아한다", -3, -1, 1, 3);
	i_e = i_e + GetQuestion("술자리에서 노는데 집에서 게임하는것보다 좋다", -3, -1, 1, 3);

	s_n = GetQuestion("업무를 하거나 과제를 할 때 계획을 먼저 세운다", -3, -1, 1, 3);
	s_n = s_n + GetQuestion("가끔 번뜩이는 아이디어가 생각나 메로를 하곤 한다", -3, -1, 1, 3);
	s_n = s_n + GetQuestion("가끔 비현실적인 망상을 하는 편 이다", -3, -1, 1, 3);
	s_n = s_n + GetQuestion("나는 내성적인 성격이다", -3, -1, 1, 3);

	t_f = GetQuestion("상대방의 고민을 들어줄 때 원인을 찾기보다 공감을 해주는 편 이다", -3, -1, 1, 3);
	t_f = t_f + GetQuestion("어떤 이유에서건 상대방의 기분을 먼저 생각해야 한다", -3, -1, 1, 3);
	t_f = t_f + GetQuestion("다른 사람들이 나를 어떻게 생각하는지 지나치게 생각한다", -3, -1, 1, 3);
	t_f = t_f + GetQuestion("뮤지컬이나 예술작품이 영화나 드라마보다 더 많은 영감을 준다", -3, -1, 1, 3);

	j_p = GetQuestion("방 정리가 되어있지 않으면 일을 시작할 수 없다", -3, -1, 1, 3);
	j_p = j_p + GetQuestion("과제나 업무는 최대한 미루었다가 한꺼번에 하는 편 이다", -3, -1, 1, 3);
	j_p = j_p + GetQuestion("호기심은 나를 움직이는 원동력이다", -3, -1, 1, 3);
	j_p = j_p + GetQuestion("프리랜서가 회사원보다 더 나은 삶을 살고 있다고 생각한다", -3, -1, 1, 3);\

	PrintResult(i_e, s_n, t_f, j_p);

	return 0;
}

// 질문 받는 함수
int GetQuestion(const char* q, int v1, int v2, int v3, int v4) {
	int input;
	int result = 0;
	for (;;) {
		printf("%s\n", q);
		printf("1. 강한 부정 2. 약한 부정 3. 약한 긍정 4. 강한 긍정 : ");
		fseek(stdin, 0, SEEK_END);
		scanf("%d", &input);
		if (input == 1) {
			result = v1;
			break;
		}
		else if (input == 2) {
			result = v2;
			break;
		}
		else if (input == 3) {
			result = v3;
			break;
		}
		else if (input == 4) {
			result = v4;
			break;
		}
		else {
			printf("잘못된 입력입니다. 다시 시도하세요.\n");
			continue;
		}
	}
	return result;
}

// 결과 출력 함수
void PrintResult(int v1, int v2, int v3, int v4) {
	if (0 > v1 && 0 > v2 && 0> v3 && 0 > v4) {
		printf("당신은 ISTJ, 논리주의자입니다");
	}
	else if (0 > v1 && 0 > v2 && 0 <= v3 && 0 > v4) {
		printf("당신은 ISFJ, 조용하고 차분하며 친근합니다. 가장 믿음직스러운 사람입니다");
	}
	else if (0 > v1 && 0 <= v2 && 0 > v3 && 0 > v4) {
		printf("당신은 INFJ, 인내심이 많고 사람들을 좋아합니다. 눈치가 빠르고 영감이 있습니다");
	}
	else if (0 > v1 && 0 <= v2 && 0 > v3 && 0 > v4) {
		printf("당신은 INTJ, 논리적이고 효율성을 중시하는 냉철한 사람입니다");
	}
	else if (0 > v1 && 0 > v2 && 0 > v3 && 0 <= v4) {
		printf("당신은 ISTP, 조용하고 과묵하고 손재주가 있는 공학자 스타일입니다");
	}
	else if (0 > v1 && 0 > v2 && 0 > v3 && 0 <= v4) {
		printf("당신은 ISFP, 다정하고 착하고 상대방에 대한 배려심이 많습니다. 주위 사람들에게 많이 휩쓸리는 성격입니다");
	}
	else if (0 > v1 && 0 <= v2 && 0 <= v3 && 0 <= v4) {
		printf("당신은 INFP, 당신은 정열적이고 완벽을 추구하며 유토피아를 추구하는 성격입니다");
	}
	else if (0 > v1 && 0 <= v2 && 0 > v3 && 0 <= v4) {
		printf("당신은 INTP, 당신은 조용하고 과묵하며 상상을 즐기는 사색가입니다. 사회성이 부족하다는 말을 많이 듣습니다");
	}
	else if (0 <= v1 && 0 > v2 && 0 > v3 && 0 <= v4) {
		printf("당신은 ESTP, 당신은 활동하는것을 좋아하는 사업가형 입니다");
	}
	else if (0 <= v1 && 0 > v2 && 0 <= v3 && 0 <= v4) {
		printf("당신은 ESFP, 당신은 자유로운 영혼을 갖고 있는 연예인 스타일입니다");
	}
	else if (0 <= v1 && 0 <= v2 && 0 <= v3 && 0 <= v4) {
		printf("당신은 ENFP, 당신은 넘치는 상상력을 바탕으로 항상 새로운 가능성을 찾아보는 탐험가입니다");
	}
	else if (0 <= v1 && 0 <= v2 && 0 > v3 && 0 <= v4) {
		printf("당신은 ENTP, 당신은 논쟁을 즐기며 사람을 만나는 것을 좋아합니다");
	}
	else if (0 <= v1 && 0 > v2 && 0 > v3 && 0 > v4) {
		printf("당신은 ESTJ, 현설적, 구체적이고 사실적이며 조직을 이끌어나가는 리더형입니다");
	}
	else if (0 <= v1 && 0 > v2 && 0 <= v3 && 0 > v4) {
		printf("당신은 ESFJ, 동정심이 많고 다른 사람에게 관심을 주는 것을 좋아하며 협력을 좋아하고 동료애가 끈끈합니다");
	}
	else if (0 <= v1 && 0 <= v2 && 0 <= v3 && 0 > v4) {
		printf("당신은 ENFJ, 당신은 따듯하고 적극적이며 사교성이 풍부하고 이타적입니다");
	}
	else {
		printf("당신은 열정적이며 솔직하고 지도력과 통솔력이 있습니다. 활동적이고 장기적인 계획을 좋아합니다");
	}
	
}


