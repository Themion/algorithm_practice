#include <cstdio>
#include <algorithm>

int main()
{
    // N: 배열의 크기, arr: 미리 초기화한 배열
    int N, arr[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    // N을 입력받은 뒤
    //next_permutation을 이용해 길이가 N인 모든 순열을 탐색
    scanf("%d", &N);
    do 
    {
        for (int i = 0; i < N; i++) printf("%d ", arr[i]);
        printf("\n");
    } while (std::next_permutation(arr, arr + N));

    return 0;
}