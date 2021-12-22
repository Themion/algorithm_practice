#include <cstdio>

#define MAX 10000

int main() {
    // chk[i]: d(x) = i인 x가 존재한다면 true, 아니라면 false
	bool chk[MAX + 1] = { false, };
    // n, d_n: n을 생성자로 d_n을 생성
	int n, d_n;

    // 1부터 모든 수에 대해
	for (int i = 1; i <= MAX; i++) {
        // 생성자를 이용해 i를 만들었다면 d(i) 역시 만들었으므로 continue
		if (chk[i]) continue;

        // i에서 시작해 d(i)를 반복적으로 계산
		n = d_n = i;

        // 생성자가 MAX보다 작을 때
		while (n <= MAX) {
            // 생성자 n을 이용해 d(n)을 만든다
			while (n) {
				d_n += n % 10;
				n /= 10;
			}
            // d_n이 출력 범위 내에 있을 때 d_n이 셀프 넘버가 아님을 표시
			if (d_n <= MAX) chk[d_n] = true;
            // d_n을 생성자로 하는 d(n)을 다시 만든다
            n = d_n;
		}
	}

    // 범위 [1, MAX] 안의 셀프 넘버를 모두 출력
	for (int i = 1; i <= MAX; i++) if (!chk[i]) printf("%d\n", i);

    return 0;
}
