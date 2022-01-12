#include <cstdio>

#define R 31
#define M 1234567891

// 문자를 하나 입력받아 기존 해싱 결과와 더해 해싱
long long hashing(int L) {
    // 문자 하나를 입력받은 뒤
    char c = getchar();
    // 문자열의 길이가 0이라면 0을 반환
    if (!L) return 0;
    // 그렇지 않다면 주어진 방식대로 현재 문자를 해싱해 반환
    return (hashing(L - 1) * R + c - 'a' + 1) % M;
}

int main() {
    // 문자열의 길이를 입력받아 문자열을 해싱한 뒤 출력
    int L;
    scanf("%d\n", &L);
    printf("%lld\n", hashing(L));
    return 0;
}
