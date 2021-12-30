#include <cstdio>

int main() {
    // 고양이 모습을 하드코딩
    char str[4][9] = {"\\    /\\",
                      " )  ( \')",
                      "(  /  )",
                      " \\(__)|"};
    // str을 출력한다
    for(int i = 0; i < 4; i++) printf("%s\n", str[i]);

    return 0;
}
