#include <cstdio>
#include <queue>

//pair보다 비용이 싸다
class doc { public: int idx = 0, pri = 0; };

//입력 및 큐의 front의 저장에 사용할 공간
doc temp;
//프린터의 형태가 큐이므로 큐를 이용해 프린터를 구현한다
std::queue<doc> Q;

int main()
{
    //tc: 테스트 케이스의 수
    //num: 대기중인 출력물의 수
    //target: 출력 순번을 확인할 출력물의 인덱스
    //search: 출력 순번을 확인할 출력물의 가중치
    //rank[i]: 가중치가 i인 출력물의 개수
    int tc, num, target, search, rank[10];
    scanf("%d", &tc);

    //각 테스트 케이스마다
    while(tc--)
    {
        //가중치의 최소치와 최대치는 각각 1, 9이므로
        //가중치가 1 이상 9 이하인 출력물의 개수를 0으로 초기화한다
        for (int i = 1; i <= 9; i++) rank[i] = 0;
        //큐를 전부 비운다
        while(!Q.empty()) Q.pop();
        //num과 target을 입려받는다
        scanf("%d %d", &num, &target);

        //각 출력물의 가중치를 입력받아 큐에 저장한다
        for (int i = 0; i < num; i++)
        {
            temp.idx = i;
            scanf("%d", &temp.pri);
            Q.push(temp);
            
            //가중치가 같은 출력물의 개수를 저장하고 가능하면 search를 갱신한다
            rank[temp.pri]++;
            if(temp.idx == target) search = temp.pri;
        }
        
        //가중치를 9부터 시작해서
        for (int i = 9; i >= search; i--)
        {
            //해당 가중치를 가진 출력물이 있다면
            while(rank[i])
            {
                //맨 앞 출력물을 확인하여
                temp = Q.front();
                Q.pop();

                //해당 출력물이 원하는 출력물이고 출력할 준비가 되었다면 출력한다
                if      ((temp.idx == target) && (temp.pri == i)) break;

                //해당 출력물의 가중치가 i보다 작다면 해당 출력물을 큐에 push한다
                if (temp.pri < i) Q.push(temp);
                //그렇지 않다면 해당 가중치를 가진 출력물의 수를 1 줄인 뒤 출력한다
                else              rank[temp.pri]--;
                
            }
        }

        //원하는 결과는 (총 출력물의 수 - 출력되지 않은 출력물의 수)와 같다
        printf("%d\n", num - Q.size());
    }

    return 0;
}