#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<double, double> point;
typedef pair<double, pair<int, int>> edge; 

#define MAX_N 1000
#define _y first
#define _x second
#define _A second.first
#define _B second.second
#define _C first

int n;
int parent[MAX_N + 1];
vector<point> vp;
vector<edge> v;

// root(node): node가 속한 트리의 루트 노드를 반환
int root(int node) { return (parent[node] && parent[node] % node) ? root(parent[node]) : node; }
// root(a, b): 두 노드 a와 b가 속한 트리의 루트 노드를 구해 정렬한 뒤
// 둘의 일치 여부를 반환
bool root(int &a, int &b) 
{
    a = root(a);
    b = root(b);
    if (a > b) swap(a, b);

    return a == b;
}

int main()
{
    // 별자리를 이루는 그래프의 가중치의 합
    double ans = 0;

    // 두 배열 vp, v의 길이는 모두 n에 의해 결정된다
    // n을 입력받은 뒤 vp, v, it을 초기화
    scanf("%d", &n);
    vp = vector<point>(n);
    v = vector<edge>(n * (n - 1) / 2);
    // v를 순회할 때 사용할 변수
    auto it = v.begin();

    // 모든 별의 좌표를 입력받은 뒤
    for (point &p : vp) scanf("%lf %lf", &(p._y), &(p._x));
    // 각 별에 번호를 매기고 별과 별 사이의 거리를 계산해 에지로 만들어 v에 push
    for (int i = 0; i < vp.size(); i++) for (int j = i + 1; j < vp.size(); j++)
        *it++ = {sqrt(pow(vp[i]._y - vp[j]._y, 2) + pow(vp[i]._x - vp[j]._x, 2)), {i + 1, j + 1}};

    // 에지를 가중치의 오름차순으로 정렬
    sort(v.begin(), v.end());

    // 모든 에지를 이용해 최소 스패닝 트리를 구현
    for (edge e : v)
    {
        // 현재 에지의 노드를 root 함수를 이용해 루트 노드로 변환
        if (root(e._A, e._B)) continue;
        // 두 트리를 연결한 뒤 루트를 명시하고 가중치를 ans에 더한다
        parent[e._B] = e._A;
        ans += e._C;
    }

    // 최소 스패닝 트리의 가중치를 출력
    printf("%.2lf\n", ans);

    return 0;
}