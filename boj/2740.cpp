#include <cstdio>

short a[100][100], b[100][100];

//행렬의 한 항을 함수 내에서 계산
int mul(int n, int i, int k)
{
    int ret = 0;
    for(int m = 0; m < i; m++) ret += a[n][m] * b[m][k];
    return ret;
}

int main()
{
    ///a[n][m], b[m][k]
    int n, m, k;

    //행렬 a를 입력받는다
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        scanf("%hd", &a[i][j]);
        
    //행렬 b를 입력받는다
    scanf("%*d %d", &k);
    for (int i = 0; i < m; i++) for (int j = 0; j < k; j++)
        scanf("%hd", &b[i][j]);

    //행렬 A*B를 저장하지 않고 바로 출력한다
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < k; j++) printf("%d ", mul(i, m, j));
        printf("\n");
    }

    return 0;
}