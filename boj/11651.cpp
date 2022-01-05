#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> coord;

#define MAX_N 100000
#define _x first
#define _y second

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 입력받을 좌표의 수
    int N;
    // 입력받을 좌표를 저장할 공간
    coord c[MAX_N];

    // 좌표의 수와 좌표들을 입력받는다
    cin >> N;
    for (int i = 0; i < N; i++) cin >> c[i]._x >> c[i]._y;

    // 좌표를 정렬한 뒤 정렬된 순서로 출력
    sort(c, c + N, [](coord a, coord b){
        return (a._y == b._y) ? a._x < b._x : a._y < b._y; 
    });
    for (int i = 0; i < N; i++) cout << c[i]._x << ' ' << c[i]._y << '\n';

    return 0;
}
