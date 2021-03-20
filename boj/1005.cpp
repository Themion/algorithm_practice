#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

//t[k]: k번쨰 건물을 짓는 데 걸리는 시간
int t[1000];
//time[k]: k번째 건물을 짓는 데 걸리는 총 최소 시간
vector<ll> time;
//ord[a]: a번째 건물을 짓기 위해 필요한 건물의 집합
vector<vector<int>> ord;

//time[idx]를 함수를 이용해 접근한다
ll getTime(int idx)
{
    //time[idx]를 매번 배열에서 접근하면 시간이 너무 오래 걸리므로
    //레퍼런스를 이용해 접근 시간을 줄인다
    ll &ret = time[idx];

    //time[idx]가 초기값이라면
    if (ret == -1)
    {
        //ret을 0으로 초기화한 뒤
        ret = 0;
        //idx번째 건물을 짓기 위한 모든 건물에 대해 
        //각각 총 최소 시간 중 가장 큰 값을 ret에 대입한 뒤
        if (ord[idx].size() != 0) for (auto i : ord[idx])
                ret = max(ret, getTime(i));
        //time[idx]에 idx번째 건물을 짓는 시간을 더한다
        ret += t[idx];
    }

    //ret을 반환한다
    return ret;
}

int main()
{
    //tc: 테스트 케이스의 수
    //N: 각 테스트 케이스에서 건물의 수, K: 각 테스트 케이스에서 규칙의 수
    //X, Y: Y 건물을 짓기 위해서는 X 건물을 먼저 지어야 한다
    //W: 짓고자 하는 건물의 번호
    int tc, N, K, X, Y, W;

    scanf("%d", &tc);
    while (tc--)
    {
        //N과 K를 입력받고 거기에 맞춰 time과 ord를 초기화한다
        scanf("%d %d", &N, &K);
        time = vector<ll>(N, -1);
        ord = vector<vector<int>>(N);

        //t와 ord를 입력받은 뒤
        for (int i = 0; i < N; i++) scanf("%d", &t[i]);
        for (int i = 0; i < K; i++)
        {
            scanf("%d %d", &X, &Y);
            ord[Y - 1].push_back(X - 1);
        }

        //W를 입력받아
        scanf("%d", &W);
        //W를 짓는 데까지 걸리는 시간을 getTime을 이용해 구한다
        printf("%lld\n", getTime(W - 1));
    }

    return 0;
}