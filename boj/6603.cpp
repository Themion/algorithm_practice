#include <cstdio>

//arr: 로또 번호 후보를 저장할 공간
//picks: 로또 번호 후보 중 로또로 예측되는 번호
int arr[13], picks[6];

//현재 idx개의 번호를 뽑았으며 마지막으로 뽑은 번호는 last번째 번호이다
void pick(int idx, int last)
{
    //6개 미만의 번호를 뽑았다면
    if(idx < 6)
    {
        //last + 1번째 번호부터 실질적으로 가능한 번호들을 전부 뽑는다
        for(int i = last + 1; i + (5 - idx) <= arr[0]; i++)
        {
            //각 번호는 idx + 1번째 번호가 되고
            picks[idx] = arr[i];
            //이후 pick함수를 재귀적으로 수행한다
            pick(idx + 1, i);
        }
    }
    //만일 6개의 번호를 모두 뽑았다면
    else
    {
        //각 번호를 순서대로 출력한뒤 행을 바꾼다
        for (int i = 0; i <= 5; i++) printf("%d ", picks[i]);
        printf("\n");
    }
}

int main()
{
    //arr[0]을 로또 번호 후보의 수로 사용한다
    scanf("%d", &arr[0]);

    //테스트 케이스의 길이가 0이 아니라면
    while(arr[0] != 0)
    {
        //테스트 케이스를 입력받은 뒤
        for (int i = 1; i <= arr[0]; i++) scanf("%d", &arr[i]);
        //로또 번호를 처음부터 유추한다
        pick(0, 0);
        //테스트 케이스가 끝났으므로 개행문자를 통해 테스트 케이스의 끝을 알린다
        printf("\n");

        //다음 테스트 케이스의 길이를 입력받는다
        scanf("%d", &arr[0]);
    }
}