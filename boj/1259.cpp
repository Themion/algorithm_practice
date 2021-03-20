#include <iostream>
#include <string>

using namespace std;

int main()
{
	//cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    //입력받은 수를 문자열로 저장
    string s = "";
    //문자열의 각 위치를 확인할 때 쓸 인덱스
    int idx;

    //문자열을 먼저 입력받은 뒤
    cin >> s;

    //팰린드롬수 확인 종료를 알리는 문자열이 아닌 경우
    while(s != "0")
    {
        //인덱스를 0으로 초기화한 뒤
        idx = 0;

        //문자열의 각 위치를 비교하여 같으면 idx를 1 올리고, 다르다면 break
        while(idx < s.length() / 2)
        {
            if(s[idx] == s[s.length() - (idx + 1)]) idx++;
            else break;
        }

        //idx를 통해 문자열을 마지막까지 비교했는지 확인
        cout << ( (idx < s.length() / 2) ? "no" : "yes" ) << '\n';
        cin >> s;
    }

    return 0;
}