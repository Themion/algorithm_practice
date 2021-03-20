#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> coord;

#define MAX 0x3f3f3f3f
#define _y first
#define _x second

int abs(int num) { return num > 0 ? num : -num; }
int min(int a, int b) { return a < b ? a : b; }
void set_min(int&a, int b) { a = a < b ? a : b; }
void set_max(int& a, int b) { a = a > b ? a : b; }

int main()
{
    int N, M, buf, ans = 0;
    vector<coord> v;

    scanf("%d %d", &N, &M);
    
    // 상어가 있는 좌표를 v에 저장
    for (int y = 0; y < N; y++) for (int x = 0; x < M; x++)
    {
        scanf("%d", &buf);
        if (buf) v.push_back({y, x});
    }

    // 각 좌표에서 가장 가까운 상어까지의 거리를 계산
    for (int y = 0; y < N; y++) for (int x = 0; x < M; x++)
    {
        int dist = MAX;
        
        // 각 상어까지의 거리 중 가장 작은 값을 dist에 저장
        for (auto c: v) set_min(dist, max(abs(y - c._y), abs(x - c._x)));
        // ans에 dist의 최댓값을 저장
        set_max(ans, dist);
    }

    // 가장 안전한 곳의 좌표를 출력
    printf("%d", ans);

    return 0;
}