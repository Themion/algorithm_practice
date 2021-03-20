#include <cstdio>

int main()
{
    //card: 각 카드에 적힌 수
    //size: 카드의 수, num: 딜러가 부른 수
    //max: 세 카드의 합의 최대치, temp: 값을 임의로 저장할 공간
    int card[100], size, num, max = 0, temp;
    scanf("%d %d", &size, &num);
    for (int i = 0; i < size; i++) scanf("%d", card + i);

    //카드는 반드시 세 개가 되어야 하므로
    //3중 for문을 이용해 카드 셋을 고른다
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            for (int k = j + 1; k < size; k++)
            {
                //카드의 합이 num을 넘지 않는 선에서 최대가 되도록 한다
                temp = card[i] + card[j] + card[k];
                if (temp <= num) max = max > temp ? max : temp;
            }

    printf("%d\n", max);

    return 0;
}