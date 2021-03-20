#include <cstdio>

//노드의 수
int size;
//graph: 그래프, virus[i]: i번 노드를 방문했다면 true, 그렇지 않다면 false
bool graph[100][100] = {{ false, }}, virus[100] = { false, };

void dfs(int node)
{
    //node와 연결된 임의의 노드 i에 대해 그 노드를 방문하지 않았다면
    for (int i = 0; i < size; i++)
        if ((graph[node][i] || graph[i][node]) && !virus[i])
        {
            //노드에 연결된 에지를 해제한 뒤
            graph[node][i] = false;
            graph[i][node] = false;
            //바이러스를 전파하고
            virus[i] = true;
            //전파한 노드에 대해 dfs
            dfs(i);
        }
}

int main()
{
    //temp: 아무렇게나 쓰는 변수
    //a, b: 그래프를 입력받을 때 사용할 변수
    int temp, a, b;

    //컴퓨터의 수와 그래프를 입력받는다
    scanf("%d\n%d", &size, &temp);
    while (temp--)
    {
        scanf("%d %d", &a, &b);
        a--; b--;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    //0번 컴퓨터가 바이러스에 걸렸으므로 dfs를 통해 바이러스 전파
    virus[0] = true;
    dfs(0);

    //temp를 바이러스에 걸린 컴퓨터 수로 사용
    temp = 0;
    //0번 컴퓨터를 제외하고 바이러스에 걸린 컴퓨터의 수를 계산
    for (int i = 1; i < size; i++) temp += virus[i];
    //계산한 수를 출력
    printf("%d\n", temp);

    return 0;
}