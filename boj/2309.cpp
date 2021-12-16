#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    // height: 각 난쟁이의 키
    // sum: 키의 합. 올바른 난쟁이의 키의 합이 100이므로
    // 잘못된 난쟁이의 키의 합은 height의 합 - 100일 것이다
    // l, r : 난쟁이를 찾을 때 쓸 인덱스
    int height[9], sum = -100, l = 0, r = 8;

    // 난쟁이의 키를 입력받아 sum에 더한다
    for (int i = 0; i < 9; i++) {
        scanf("%d", &height[i]);
        sum += height[i];
    }

    // 난쟁이들의 키를 정렬한다
    sort(height, height + 9);

    // sum은 아홉 난쟁이의 키의 크기에서 100을 뺀 값이므로
    // 두 난쟁이 l와 r의 키의 합이 sum과 같다면
    // l번째 난쟁이와 r번째 난쟁이는 잘못된 난쟁이이다
    while (height[l] + height[r] != sum)
        // 투 포인터를 이용해 오름차순으로 정렬된 난쟁이의 키에서
        // 잘못된 두 난쟁이를 찾는다
        (height[l] + height[r] < sum) ? l++ : r--;

    // 올바른 난쟁이들의 키를 출력한다
    for (int i = 0; i < 9; i++) if ((i != l) && (i != r))
        printf("%d\n", height[i]);

    return 0;
}
