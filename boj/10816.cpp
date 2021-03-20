#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

//숫자 카드에 적힌 수를 저장할 배열
vector<int> card;

int main()
{
    //n, buf: 숫자 카드의 개수, buf: 각 숫자 카드의 수
    int n, buf;
    //upper_bound, lower_bound의 결과값을 저장할 공간
    vector<int>::iterator upper, lower;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &buf);
        card.push_back(buf);
    }

    //입력받은 card는 정렬되어 있지 않아 이분 탐색을 사용할 수 없다
    sort(card.begin(), card.end());

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        //개수를 찾을 숫자 카드의 수를 입력받은 뒤
        scanf("%d", &buf);
        //buf가 처음 나온 위치와 
        //그 이후로 buf가 아닌 수가 처음 나온 위치를 찾은 뒤
        upper = upper_bound(card.begin(), card.end(), buf);
        lower = lower_bound(card.begin(), card.end(), buf);
        //둘의 차를 출력한다
        printf("%d ", (int)(upper - lower));
    }
    printf("\n");

    return 0;
}