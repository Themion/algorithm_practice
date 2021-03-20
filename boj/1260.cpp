#include <cstdio>
#include <queue>

//edge[i][j]: 노드 i와 j가 연결되어 있다면 true, 아니라면 false
//called:   DFS가 호출된 직후에 BFS가 호출됨을 이용
//          DFS에선 각 노드를 방문했다면 true, 결과적으로 모든 노드를 방문하므로 전부 true가 된다
//          BFS에선 각 노드를 방문했다면 false
bool edge[1001][1001], called[1001];

//start: 탐색을 시작할 노드
//min, max: 탐색의 속도를 높이기 위해 노드의 최솟값과 최댓값을 저장
int start, min = 1001, max = -1;

//BFS에서 사용할 큐
std::queue<int> q;

//DFS를 재귀적으로 구현
void DFS(int node)
{
	//현재 노드를 출력한 뒤 현재 노드를 방문했음을 표시한다
	printf("%d ", node);
	called[node] = true;

	//현재 노드와 연결된 노드 중 방문하지 않은 노드를 방문한다
	for (int i = min; i <= max; i++) if ((edge[node][i]) && (!called[i])) DFS(i);

    if(node == start) printf("\n");
}

//BFS를 큐를 이용하여 구현
void BFS(int node)
{
    //방문한 노드와 연결된 노드를 검색할 때 쓸 변수
	int visit;

	//시작 노드를 방문한 뒤 큐에 넣는다
	called[node] = false;
	q.push(node);

	//큐에 들어있는 노드에 대해
	while (!q.empty())
	{
		//해당 노드를 출력한다
		visit = q.front();
		printf("%d ", visit);
				
		//모든 노드에 대해
		for (int i = min; i <= max; i++)
		{
			//현재 노드와 임의의 노드가 연결되어 있고 임의의 노드를 아직 방문하지 않았다면
			if (edge[visit][i] && called[i])
			{
				//그 노드를 큐에 넣고 방문했음을 표시한다
				q.push(i);
				called[i] = false;
			}
        }

		//노드의 모든 이웃 노드를 방문했으므로 큐에서 제거
		q.pop();
	}

	//모든 노드를 방문했으므로 줄을 바꾼다
	printf("\n");
}

int main()
{
    //M : 에지의 개수
    //a, b : 에지를 입력받을 때 사용할 공간
    int M, a, b;

	//N, M, start를 저장한다
	//N은 실제로 쓰이지 않는다
	scanf("%*d %d %d", &M, &start);

	//에지의 수만큼 에지를 입력받는다
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		//양방향 그래프이므로 에지를 양방향으로 연결한다
		edge[a][b] = true;
		edge[b][a] = true;

		//min과 max를 갱신
		if (min > a) min = a;
		if (min > b) min = b;

		if (max < a) max = a;
		if (max < b) max = b;
	}

	//DFS를 한 뒤 BFS를 한다
	DFS(start);
	BFS(start);

    return 0;
}