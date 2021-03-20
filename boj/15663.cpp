#include <cstdio>
#include <map>

using namespace std;

int N, M, arr[10];
map<int, int> m;

void backtrack(int idx)
{
    // 수열의 길이가 최대치에 도달했다면 수열을 출력
    if (idx == M) 
    {
        for (int i = 0; i < M; i++) printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    // 수열을 이룰 수 있는 각 수를 arr에 넣어 백트래킹
    for (auto i = m.begin(); i != m.end(); i++) if (m[i->first])
    {
        m[i->first]--;
        arr[idx++] = i->first;
        backtrack(idx);
        arr[idx--] = 0;
        m[i->first]++;
    }
}

int main()
{
    int buf;
    scanf("%d %d", &N, &M);
    
    // 중복된 수는 존재할 수 있으나 중복된 수열은 존재할 수 없으므로
    // 각 원소를 map에 저장한다
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &buf);
        m[buf]++;
    }

    backtrack(0);

    return 0;
}