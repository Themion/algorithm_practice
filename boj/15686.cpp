#include <algorithm>
#include <cstdio>
#include <vector>

#define MAX 0x3f3f3f3f

using namespace std;

typedef pair<int, int> p;

int N, M;
int town[50][50] = {{0,}};
// chik, home: 치킨집과 집의 각 좌표
vector<p> chik, home;
// dist[i]: i번째 치킨집에서 각 집까지의 맨하탄 거리
// v: 브루트 포스 시 고른 성분의 집합을 vector에 저장
vector<int> dist[13], v;

// a와 b의 최솟값, a - b의 절댓값
int min (int a, int b) { return a < b ? a : b; }
int diff (int a, int b) { return a > b ? a - b : b - a; }

// 두 점 a, b의 맨하탄 거리
int get_dist (p a, p b)
{ return diff(a.first, b.first) + diff(a.second, b.second); }

// dist에서 M개의 성분을 골라 치킨 거리를 계산
// cnt: 고른 성분의 수, start: 고를 수 있는 성분의 최솟값
int brute (int cnt, int start)
{
    // 치킨 거리를 계산할 땐 무한대, 성분을 고를 땐 0
    int ret = MAX * (cnt != M);

    // M개의 성분을 모두 고른 경우
    if (cnt == M) for (int i = 0; i < home.size(); i++)
    {
        int temp = MAX; // 성분에서 home[i]까지의 거리의 최솟값을 구한 뒤
        for (auto id: v) temp = min(temp, dist[id][i]);
        ret += temp;    // 이를 ret에 더한다
    }
    // M개의 성분을 골라야 하는 경우
    // cnt개를 골랐을 때 다음으로 고를 성분의 인덱스의 최댓값을 제한
    // 제한하지 않으면 M개를 다 고르지 않았음에도 불구하고
    // 인덱스가 chik.size()에 도달하는 경우가 생김
    else for (int i = start; i < chik.size() - (M - cnt - 1); i++) 
    {
        // 성분 i를 v에 포함시킨 뒤
        v.push_back(i);
        // 가능한 경우 중 가장 짧은 치킨 거리를 계산한 뒤
        ret = min(ret, brute(cnt + 1, i + 1));
        // 성분 i를 v에서 제거
        v.pop_back();
    }
    
    return ret;
}

int main ()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
    {
        scanf("%d", &town[i][j]);
        if (town[i][j] == 1) home.push_back(p(i, j));
        if (town[i][j] == 2) chik.push_back(p(i, j));
    }

    // 각 치킨집에서 집까지의 거리를 미리 계산
    for (int i = 0; i < chik.size(); i++) for (auto h: home)
        dist[i].push_back(get_dist(chik[i], h));

    // 브루트 포스로 치킨 거리를 계산한다
    printf("%d\n", brute(0, 0));

    return 0;
}