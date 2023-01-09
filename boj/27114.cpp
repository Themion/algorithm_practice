#include <cstdio>
#include <queue>

#define MAX_K 1000000
#define _cost first
#define _dir second

using namespace std;

typedef pair<int, int> act;

int cost(act a, act b) { return a._cost + b._cost; }
int dir(act a, act b) { return (a._dir + b._dir) % 4; }

act operator+(act a, act b) { return { cost(a, b), dir(a, b) }; }

int main() {
    int K;
    bool e[MAX_K + 1][4] = {{ 0, }};
    int ans = -1, len = 0;
    queue<act> q;
    act single[3], f;

    scanf("%d %d %d %d", &single[0]._cost, &single[2]._cost, &single[1]._cost, &K);
    for (int i = 0; i < 3; i++) single[i]._dir = i + 1;

    q.push({0, 0});

   for (int i = 1; !q.empty(); i++) {
        len = q.size();

        while (len--) {
            f = q.front();
            q.pop();

            for (act s : single) {
                act s_ = f + s;

                if (s_._cost == K && s_._dir == 0) {
                    q = queue<act>();
                    len = 0;
                    ans = i;
                    break;
                }
                else if (s_._cost < K && !e[s_._cost][s_._dir]) {
                    q.push(f + s);
                    e[s_._cost][s_._dir] = true;
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
