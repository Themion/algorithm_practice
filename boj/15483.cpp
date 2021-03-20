#include <cstdio>

//a, b: 입력받을 두 문자열
char a[1001], b[1001];
//dist[i][j]: a의 시작부터 i글자와 b의 시작부터 j글자의 편집 거리
short dist[1001][1001];

int main()
{
    //aidx, bidx: a와 b의 길이
    int aidx = 0, bidx = 0;
    //a와 b를 입력받는다
    do { scanf("%c", &a[aidx]); } while (a[aidx++] != '\n');
    do { scanf("%c", &b[bidx]); } while (b[bidx++] != '\n');
    //a와 b의 길이에 맞게 각 인덱스를 1씩 빼 준다
    aidx--; bidx--;

    //공백을 a 혹은 b로 바꿀 때의 편집 거리를 미리 입력한다
	for (int i = 1; i <= aidx; i++) dist[i][0] = i;
	for (int i = 1; i <= bidx; i++) dist[0][i] = i;

    //동적 계획법으로 편집 거리를 계산한다
	for (int i = 1; i <= aidx; i++) for (int j = 1; j <= bidx; j++)
	{
		dist[i][j] = dist[i - 1][j - 1] + (a[i - 1] != b[j - 1]);
		if (dist[i][j] > dist[i - 1][j] + 1) dist[i][j] = dist[i - 1][j] + 1;
		if (dist[i][j] > dist[i][j - 1] + 1) dist[i][j] = dist[i][j - 1] + 1;
	}

    //최단 거리를 출력한다
	printf("%d\n", dist[aidx][bidx]);

	return 0;
}