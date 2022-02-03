#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

#define MAX_N 100

// {time, stat, place}: time 시간에 place 장소의 촬영이 (stat == 1 ? 시작함 : 종료됨)
// p: 각 촬영 정보를 place순, place가 같다면 time 순으로 정렬해 저장할 공간
struct point {
    int time = 0, stat = 0;
    string place;
} p[MAX_N * 2];

int main() {
    // N: 촬영 요청 제출 수, l, r: 각 요청의 시작 시간과 종료 시간
    // len: 중복된 요청을 제거한 총 촬영 횟수
    // max: 같은 장소에서 같은 시간에 진행되는 촬영의 최대 개수
    // line: 같은 지점에서 같은 시점에 진행되는 촬영의 수
    int N, l, r, len = 0, max = 0, ans = 0;
    // name, place: 각 요청을 신청한 사람과 진행할 장소
    string name, place;
    // 촬영을 요청한 사람의 집합
    unordered_set<string> names;

    // 각 촬영 요청에 대해
    for (cin >> N; N--; ) {
        // 촬영 요청을 입력받은 뒤
        cin >> name >> place>> l >> r;

        // 이미 촬영을 요청했다면 continue
        if (names.find(name) != names.end()) continue;

        // 촬영 요청을 한 사람을 names에 저장한 뒤
        names.insert(name);
        // p에 촬영 시작 시간과 종료 시간을 저장
        p[len++] = { l, 1, place };
        p[len++] = { r, -1, place };
    }

    // 각 촬영의 시작/종료 시간을 장소 -> 시간순으로 정렬
    sort(p, p + len, [](point a, point b) {
        if (a.place == b.place) {
            if (a.time == b.time) return a.stat < b.stat;
            return a.time < b.time;
        }
        return a.place < b.place;
    });

    // 같은 장소에서 시작 시간과 종료 시간이 겹치는 경우 한 촬영으로 간주함
    for (l = 0, r = 1; r < len; r++) {
        // 각 이웃한 시점 중 장소와 시간이 같고 각각 시작/종료인 두 시점이 있다면
        if (p[l].place == p[r].place &&
            p[l].time == p[r].time && p[l].stat + p[r].stat == 0)
            // 해당 두 시점을 p에서 제거해 두 촬영을 하나로 간주
            p[l] = p[++r];
        // 그렇지 않다면 두 시점을 그대로 이웃하게 둔다
        else p[++l] = p[r];
    }
    // 일부 시점을 제거했으므로 len을 실제 시점의 수인 l로 갱신
    len = l;

    // 각 시점에 대해
    for (int i = l = 0; i < len; i++) {
        // 현재 시점에서 진행되는 촬영의 수가 기존 최대 촬영보다 많거나
        // 기존 최대 촬영보다 같지만 현재 장소가 기존 장소보다 사전순으로 빠르다면
        if (max < (l += p[i].stat) || (max == l && p[ans].place > p[i].place)) {
            // 최대 촬영 수를 line으로 갱신한 뒤 ans에 해당 시점을 저장
            max = l;
            ans = i;
        }
    }

    // 가장 혼잡한 시점의 장소와 시간대를 출력
    cout << p[ans].place << ' ' << p[ans].time << ' ' << p[ans + 1].time << '\n';

    return 0;
}
