#include <algorithm>
#include <cstdio>

#define MAX_N 100000

using namespace std;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

class work {
    public: 
    int d, t;
    work() { d = t = 0; }
    work(int _d, int _t) {d = _d; t = _t;}
};

int main() {
    int N;
    work w[MAX_N];
    int work_left = 0;
    int total_daytime = 0;
    int total_nighttime = 0;
    int worked_daytime = 0;
    int worked_nighttime = 0;
    int worked_today;

    for (int i = scanf("%d", &N) - 1; i < N; i++)
        scanf("%d %d", &(w[i].d), &(w[i].t));

    sort(w, w + N, [](work a, work b) { return a.d < b.d; });

    for (int i = 0; i < N; i++) {
        work_left = w[i].t;
        total_daytime = (w[i].d / 7 * 5) + min(w[i].d % 7, 5);
        total_nighttime = w[i].d;

        worked_today = min(work_left, total_daytime - worked_daytime);
        work_left -= worked_today;
        worked_daytime += worked_today;

        if (work_left > total_nighttime - worked_nighttime) {
            printf("-1\n");
            return 0;
        }
        else
            worked_nighttime += work_left;
    }

    printf("%d\n", worked_nighttime);

    return 0;
}
