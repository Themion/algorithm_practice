#include <cstdio>
#include <vector>

using namespace std;

int main() {
    // N: 순열의 길이, K: 순열의 점프 크기
    int N, K, idx = 0;
    vector<int> v;
    // 문제의 조건을 입력받은 뒤 순열을 오름차순으로 채운다
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) v.push_back(i + 1);

    // 순열의 시작을 출력한 뒤
    printf("<");

    // 순열을 정해진 순서대로 탐색
    while (N--) {
        // 순열의 다음 값을 찾고
        idx = (idx + K - 1) % v.size();
        // 찾은 값을 형식에 맞게 출력한 뒤 순열에서 제거
        printf("%d%s", v[idx], N ? ", " : ">\n");
        v.erase(v.begin() + idx);
    }

    return 0;
}
