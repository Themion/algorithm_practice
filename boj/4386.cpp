#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

typedef pair<double, double> point;
typedef pair<double, pair<int, int>> edge; 

#define MAX_N 100
#define _y first
#define _x second
#define _A second.first
#define _B second.second
#define _C first

int parent[MAX_N + 1];

// root(node): node가 속한 트리의 루트 노드를 반환
int root(int node) { return (parent[node] && parent[node] % node) ? root(parent[node]) : node; }
// root(a, b): 두 노드 a와 b가 속한 트리의 루트 노드를 구해 정렬한 뒤
// 둘의 일치 여부를 반환
bool root(int &a, int &b)  {
    a = root(a);
    b = root(b);
    if (a > b) swap(a, b);

    return a == b;
}

int main() {
    // 최소 스패닝 트리의 가중치
    double ans = 0;
    // n: 노드의 수, size: 에지의 개수
    int n, size = 0;
    // 각 노드의 좌표
    point p[MAX_N];
    // 에지를 저장할 공간
    edge e[MAX_N * (MAX_N - 1) / 2];

    // 문제의 조건을 입력받은 뒤
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lf %lf", &(p[i]._y), &(p[i]._x));

    // 노드를 잇는 에지를 모두 만들어 e에 저장
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++)
        e[size++] = {sqrt(pow(p[i]._y - p[j]._y, 2) + pow(p[i]._x - p[j]._x, 2)), {i + 1, j + 1}};

    // 에지를 가중치의 오름차순으로 정렬
    sort(e, e + size);

    // 모든 에지를 이용해 최소 스패닝 트리를 구현
    for (int i = 0; i < size; i++) {
        // 현재 에지의 노드를 root 함수를 이용해 루트 노드로 변환
        if (root(e[i]._A, e[i]._B)) continue;
        // 두 트리를 연결한 뒤 루트를 명시하고 가중치를 ans에 더한다
        parent[e[i]._B] = e[i]._A;
        ans += e[i]._C;
    }

    // 최소 스패닝 트리의 가중치를 출력
    printf("%.2lf\n", ans);

    return 0;
}
