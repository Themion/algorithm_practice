#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_valid(char c) { return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_'; }

int main()
{
	//cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    // 변수명이 Java 꼴이거나 cpp 꼴이라면 true
    bool isJavaLike = false, is_cpp_like = false;
    // 입력받은 변수명을 저장할 공간
    string str;
    // 입력받은 변수명을 단어 단위로 끊어서 저장
    vector<string> ret(1, "");

    cin >> str;

    // 변수명의 각 글자에 대해
    for (int i = 0; i < str.size(); i++)
    {
        // 글자가 소문자라면 ret의 맨 마지막 단어의 뒤에 추가
        if (str[i] >= 'a' && str[i] <= 'z') 
            ret.back() += str[i];
        // 글자가 대문자라면
        else if (str[i] >= 'A' && str[i] <= 'Z') 
        {
            // ret의 맨 마지막에 단어 _를 추가한 뒤
            ret.push_back("_");
            // 글자를 소문자로 바꿔서 맨 마지막의 뒤에 추가
            ret.back() += str[i] - 'A' + 'a';
            // 변수명이 Java 꼴임을 표시
            isJavaLike = true;
        }
        // 글자가 알파벳이 아니라면
        else 
        {
            // ret의 맨 마지막에 빈 단어를 추가한 뒤
            ret.push_back("");
            // 그 다음 글자를 대문자로 바꿔서 빈 단어의 뒤에 추가
            ret.back() += str[++i] += 'A' - 'a';
            // 변수명이 cpp 꼴임을 표시
            is_cpp_like = true;
        }
    }

    // 변수명의 각 단어에 대해
    // 단어의 길이가 0이거나, 첫 글자가 이상한 글자거나, Java 꼴인 동시에 cpp 꼴이라면
    for (auto r : ret)
        if (r.size() == 0 || !is_valid(r[0]) || (isJavaLike && is_cpp_like))
        {
            // Error!를 출력한 뒤 프로그램 종료
            cout << "Error!\n";
            return 0;
        }

    // 아무런 문제도 없을 경우 각 단어를 공백 문자 없이 출력
    for (auto r : ret) cout << r;
    cout << '\n';

    return 0;
}