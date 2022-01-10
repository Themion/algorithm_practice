#include <iostream>

using namespace std;

#define MAX_N 1000000

int main(){
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 시험장 수, A[i]: i번째 시험장에 있는 응시자 수
    // B: 총감독관이 감독하는 응시자 수, C: 부감독관 한 명이 감독하는 응시자 수
    int N, A[MAX_N], B, C;
    unsigned long long ans = 0;
    
    // 문제의 조건을 입력받은 뒤
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> B >> C;

    // 각 시험장에 대해
    for (int i = 0; i < N; i++) {
        // 총감독관이 감독할 수 있는 응시자는 제외한 뒤
        A[i] -= B;
        // 남은 응시자가 있다면 필요한 부감독관의 인원수를 계산해 ans에 더한다
        if (A[i] > 0) ans += A[i] / C + (bool)(A[i] % C);
    }

    // 각 시험장에 총감독관은 반드시 한 명씩 존재하므로
    // 부감독관 수의 총합에 시험장 수를 더한 값을 출력한다
    cout << ans + N << '\n';

    return 0;
}
