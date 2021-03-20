#include <cstdio>
#include <queue>

#define MAX 1e9

int main()
{
    // step: A에서 B로 가기 위해 필요한 연산의 수
    // size: 한 step에서 연산이 가능한 수의 개수
    int A, B, step = 1, size = 1;
    // A에서 B로 가는 과정에 존재할 수 있는 수의 집합
    std::queue<int> q;
    scanf("%d %d", &A, &B);

    // A -> B의 맨 첫번째 수는 항상 A
    q.push(A);

    // A ->  B의 과정에 있는 수가 있을 때
    while(!q.empty())
    {
        // q에서 값을 하나 가져온 뒤
        A = q.front();
        q.pop();

        // 그 값이 B와 같다면 break
        if (A == B) break;
        // 연산을 거친 수가 범위 내에 존재하는 수라면 push
        if (2 * A <= MAX) q.push(2 * A);
        if (A <= MAX / 10) q.push(10 * A + 1);

        // 한 step에서 가능한 연산을 모두 마쳤다면
        if (--size == 0)
        {
            // size를 갱신하고 step을 1 늘린다
            size = q.size();
            step++;
        }
    }

    // A -> B를 찾아냈다면 변수 A에 B의 값이 들어가 있다
    // 따라서 A == B라면 A -> B가 가능하므로 step을, A != B라면 -1을 출력
    printf("%d\n", A == B ? step : -1);

    return 0;
}