#include <algorithm>
#include <cstdio>

using namespace std;

//pair<int, int>는 기므로 mtng_t로 부른다
typedef pair<int, int> mtng_t;
//각 회의를 저장할 배열
mtng_t m[100000];

int main()
{
    //n: 주어진 회의의 수, end: 가장 마지막으로 끝난 회의의 끝나는 시간
    //ret: 회의실을 사용한 회의의 수
    int n, end = -1, ret = 0;

    //회의의 수와 각 회의를 입력받는다
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &m[i].first, &m[i].second);

    //회의들을 끝나는 시간 순으로, 끝나는 시간이 같다면 시작하는 시간 순으로 정렬한다
    sort(m, m + n, 
        [](mtng_t a, mtng_t b) 
        { 
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second; 
        }
    );

    //정렬된 순서대로 회의 일정을 살펴본다
    //현재 회의가 회의실을 가장 마지막으로 사용한다면
    for (int i = 0; i < n; i++) if (end <= m[i].first)
    {
        //해당 회의를 가장 마지막으로 회의실을 사용하게 한다
        end = m[i].second;
        //회의실을 사용한 회의가 하나 더 늘었다
        ret++;
    }

    //회의실을 사용한 회의의 수를 출력한다
    printf("%d\n", ret);

    return 0;
}