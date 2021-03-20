#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 문장에 들어가는 단어의 수는 약 1000개이므로
// 시간복잡도가 O(N^2)인 코드로도 통과할 수 있음
void baekjoon_9322(int N)
{
    // key1: 제1 공개키, key2: 제2 공개키, code: 암호문
    vector<string> key1(N), key2(N), code(N);

    // 공개키와 암호문을 단어의 배열로 저장
    for (int i = 0; i < N; i++) cin >> key1[i];
    for (int i = 0; i < N; i++) cin >> key2[i];
    for (int i = 0; i < N; i++) cin >> code[i];

    // 제1 공개키의 각 단어가 제2 공개키의 j번째 단어와 일치할 때
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        if (key1[i] == key2[j])
        {
            // j번째 암호문의 단어를 제1 공개키의 순서대로 출력
            cout << code[j] << ' ';
            break;
        }

    // 줄바꿈 문자를 출력하여 평문의 출력을 마친다
    cout << '\n';
}

int main()
{
    //cin, cout 사용 시 필히 사용할 것
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc, N;
    cin >> tc;
    // 각 테스트 케이스마다
    while (tc--)
    {
        // 문장의 단어 수를 입력받은 뒤 테스트 케이스 실행
        cin >> N;
        baekjoon_9322(N);
    }

    return 0;
}