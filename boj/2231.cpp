#include <cstdio>

int main() {
    // N: 생성자를 구할 분해합, mkr: 생성자를 저장할 공간, k: N의 자릿수
    // sum, k: 각 생성자로 만들어지는 수
    int N, mkr = 0, k = 0, sum;

    //분해합을 입력받은 뒤
    scanf("%d", &N);
    sum = N;

    // N의 자리수를 k에 저장
    while (sum > 0) {
        k += 1;
        sum /= 10;
    }

    // 각 자리의 최대값은 9이므로 
    // 생성자의 최소값은 (분해합 - (9 *  분해합의 자리수))이다
    // 생성자의 각 후보에 대해
    for (int i = N - (9 * k); i <= N; i++) {
        // mkr로 분해합을 생성해 sum에 저장한 뒤
        mkr = sum = i;
        while (mkr > 0) {
            sum += mkr % 10;
            mkr /= 10;
        }

        // 생성한 분해합이 N과 같다면 mkr에 i를 넣고 루프문을 빠져나간다
        if (sum == N) {
            mkr = i;
            break;
        }
    }

    // 분해합 N을 만들지 못했다면 mkr은 0이고
    // N을 만들었다면 mkr은 정답인 생성자이므로 결국 답은 mkr이다
    printf("%d\n", mkr);

    return 0;
}
