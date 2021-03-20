#include <cstdio>
#include <stack>

using namespace std;

// 스택에 문자열을 입력
void stack_input(stack<char> &s)
{
    // 각 문자를 대신 입력받을 공간
    char buf = '\0';

    // 개행 문자가 나오기 전까지 입력받은 문자열을 큐에 push
    scanf ("%c", &buf);
    while (buf != '\n')
    {
        s.push(buf);
        scanf ("%c", &buf);
    }
}

// a에서 b로 값을 하나 옮긴다
void stack_move(stack<char> &a, stack<char> &b)
{
    b.push(a.top());
    a.pop();
}

int main()
{
    // base: 폭발 문자열이 있는 문자열, find: 폭발 문자열
    // ase_save, find_save: base와 find를 복원하기 위한 스택
    stack<char> base, find, base_save, find_save;

    // 긴 문자열과 폭발 문자열을 입력받는다
    stack_input(base);
    stack_input(find);

    // 긴 문자열 안에서 폭발 문자열을 탐지
    while (!base.empty())
    {
        // 두 문자열의 마지막 자리가 일치한다면
        if (base.top() == find.top())
        {
            // 두 문자열의 마지막 자리를 save에 저장
            stack_move(base, base_save);
            stack_move(find, find_save);

            // find의 모든 문자가 일치한다면
            if (find.empty()) 
            {
                // find를 복원하며 base_save 안의 find를 제거
                while (!find_save.empty()) 
                {
                    stack_move(find_save, find);
                    base_save.pop();
                }
                
                // base_save를 base 안에 저장
                // 이 때 find의 마지막 문자를 발견한다면 정지
                while (!base_save.empty() 
                    && !base.empty() && base.top() != find.top())
                    stack_move(base_save, base);
            }
        }

        // 마지막 자리가 일치하지 않는다면
        else
        {
            // find를 복원하며 base도 같은 글자수만큼 복원
            while (!find_save.empty())
            {
                stack_move(base_save, base);
                stack_move(find_save, find);
            }
            // 다음 문자를 비교하기 위해 
            // base의 마지막 문자를 save에 저장
            stack_move(base, base_save);
        }
    }

    // base가 폭발 문자열만으로 이루어져 있었다면 지정된 문자열을 출력
    if (base_save.empty()) printf("FRULA\n");
    // 그렇지 않다면 base를 복원하여 출력
    else
    {
        while (!base_save.empty()) 
        {
            printf("%c", base_save.top());
            base_save.pop();
        }
        printf("\n");
    }

    return 0;
}