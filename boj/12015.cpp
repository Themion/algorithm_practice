#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    // n: 배열의 길이, buf: 배열의 각 성분을 임시로 입력받을 공간
    int n, buf;
    // 최장 부분 수열을 길이를 인덱스로, 마지막 값을 값으로 저장
    vector<int> len(0);

    // 배열의 각 성분을 입력받으며 최장 부분수열을 구한다
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        // i번째 값을 입력받은 뒤
        scanf("%d", &buf);
        // 최장 부분수열이 갱신 가능하면 갱신하고
        if (len.size() == 0 || len.back() < buf) len.push_back(buf);
        // 그렇지 않다면 삽입 가능한 위치 중 인덱스가 가장 큰 곳을
        // 이분탐색으로 구하여 해당 위치에 삽입
        else len[lower_bound(len.begin(), len.end(), buf) - len.begin()] = buf;
    }

    // 배열 len의 길이가 곧 최장 부분수열의 길이이므로 이를 출력한다
    printf("%d\n", len.size());

    return 0;
}