#include <cstdio>
#include <map>

using namespace std;

int N, M, arr[10];
map<int, bool> m;

void backtrack(int idx, map<int, bool>::iterator it)
{
    // 수열의 길이가 최대치에 도달했다면 수열을 출력
    if (idx == M) 
    {
        for (int i = 0; i < M; i++) printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    // 수열을 이룰 수 있는 각 수를 arr에 넣어 백트래킹
    for (auto i = it; i != m.end(); i++) if (m[i->first])
    {
        arr[idx++] = i->first;
        backtrack(idx, i);
        arr[idx--] = 0;
    }
}

int main()
{
    int buf;
    scanf("%d %d", &N, &M);
    
    // 서로 다른 원소가 등장했는지 여부만 파악하면 되므로
    // map에 원소를 저장한다
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &buf);
        m[buf] = true;
    }

    backtrack(0, m.begin());

    return 0;
}