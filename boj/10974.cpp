#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // N: 배열의 크기, arr: 미리 초기화한 배열
    int N, arr[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    // N을 입력받은 뒤 next_permutation을 이용해 길이가 N인 모든 순열을 탐색
    cin >> N;
    do for (int i = 0; i < N; i++) 
        cout << arr[i] << (i == N - 1 ? '\n' : ' ');
    while (next_permutation(arr, arr + N));

    return 0;
}
