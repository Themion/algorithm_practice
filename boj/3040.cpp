#include <cstdio>

int main()
{
    // dwarf: 각 난쟁이의 모자에 적힌 수
    // sum: 모자에 적힌 수의 총합
    // a, b: 일곱 난쟁이가 아닌 난쟁이의 수
    int dwarf[9], sum = 0, a, b;

    // 아홉 난쟁이의 모자에 적힌 수를 입력받는다
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", dwarf + i);
        sum += dwarf[i];
    }

    // 두 드워프를 골라 sum에서 두 드워프의 수를 뺀 값이 100이라면
    // a와 b는 각각 i와 j이다
    for (int i = 0; i < 8; i++) for (int j = i + 1; j < 9; j++)
        if (sum - (dwarf[i] + dwarf[j]) == 100)
        {
            a = i;
            b = j;
        }

    // 일곱 난쟁이를 출력
    for (int i = 0; i < 9; i++) if (i != a && i != b)
        printf("%d\n", dwarf[i]);

    return 0;
}