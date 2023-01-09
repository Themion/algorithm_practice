#include <algorithm>
#include <iostream>

#define MAX_N 1500

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int NN;
    int arr[MAX_N * MAX_N];

    cin >> N;
    NN = N * N;
    for (int i = 0; i < NN; i++) cin >> arr[i];

    nth_element(arr, arr + NN - N, arr + NN);

    printf("%d\n", arr[NN - N]);

    return 0;
}
