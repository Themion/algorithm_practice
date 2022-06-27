#include <cmath>
#include <string>
#include <vector>

using namespace std;
// 단순무식하게 소수를 계산
bool isPrime(int num) {
    // 2부터 num의 제곱근까지 모든 자연수로 나눠보면서
    // 나머지가 0인 수를 발견했다면 num은 소수가 아니다
    for (uint64_t i = 2; i <= sqrt(num); i++) if (!(num % i))return false;
    return true;
}

int solution(int n, int k) {
    // n을 k진수로 나타냈을 때 각 소수의 개수
    int answer = 0;
    // str 안의 각 소수를 저장할 공간
    uint64_t num = 0;
    // n을 k진수로 나타낸 수를 문자열 꼴로 저장
    // 가장 오른쪽에 있는 소수를 계산 결과에 포함하기 위해 초기 상태를 "0"으로 지정
    string str = "0";
    
    // n을 k진수로 바꿔 string 형태로 str에 저장
    while (n) {
        str = (char)((n % k) + '0') + str;
        n /= k;
    }
    
    // str에서 정해진 형태의 정수를 추출해 소수 판정
    for (char c : str) {
        // c가 0이라면 정수 추출을 끝냈으므로 추출한 정수가 소수라면 answer를 1 증가 
        if (c == '0') {
            if (num >= 2 && isPrime(num)) answer++;
            num = 0;
        }
        // 그렇지 않다면 num의 오른쪽에 c를 붙여 정수 추출을 계속함
        else num = num * 10 + c - '0';
    }

    // n을 k진수로 바꿨을 때 정해진 형식의 소수의 개수를 반환
    return answer;
}
