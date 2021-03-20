#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> p, n;

int main()
{
    // N: 책의 수, M: 한번에 옮길 수 있는 책의 수
    // ans: 최소 걸음의 수, idx: 위치가 양수/음수인 배열의 인덱스
    int N, M, ans = 0, idx[2] = {0, 0};
    scanf("%d %d", &N, &M);

    // 각 책에 대해
    for (int i = 0; i < N; i++)
    {
        // 책의 원래 위치를 입력받은 뒤
        scanf("%d", &ans);
        // 위치가 양수라먼 p에, 음수라면 n에 push
        (ans > 0 ? p : n).push_back(ans);
    }

    // 빈 배열이 있다면 그 배열에 0을 push
    if (p.empty()) p.push_back(0);
    if (n.empty()) n.push_back(0);

    // 처음 위치로부터 거리가 먼 순으로 정렬
    sort(p.begin(), p.end(), [](int a, int b) { return a > b; });
    sort(n.begin(), n.end(), [](int a, int b) { return a < b; });

    // 초기 상태에서 걸음의 수는 0
    ans = 0;
    // 거리가 먼 순으로 M개의 책을 차례로 가져다 놓고 돌아온다
    while (idx[0] < p.size())
    {
        ans += 2 * p[idx[0]];
        idx[0] += M;
    }
    while (idx[1] < n.size())
    {
        ans -= 2 * n[idx[1]];
        idx[1] += M;
    }

    // 거리가 가장 먼 곳은 책을 가져다 둔 뒤 돌아올 필요가 없으므로
    // 해당 거리만큼 ans에서 빼 준다
    ans -= p[0] > -n[0] ? p[0] : -n[0];

    // 정답을 출력
    printf("%d\n", ans);

    return 0;
}