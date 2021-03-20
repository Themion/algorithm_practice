#include <cstdio>
#include <algorithm>

using namespace std;

//입력받은 점을 저장할 공간
pair<int, int> p[100000];

int main()
{
    //입력받을 점의 개수
    int n;
    scanf("%d", &n);
    //점의 second를 first보다 우선하여 정렬하므로
    //second를 first보다 먼저 입출력한다
    for (int i = 0; i < n; i++)
        scanf("%d %d", &(p[i].second), &(p[i].first));

    sort(p, p + n);

    for (int i = 0; i < n; i++)
        printf("%d %d\n", p[i].second, p[i].first);

    return 0;
}