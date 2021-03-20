#include <cstdio>

bool fractal[3072][6144] = {{true,  true,  true,  true,  true,  false, },
                            {false, true,  false, true,  false, false, },
                            {false, false, true,  false, false, false, }};

int main()
{
    int input, cnt = 3;
    scanf("%d", &input);

    while (input % 2 == 0)
    {
        for(int i = 0; i < cnt; i++) for (int j = 0; j < cnt * 2; j++)
        {
            fractal[i][j + (cnt * 2)] = fractal[i][j];
            fractal[i + cnt][j + cnt] = fractal[i][j];
        }

        input /= 2; cnt *= 2;
    }

    for(int i = cnt - 1; i >= 0; i--) 
    {
        for (int j = 0; j < cnt * 2; j++)
        {
            if(fractal[i][j]) printf("*");
            if(!fractal[i][j]) printf(" ");
        }
        
        printf("\n");
    }

    return 0;
}