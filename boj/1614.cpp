#include <cstdio>

typedef long long ull;

// 손가락 일일히 세보기
int manual[8] = {1, 2, 3, 4, 5, 4, 3, 2};
// hurt: 다친 손가락, add_per_set: 손가락 한번에 8개씩 세기
int hurt, add_per_set = 1;
// cnt: 손가락으로 수 센 횟수, limit: 다친 손가락의 한계
ull cnt = 0, limit;

int main() {
    // 다친 손가락의 위치와 한계를 입력받은 뒤
    scanf("%d %lld", &hurt, &limit);
    // 손가락이 엄지 혹은 약지가 아니라면 app_per_set을 1 더한다
    add_per_set += ((hurt - 1) % 4 != 0);

    // 엄지 ~ 약지, 새끼 ~ 검지씩 수를 8번 세는 걸 한 세트로 묶고
    // cnt를 세트 수 * 8만큼 더한 뒤 손가락의 내구도를 재계산
    cnt = 8 * (limit / add_per_set);
    limit %= add_per_set;

    // 대략적으로 센 뒤 오차를 맞추기 위해 일일히 손으로 센다
    for (int i = 0; limit >= 0; i++) {
        if (manual[i % 8] == hurt) limit--;
        cnt++;
    }

    // 다친 손가락의 내구도가 -1이 되는 순간 루프문이 종료되므로
    // 센 횟수에서 1을 차감한 값을 출력
    printf("%lld\n", cnt - 1);

    return 0;
}