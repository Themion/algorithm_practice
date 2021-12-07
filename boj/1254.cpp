#include <cstdio>

using namespace std;

#define STR_MAX 1001

char S[STR_MAX];

void swap(int a, int b) { char temp = S[a]; S[a] = S[b]; S[b] = temp; }

// S의 앞에서부터 len개의 문자가 팰린드롬인지를 출력
bool is_palindrome(int len) {
    for (int i = 0; i < len / 2; i++) if (S[i] != S[len - i - 1]) return false;
    return true;
}

int main() {
    // len: 입력받은 문자열의 길이
    // pal_len: 입력받은 문자열에서 
    //          마지막 문자를 포함하는 부분 문자열 중 가장 긴 팰린드롬의 길이
    int len = 0, pal_len;

    // 문자열을 입력받은 뒤 문자열의 길이를 계산
    scanf("%s", S);
    while (S[len] != '\0') len++;

    // 팰린드롬 계산을 위해 문자열을 뒤집는다
    for (int i = 0; i < len / 2; i++) swap(i, len - i - 1);

    // 뒤집은 문자열에서 앞에서부터 가장 긴 팰린드롬과 그 길이를 계산
    pal_len = len;
    while (!is_palindrome(pal_len)) pal_len--;

    // 입력받은 문자열과 뒤집은 문자열을 붙인 뒤
    // 계산한 팰린드롬을 뒤집은 문자열에서 제거하면 만들고자 하는 문자열이 나온다
    // 이 문자열의 길이는 2 * len - pal_len이다
    printf("%d\n", 2 * len - pal_len);

    return 0;
}
