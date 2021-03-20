#include <cstdio>

int main()
{
    int hr, min;
    scanf("%d %d", &hr, &min);

    min -= 45;

    if (min < 0)
    {
        min += 60;
        hr = (hr + 23) % 24;
    }

    printf("%d %d\n", hr, min);

    return 0;
}