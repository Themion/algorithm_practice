#include <cstdio>

int main()
{
    int n, buf, min = 1000000, max = -1000000;
    
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &buf);
        if(min > buf) min = buf;
        if(max < buf) max = buf;
    }

    printf("%d %d", min, max);

    return 0;
}