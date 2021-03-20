#include <cstdio>
#include <string>

//고양이 모습을 하드코딩한다
std::string str[4] = {"\\    /\\",
                      " )  ( \')",
                      "(  /  )",
                      " \\(__)|"};

int main()
{
    //str을 출력한다
    for(int i = 0; i < 4; i++)
    {
        for (auto j : str[i]) printf("%c", j);
        printf("\n");
    }

    return 0;
}