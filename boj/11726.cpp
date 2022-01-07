#include <cstdio>

#define MAX_N 1000
#define MOD 10007
#define get(i) (arr[i][0] + arr[i][1]) % MOD

int main() {
    // 만들고자 하는 타일의 길이
    int n;
    // arr[i - 1][j]: 2 * i 크기의 타일을 (j ? = : |)로 끝내는 경우의 수
    short arr[MAX_N][2] = {{1, 0}, {1, 1}};

    // 만들고자 하는 타일의 길이를 입력받은 뒤
    scanf("%d", &n);

    // 길이 2부터 차례로
    for (int i = 2; i < n; i++) {
        // 끝에 |가 붙는 길이가 i인 타일은 길이가 i - 1인 타일의 맨 뒤에 |를,
        // 끝에 =가 붙는 길이가 i인 타일은 길이가 i - 2인 타일의 맨 뒤에 =를 붙여 생성
        arr[i][0] = get(i - 1);
        arr[i][1] = get(i - 2);
    }
    
    // 길이가 n인 타일을 만드는 경우의 수를 출력
    printf("%d\n", get(n - 1));

    return 0;
}
