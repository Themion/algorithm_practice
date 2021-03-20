#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    //cin, cout 사용 시 필히 사용할 것
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력을 받을 공간
    string str;
    //괄호를 넣을 스택
    stack<char> s;

    //문장을 입력받는다
    getline(cin, str);

    //문장이 "."이 아니라면
    while (str != ".")
    {
        //문장의 각 성분에 대해
        for (int i = 0; i < str.size(); i++)
        {
            //해당 성분이 '(' 혹은 '['라면 해당 성분을 스택에 넣는다
            if ((str[i] == '(') || (str[i] == '[')) s.push(str[i]);
            //해당 성분이 ')'라면
            else if (str[i] == ')')
            {
                //스택에 가장 마지막에 넣은 값이 '('라면 이 값을 pop한다
                if (!s.empty() && (s.top() == '(')) s.pop();
                //그렇지 않다면 아무 값이나 넣고 for문을 빠져나간다
                else
                {
                    s.push(str[i]);
                    break;
                }
            }
            //해당 성분이 ']'라면
            else if (str[i] == ']')
            {
                //스택에 가장 마지막에 넣은 값이 '['라면 이 값을 pop한다
                if (!s.empty() && (s.top() == '['))  s.pop();
                //그렇지 않다면 아무 값이나 넣고 for문을 빠져나간다
                else
                {
                    s.push(str[i]);
                    break;
                }
            }
        }

        //스택이 비어있다면 주어진 문자열이 균형을 이루므로 yes를 출력
        if (s.empty()) cout << "yes\n";
        //그렇지 않다면 주어진 문자열은 균형을 이루지 못하므로
        else
        {
            //no를 출력한 뒤 스택에 있는 값을 전부 제거한다
            cout << "no\n";
            while (!s.empty()) s.pop();
        }

        //마지막으로 다음 문장을 입력받는다
        getline(cin, str);
    }

    return 0;
}