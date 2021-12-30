#include <iostream>
#include <string>

using namespace std;

#define MAX 200

// 나이가 같은 회원의 이름을 링크드 리스트 꼴로 저장
struct person {
    // 회원의 이름
    string name = "";
    // 링크드 리스트의 다음 항목
    person* next = NULL;
};

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 회원의 수, age: 각 회원의 나이
    int N, age;
    // p[i]: 나이가 i인 회원의 링크드 리스트, it[i]: p[i]를 순회하기 위한 iterator
    person p[MAX + 1], *it[MAX + 1];

    // it 초기화
    for (int i = 1; i <= MAX; i++) it[i] = &p[i];

    // 회원 정보 N개를 입력받는다
    for (cin >> N; N--; ) {
        // 나이를 입력받은 뒤
        cin >> age;
        // 입력받을 공간을 만들고
        it[age] = (it[age]->next = new person);
        // 만든 공간에 이름을 입력
        cin >> it[age]->name;
    }

    // 회원을 나이별로 출력
    for (int i = 1; i <= MAX; i++) {
        // it을 초기화한 뒤
        it[i] = &p[i];

        // 나이가 i인 모든 회원을 출력
        while (it[i]->next != NULL) {
            // 각 회원의 이름이 저장된 공간을 가져온 뒤
            it[i] = it[i]->next;
            // 각 회원의 나이와 이름을 출력
            cout << i << ' ' << it[i]->name << '\n';
        }
    }

    return 0;
}
