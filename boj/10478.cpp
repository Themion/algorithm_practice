#include <iostream>
#include <map>
#include <string>

using namespace std;

#define MAX_N 10
#define FOR(i, a, b) for(i = a; i < b; i++)

// arr[i][j]: 단위 i가 단위 j의 정수배라면 그 배수, 그 반대라면 -1
int arr[MAX_N][MAX_N];

// 단위 i와 단위 j의 비율을 val로 설정
void set_arr(int i, int j, int val) {
    arr[i][j] = val;
    arr[j][i] = -1;
}

void test_case(int N) {
    // i, j, k: 순회에 사용할 인덱스, num: 각 단위 사이의 배율, max: num의 최댓값
    int i, j, k, num, max = 0;
    // from, to: 문제에서 주어지는 단위의 이름을 입력할 공간
    // name[i]: i번째 단위의 이름
    string from, to, name[MAX_N];
    // unit[str]: 단위 str의 순서
    map<string, int> unit;

    // 각 단위의 이름을 입력받고 name, unit에 저장한 뒤 arr를 초기화
    FOR(i, 0, N) {
        cin >> name[i];
        unit[name[i]] = i;
        FOR(j, 0, N) arr[i][j] = i == j;
    }

    // 각 단위 사이의 배율을 입력받는다
    FOR(i, 1, N) {
        cin >> from >> to >> num >> to;
        arr[unit[from]][unit[to]] = num;
        arr[unit[to]][unit[from]] = -1;
    }

    // 플로이드-워셜을 응용해 arr에 각 단위간의 배율을 저장
    // 두 단위 i, j의 직접적인 관계를 모를 때
    // 두 단위와의 직접적인 관계를 아는 k를 이용해 두 단위의 직접적인 관계를 계산
    FOR(k, 0, N) FOR(i, 0, N) FOR(j, 0, N) if (!arr[i][j]) {
        if (arr[i][k] > 0 && arr[j][k] > 0) {
            if (arr[i][k] > arr[j][k]) set_arr(i, j, arr[i][k] / arr[j][k]);
            else set_arr(j, i, arr[j][k] / arr[i][k]);
        }
        else if (arr[i][k] > 0 && arr[j][k] < 0)
            set_arr(i, j, arr[i][k] * arr[k][j]);
        else if (arr[i][k] < 0 && arr[j][k] > 0)
            set_arr(j, i, arr[j][k] * arr[k][i]); 
        else if (arr[i][k] < 0 && arr[j][k] < 0) {
            if (arr[k][i] > arr[k][j]) set_arr(j, i, arr[k][i] / arr[k][j]);
            else set_arr(i, j, arr[k][j] / arr[k][i]);
        }
    }

    // 배율이 가장 큰 관계를 가진 단위의 인덱스를 k에 저장한 뒤
    FOR(i, 0, N) FOR(j, 0, N) {
        if (max < arr[i][j]) {
            max = arr[i][j];
            k = i;
        }
        else if (max < arr[j][i]) {
            max = arr[j][i];
            k = j;
        }
    }

    // 가장 큰 단위를 출력하고
    cout << 1 << name[k];
    arr[k][k] = 0;

    // 두번째로 큰 단위부터 내림차순으로 배율과 단위의 이름을 출력
    for (int _ = 1; _ < N; _++) {
        // 배율이 작은 순서대로 출력해야 한다
        num = __INT_MAX__;
        // 배율이 가장 작으면서 그 배율이 1 초과인 단위의 인덱스를 i에 저장한 뒤
        FOR(j, 0, N) if (num >= arr[k][j] && arr[k][j] > 1) {
            num = arr[k][j];
            i = j;
        }
        // " = (단위 배율)(단위 이름)"을 각각 출력한 뒤
        cout << " = " << arr[k][i] << name[i];
        // 중복 출력을 막기 위해 단위 배율을 0으로 변경
        arr[k][i] = 0;
    }

    // 개행 문자를 출력해 출력을 종료
    cout << '\n';

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 테스트 케이스의 단위 수를 입력받고 단위 수가 0이 아니라면 테스트 케이스 실행
    for (int N; cin >> N && N; ) test_case(N);

    return 0;
}
