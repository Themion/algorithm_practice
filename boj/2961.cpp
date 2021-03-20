#include <algorithm>
#include <cstdio>

//재료의 수
int num;
//각 재료의 신맛과 쓴맛 지수
std::pair<int, int> item[10];

//idx번째의 재료를 쓸 예정이고
//요리의 신맛 지수와 쓴맛 지수가 각각 first, second
int cook(int idx, int first, int second)
{
    //ret: 요리한 직후의 신맛과 쓴맛의 차
    //temp: 이후 다른 요리의 신맛과 쓴맛의 차를 구해 저장함
    int ret, temp;

    //신맛 지수는 기존 신맛 지수에 곱하고
    //쓴맛 지수는 기존 쓴맛 지수에 더한다
    first *= item[idx].first;
    second += item[idx].second;

    //현재 요리의 신맛 지수와 쓴맛 지수의 차를 구한 뒤
    ret = (first > second) ? (first - second) : (second - first);
    //현재 요리에서 다른 요리를 추가했을 때
    //신맛 지수와 쓴맛 지수의 차가 줄어든다면
    //줄어든 차를 ret에 저장한다
    for (int i = idx + 1; i < num; i++)
    {
        temp = cook(i, first, second);
        if (ret > temp) ret = temp;
    }

    //신맛 지수와 쓴맛 지수의 차를 반환한다
    return ret;
}

int main()
{
    //물의 신맛 지수와 쓴맛 지수의 차를 큰 값으로 지정한다
    int ret = 0x3f3f3f3f, temp;

    //재료의 수와 각 재료의 신맛/쓴맛 지수를 입력받는다
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
        scanf("%d %d", &(item[i].first), &(item[i].second));

    //함수 구조 상 자신보다 이전 차례의 재료는 사용하지 않으므로
    //각 재료를 처음으로 쓰는 cook 함수를 호출한다
    for (int i = 0; i < num; i++)
    {
        temp = cook(i, 1, 0);
        if (ret > temp) ret = temp; 
    }

    //요리하여 신맛 지수와 쓴맛 지수의 차가 최소인 값을 출력한다
    printf("%d\n", ret);

    return 0;
}