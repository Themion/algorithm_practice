#include <cstdio>
#include <queue>

short num[50001] = { 0, };

int min(int a, int b) {return a < b ? a : b; }

int main()
{
    int n, k;
    std::queue<int> q;
    scanf("%d", &n);

    q.push(0); num[0] = 1;

    while(!q.empty())
    {
        k = q.front();
        if (k == n) break;
        for (int i = 1; i * i + k <= n; i++) if (num[i * i + k] == 0)
        {
            num[i * i + k] = num[i * i] + num[k];
            q.push(i * i + k);
        }
        q.pop();
    }

    printf("%d\n", num[n]);

    return 0;
}