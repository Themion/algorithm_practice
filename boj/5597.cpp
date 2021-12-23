#include <cstdio>

#define N 30

int main() {
    // ans[i]: i번째 학생이 과제를 제출했다면 true, 아니라면 false
	bool ans[N] = { false, };
    // 입력을 ans에 바꿔서 저장하기 위한 변수
	int buf;

    // 과제를 제출한 학생의 출석번호를 받아 ans에 표시
	for (int i = 2; i < N; i++) {
		scanf("%d", &buf);
		ans[buf - 1] = true;
	}

    // 과제를 제출하지 않은 학생의 출석번호를 반환
	for (int i = 0; i < N; i++) if (!ans[i]) printf("%d\n", i + 1);

    return 0;
}
