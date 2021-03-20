#include <algorithm>
#include <cstdio>

using namespace std;

typedef pair<int, int> p;

// 좌표의 값과 입력된 순서를 배열에 저장
p arr[1000000];

int main()
{
    // N: 배열의 실질적 크기
    // buf: 좌표를 압축할 때 사용할, 이전 좌표의 압축 전 값
    // cnt: 압축된 좌표 중 자신보다 크기가 작은 서로 다른 좌표의 수
    int N, buf, cnt = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &buf);
        arr[i] = p(buf, i);
    }

    // 좌표를 크기에 따라 정렬
    sort(arr, arr + N, [](p a, p b){
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });

    // 첫 번째 좌표는 크기가 가장 작으므로 압축 후 값은 반드시 0
    buf = arr[0].first;
    arr[0].first = cnt;
    // 두 번쨰 좌표부터
    for (int i = 1; i < N; i++)
    {
        cnt += buf != arr[i].first; // 현재 좌표와 이전 좌표를 비교해 압축
        buf = arr[i].first;         // 현재 좌표의 압축 전 값을 저장한 뒤
        arr[i].first = cnt;         // 계산한 압축값을 arr에 대입
    }

    // 다시 입력된 순서로 배열을 정렬
    sort(arr, arr + N, [](p a, p b){ return a.second < b.second; });

    // 압축된 좌표값을 차례로 출력한다
    for (int i = 0; i < N; i++) printf("%d ", arr[i].first);
    printf("\n");

    return 0;
}