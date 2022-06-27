// 단순무식하게 소수를 계산
function isPrime(num) {
    // 2부터 num의 제곱근까지 모든 자연수로 나눠보면서
    // 나머지가 0인 수를 발견했다면 num은 소수가 아니다
    for (let i = 2; i <= Math.sqrt(num); i++) if (num % i === 0) return false;
    return true;
}

function solution(n, k) {
    // n을 k진수로 나타냈을 때 각 소수의 개수
    var answer = 0;
    let num = ""
    
    // n을 k진수로 바꿔 string 형태로 num에 저장
    while (n) {
        num = (n % k) + '' + num
        n = Math.floor(n / k)
    }
    
    // num을 0으로 split하면 원하는 소수를 문자열로 나타낸 값 n의 배열을 얻을 수 있다
    num.split('0').forEach(n => {
        // n을 10진수로 바꾼 값이 소수라면 answer의 값을 1 늘린다
        n = parseInt(n)
        if (n > 1 && isPrime(n)) answer++;
    })
    
    return answer;
}
