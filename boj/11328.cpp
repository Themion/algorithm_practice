#include <cstdio>

// 알파벳 소문자의 개수
const int len = 'z' - 'a' + 1;

// 문자열을 입력받은 뒤 문자열의 각 문자 개수를 센다
void scan(int cnt[], int add)
{
    char str[1010];
    scanf("%s", str);

    // 문자열의 각 문자 c가 나온 만큼 cnt에 add를 더한다
    for (int i = 0; str[i] != '\0'; i++) cnt[str[i] - 'a'] += add;
}

bool boj_11328()
{
    bool ret = true;        // 정답 여부를 확인
    int cnt[len] = { 0, };  // 각 문자가 나온 횟수를 count

    scan(cnt, 1);           // 첫번째 문자열의 각 문자만큼 +1
    scan(cnt, -1);          // 두번째 문자열의 각 문자만큼 -1

    // 첫번째 문자열과 두번째 문자열이 strfry 관계라면
    // 두 문자열의 각 문자의 수가 동일하므로
    // 두 문자열이 같다면 cnt의 모든 값은 0
    for (int i = 0; i < len; i++) ret = ret && !cnt[i];

    return ret;
}

int main()
{
    int tc = 0;
    scanf("%d\n", &tc);

    while (tc--) // 각 테스트 케이스별로 strfry 관계인지 확인
        printf("%s\n", boj_11328() ? "Possible" : "Impossible");

    return 0;
}