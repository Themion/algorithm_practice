#include <cstdio>

short t[500][500] = {{ 0, }};   // t: 입력받는 종이
int N, M;                       // 종이의 크기

// 좌표를 입력받아 t에서 해당 좌표를 읽을 수 있는지 확인
bool valid(int y, int x) { return y >= 0 && y < N && x >= 0 && x < M; }

// 두 수, 혹은 세 수를 입력받아 그 중 가장 큰 값을 반환
short max(short a, short b) { return a > b ? a : b; }
short max(short a, short b, short c) { return max(a, max(b, c)); }

// 왼쪽 위 좌표가 (y, x)인 2 * 3, 3 * 2 박스 안에서
// 최대값을 가지는 테트로미노의 값을 계산 
short search(int y, int x)
{
    // v: 3 * 2, h: 2 * 3 크기 박스에서 각 성분값
    // v_sum, h_sum: 각각 v, h를 이루는 값들의 합
    short ret = 0, v[6], h[6], v_sum = 0, h_sum = 0;

    //v, h의 값을 계산한다
    // 박스가 t의 범위를 벗어난다면 해당 위치의 값은 0으로 간주
    for (int i = 0; i < 2; i++) for (int j = 0; j < 3; j++)
    {
        v[i * 3 + j] = valid(y + i, x + j) ? t[y + i][x + j] : 0;
        v_sum += v[i * 3 + j];
        h[i * 3 + j] = valid(y + j, x + i) ? t[y + j][x + i] : 0;
        h_sum += h[i * 3 + j];
    }

    // 박스 안에서 무작위로 두 값을 빼 테트로미노를 만든다
    // 이 때 테트로미노를 만들 수 없는 값의 조합은 계산하지 않는다
    for (int i = 0; i < 6; i++) for (int j = i + 1; j < 6; j++)
        if ((i % 3 != 1 && j % 3 != 1) || i / 3 == j / 3)
            ret = max(ret, v_sum - (v[i] + v[j]), h_sum - (h[i] + h[j]));

    return ret;
}

// |자, 혹은 ㅡ자 블록은 search 함수로 계산할 수 없으므로 하드코딩
short search_I(int y, int x)
{
    short v = 0, h = 0;
    if (y < N - 3) v = t[y][x] + t[y + 1][x] + t[y + 2][x] + t[y + 3][x];
    if (x < M - 3) h = t[y][x] + t[y][x + 1] + t[y][x + 2] + t[y][x + 3];

    return max(v, h);
}

int main()
{
    short ret = 0;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
        scanf("%hd", &t[i][j]);

    // 모든 좌표에 대해 가능한 테트로미노의 값을 계산하여
    // max 함수를 통해 ret에 최대값을 저장
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
        ret = max(ret, search(i, j), search_I(i, j));

    printf("%hd\n", ret);

    return 0;
}