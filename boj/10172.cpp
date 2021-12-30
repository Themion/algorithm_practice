#include <cstdio>

int main() {
    // 개 모습을 하드코딩
    char str[5][12] = {"|\\_/|",
                        "|q p|   /}",
                        "( 0 )\"\"\"\\",
                        "|\"^\"`    |", 
                        "||_/=\\\\__|"};
    // str을 출력한다
    for(int i = 0; i < 4; i++) printf("%s\n", str[i]);

    return 0;
}
