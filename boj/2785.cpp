#include <algorithm>
#include <cstdio>

using namespace std;

#define MAX_N 500000

int len, chain[MAX_N];

int main()
{
    int idx = 0, open = 0;
    scanf("%d", &len);
    for (int i = 0; i < len; i++) scanf("%d", chain + i);

    sort(chain, chain + len);

    while(open < len - 1) {
        chain[idx]--;
        open++;
        if (!chain[idx]) {
            len--;
            idx++;
        }
    }

    printf("%d\n", open);

    return 0;
}