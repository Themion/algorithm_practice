#include <algorithm>
#include <cstdio>
 
using namespace std;
 
int main() {
    // num: 각 난쟁이의 모자에 적힌 값
    // sum: num의 합 - 100. 올바른 난쟁이의 모자에 적힌 값의 합이 100이므로
    //      잘못된 난쟁이의 모자에 적힌 값의 합은 num의 합 - 100일 것이다
    // l, r : 난쟁이를 찾을 때 쓸 인덱스
    int num[9], sum = -100, l = 0, r = 8;
 
    // 난쟁이의 모자에 적힌 값을 입력받아 sum에 더한다
    for (int i = 0; i < 9; i++) {
        scanf("%d", &num[i]);
        sum += num[i];
    }
 
    // 입력을 정렬
    sort(num, num + 9);
 
    // 두 난쟁이 l와 r의 수의 합이 sum과 같다면
    // l번째 난쟁이와 r번째 난쟁이는 잘못된 난쟁이이다
    while (num[l] + num[r] != sum)
        // 투 포인터를 이용해 오름차순으로 정렬된 난쟁이의 수에서
        // 잘못된 두 난쟁이를 찾는다
        (num[l] + num[r] < sum) ? l++ : r--;
 
    // 올바른 난쟁이들의 수를 출력한다
    for (int i = 0; i < 9; i++) if ((i != l) && (i != r))
        printf("%d\n", num[i]);
 
    return 0;
}
