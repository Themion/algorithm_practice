#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

//에지를 연결 리스트의 형태로 표현
vector<int> edge[100001];

int main()
{
	//size : 실제 노드의 개수
	//a, b : edge의 인덱싱에 쓸 변수
	int size, a, b;
    scanf("%d", &size);

	//bfs에 사용할 큐
	queue<int> parent;
	//인덱스의 부모 노드를 값으로 가짐
	vector<int> tree(100001);

	//에지를 입력받아 트리를 완성한다
	for (int c = 0; c < size - 1; c++)
	{
	    scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	//루트 노드를 큐에 넣는다
	parent.push(1);

	//bfs 사용
	while (!parent.empty())
	{
		//큐에 존재하는 각 노드에 대해
		a = parent.front();

		//노드에 연결된 모든 노드에 대해
		for (b = 0; b < edge[a].size(); b++)
		{
			//해당 노드의 부모 노드가 알려지지 않았다면
			//부모 노드를 큐의 front 노드로 설정하고 자식 노드를 큐에 넣는다
			if (tree[edge[a][b]] == 0)
			{
				tree[edge[a][b]] = a;
				parent.push(edge[a][b]);
			}
		}

		//큐의 front 노드의 모든 자식 노드를 파악했으므로 pop한다
		parent.pop();
	}

	//각 노드의 부모 노드를 출력
	for (int i = 2; i <= size; i++) printf("%d\n", tree[i]);

    return 0;
}