#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_N 100000

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // N: 정수의 개수, M: 찾을 수의 개수, A: 정수를 저장할 배열
    // buf: 찾을 수를 저장할 공간
    int N, M, A[MAX_N], buf;

    //배열의 크기와 해당 크기만큼의 배열을 입력받은 뒤 정렬한다
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A + N);

    //찾을 수의 개수를 입력받은 뒤
    cin >> M;
    while (M--) {
        //해당 횟수만큼 수를 입력받아 이진탐색을 실행한다
        cin >> buf;
        cout << binary_search(A, A + N, buf) << '\n';
    }

    return 0;
}
