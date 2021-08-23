#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_LEN 1000001

string T, P;        // 입력받은 문자열과 패턴
vector<int> fail;   // 패턴의 실패함수

// 실패함수 구성
void make_fail()
{
    // 실패함수의 배열 크기를 미리 P의 크기로 설정
    fail = vector<int>(P.size(), 0);

    // P의 각 문자에 대해
    for (int i = 1; i < P.size(); i++)
    {
        // i번째 문자와 비교할 인덱스
        int idx = i;

        // 비교할 접두사가 있을 때
        while (idx != 0)
        {
            // 비교하여 맞는 접두사를 찾았다면
            if (P[i] == P[fail[idx - 1]])
            {
                // 실패함수의 값을 접두사의 길이 + 1로 설정
                fail[i] = fail[idx - 1] + 1;
                break;
            }
            // 맞는 접두사를 아직 찾지 못했다면 더 작은 접두사와 비교
            else idx = fail[idx - 1];
        }
    }
}

void search()
{
    int idx = 0;
    vector<int> v;

    // T의 각 자리에 대해
    for (int i = 0; i < T.size(); i++)
    {
        // 현재 자리와 맞는 값이 나올 때까지 P를 KMP 알고리즘에 맞게 당긴다
        while (idx > 0 && T[i] != P[idx]) idx = fail[idx - 1];
        // 맞는 자리를 찾았을 때
        if (T[i] == P[idx]) 
        {
            // 완전히 맞는 부분 문자열을 찾았다면 v에 그 자리를 push
            if (idx == P.size() - 1) v.push_back(i - idx + 1);
            // 더 비교할 자리가 있다면 1을 더하고, 없다면 실패함수 값을 idx에 저장
            idx = (idx == P.size() - 1) ? fail[idx] : idx + 1;
        }
    }

    // 맞는 문자열의 수와 각 문자열의 시작 인덱스를 출력
    cout << v.size() << '\n';
    for (int i : v) cout << i << ' ';
    if (v.size()) cout << '\n';
}

int main()
{
    //cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    // 문자열 T와 P를 입력받으며 그 길이를 계산
    getline(cin, T);
    getline(cin, P);

    // 실패함수를 계산한 뒤 매칭
    make_fail();
    search();

    return 0;
}