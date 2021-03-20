#include <cstdio>
#include <map>

// 각 테스트 케이스를 함수 안에서 따로따로 실행
void boj_7662()
{
    
    int k, num; // k: 명령의 개수, num: 명령에 들어가는 숫자
    char cmd;   // 명령이 push일 경우 I, pop일 경우 D
    
    std::map<int, int> m;               // m[key]: map 안의 key의 수
    std::map<int, int>::iterator it;    // m의 값에 접근하기 위한 iterator

    scanf("%d", &k);
    while (k--)
    {
        scanf("\n%c", &cmd);
        scanf("%d", &num);

        
        if (cmd == 'I') m[num] += 1;    // 명령이 I라면 m에   num을 push
        else if (cmd == 'D')            // 명령이 D라면 m에서 num을 pop
        {
            if (m.empty()) continue;    // m에 원소가 없을 경우 명령을 무시

            if (num == 1)   it = --m.end(); // num에 따라 pop하기 위한
            else            it = m.begin(); // 위치를 결정

            it->second--;   // num을 pop하되, 큐 안의 num의 수가 0 이하라면
            if (it->second <= 0) m.erase(it);   // map에서 num을 제거
        }
    }
    
    // m에 원소가 없다면 EMPTY를, 원소가 있다면 최대 원소와 최소 원소를 출력
    if (m.empty()) printf("EMPTY\n");
    else printf("%d %d\n", (--m.end())->first, m.begin()->first);
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--) boj_7662();

    return 0;
}