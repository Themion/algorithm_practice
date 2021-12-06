#include <cstdio>

#define MAX 50

int M, N;
bool field[MAX][MAX];

// 양배추 군집의 모든 양배추를 찾기 위해 dfs 사용
bool dfs(int y, int x) {
    // 현재 위치의 양배추를 탐색한 뒤
    field[y][x] = false;

    // 인접한 곳에 양배추가 있다면 재귀를 통해 탐색
    if((x - 1 >= 0) && field[y][x - 1]) dfs(y, x - 1);
    if((y - 1 >= 0) && field[y - 1][x]) dfs(y - 1, x);
    if((x + 1 < M) && field[y][x + 1]) dfs(y, x + 1);
    if((y + 1 < N) && field[y + 1][x]) dfs(y + 1, x);

    // 군집 탐색을 완료했으므로 true 반환
    return true;
}

// 각 테스트 케이스를 실행할 함수
int test_case(int K) {
    // X, Y: 밭의 각 칸을 지정할 인덱스, ret: 양배추 군집의 수
    int X, Y, ret = 0;

    // 심은 양배추의 수만큼 양배추의 위치를 입력받아 희소행렬 꼴로 저장
    while (K--) {
        scanf("%d %d", &X, &Y);
        field[Y][X] = true;
    }

    //모든 칸을 찾아보면서 해당 칸에 양배추가 있다면 깊이 우선 탐색을 실행
    for (Y = 0; Y < N; Y++) for (X = 0; X < M; X++)
        if (field[Y][X]) ret += dfs(Y, X);

	// 양배추 군집의 수를 반환
    return ret;
}

int main() {
    // T: 테스트 케이스의 수, K: 양배추의 수
    int T, K;

    // 테스트 케이스의 수를 입력받은 뒤
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d", &M, &N, &K);
        printf("%d\n", test_case(K));
    }

    return 0;
}