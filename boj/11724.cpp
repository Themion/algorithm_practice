#include <cstdio>

//입력받은 그래프를 2차원 배열로 저장한다
bool graph[1001][1001];
//N: 그래프의 노드의 수, M: 그래프의 간선 수
int N, M;

void dfs(int node)
{
    //node를 방문했음을 표시한 뒤
	graph[node][node] = false;
    //node와 연결되어 있고 방문하지 않은 노드가 있다면
	for (int i = 1; i <= N; i++) 
        if (graph[node][i] && graph[i][i])
            //해당 노드를 방문한다
            dfs(i);
}

int main()
{
    //t1, t2: 그래프를 입력받을 때 사용할 변수
	int t1, t2, ret = 0;

    //그래프를 입력받는다
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &t1, &t2);
		graph[t1][t2] = true;
		graph[t2][t1] = true;
	}

    //그래프의 각 노드는 연결된 에지가 없더라도 그 자체로 연결 요소이다
    for (int i = 1; i <= N; i++) graph[i][i] = true;

    //모든 노드에 대해 dfs를 실행한다
    for (int i = 1; i <= N; i++)
        if (graph[i][i])
        {
            dfs(i);
            //dfs를 한 번 실행할 때마다 연결 요소를 찾은 것이므로
            //ret에 1을 더한다
            ret++;
        }

    //ret를 출력한다
    printf("%d\n", ret);

	return 0;
}