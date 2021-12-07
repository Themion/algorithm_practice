#include <cstdio>

// cont[N]: N이 사이클에 포함되어 있는지 검사
bool cont[100];

int main() {
    // N: 사이클의 다음 수를 계산
    // ans: 출력할 사이클의 수를 저장한다
    int N, ans = 1;

    // 사이클의 첫 수를 입력받아 cont에 저장
    scanf("%d", &N);

    // 사이클에 포함된 수를 발견할 때까지 무한반복
    do {
        // N이 사이클에 등장했으므로 cont에 표시
        cont[N] = true;
        // 사이클에 포함될 수를 생성
        N = (N / 10 + N % 10) % 10 + (N % 10) * 10;
        // 생성된 수가 사이클에 없다면 ans에 1 추가
        ans += !cont[N];
    } while (!cont[N]);

    // 사이클의 크기는 ans과 같으므로 ans을 출력한다
    printf("%d\n", ans);

    return 0;
}
