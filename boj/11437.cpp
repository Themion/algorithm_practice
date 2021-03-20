#include <cstdio>
#include <vector>

using namespace std;

//parent[i]: 가중치가 i인 노드의 부모 노드의 가중치
int parent[50001];
//트리를 이차원 배열로 저장한다
vector<vector<int>> v;

//가중치가 p인 노드의 자식을 찾아 해당 노드의 부모 노드를 p로 설정
//이 과정을 dfs로 실행한다
void dfs(int p)
{
	for (auto i : v[p]) if (parent[i] == 0)
	{
		parent[i] = p;
		if (v[i].size() > 1) dfs(i);
	}
}

int main()
{
    //n: 트리의 노드 수, cnt: 테스트 케이스의 수
    //a, b: 트리의 생성과 테스트 케이스에 사용할 노드의 가중치를 저장
	int n, cnt, a, b;

    //트리의 노드 수를 입력받은 뒤
    scanf("%d", &n);
    //트리를 저장할 배열 v의 크기를 지정하고
    v = vector<vector<int>>(n + 1);
    //트리를 입력받는다
    for (int i = 1; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    //루트 노드 1의 부모 노드를 1로 설정한다
    parent[1] = 1;
    ///dfs를 실행한다
    dfs(1);

    //테스트 케이스를 입력받은 뒤 각 테스트 케이스에 대해
    scanf("%d", &cnt);
	while (cnt--)
	{
        //노드의 부모를 탐색하는 과정에서 해당 노드가 나왔는지 확인할 배열
		vector<bool> vec = vector<bool>(n + 1, false);
        //루트 노드 1은 반드시 공통 노드이다
		vec[1] = true;

        //공통 부모 노드를 찾을 두 노드 a와 b를 입력받은 뒤
	    scanf("%d %d", &a, &b);

        //노드 a에 대해
		while (a != 1)
		{
            //a를 방문했음을 표시한 뒤
			vec[a] = true;
            //a를 a의 부모 노드로 설정한다
			a = parent[a];
		}

        //노드 b에 대해 b가 이미 방문한 노드가 될 때까지
        //b를 b의 부모 노드로 갱신한다
		while (!vec[b]) b = parent[b];

        //a와 b의 공통 부모 노드가 b에 저장되어 있을 것이므로 b를 출력한다
		printf("%d\n", b);
	}

	return 0;
}