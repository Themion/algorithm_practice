#include <cstdio>

// prev[i]: 처음부터 바로 직전의 i번째 칸까지 이동할 때 
//          얻을 수 있는 점수의 최대/최솟값
int prev_max[3] = { 0, 0, 0 }, prev_min[3] = { 0, 0, 0 };

void set_max(int &a, int b) { a = a > b ? a : b; }
void set_min(int &a, int b) { a = a < b ? a : b; }

void set(int n)
{
    // 현재 줄의 세 칸
    int now[3];
    scanf("%d %d %d", now, now + 1, now + 2);

    // 이전 줄의 점수의 최대/최소값을 따로 저장
    int max[3] = {0, 0, 0}, min[3] = {900000, 900000, 900000};

    // 이전 칸에서 i번쨰 칸에 도착할 수 있는 세 칸에 대해
    for (int i = 0; i < 3; i++) for (int j = i - 1; j <= i + 1; j++)
    {
        // 칸의 인덱스가 범위를 벗어났다면 continue
        if (j < 0 || j > 2) continue;
        // i번째 칸에 도착할 수 있는 값의 최대/최소값을 저장
        set_max(max[i], prev_max[j]);
        set_min(min[i], prev_min[j]);
    }

    // 입력받은 현재 칸과 최대/최소 칸의 값을 더해 다시 prev에 저장
    for (int i = 0; i < 3; i++)
    {
        prev_max[i] = max[i] + now[i];
        prev_min[i] = min[i] + now[i];
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) set(i);

    // 모든 칸에서의 최대/최소값을 게산하여 출력
    for (int i = 1; i < 3; i++)
    {
        set_max(prev_max[0], prev_max[i]);
        set_min(prev_min[0], prev_min[i]);
    }
    printf("%d %d\n", prev_max[0], prev_min[0]);

    return 0;
}