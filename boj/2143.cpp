#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vec;

// 배열을 입력받아 모든 부분합을 v에 저장
void make_array(vec &v) {
    // arr: 배열의 각 성분, size: 배열의 길이
    int arr[1000] = { 0, }, size;

    // 배열 입력
    scanf("%d", &size);
    for (int i = 0; i < size; i++) scanf("%d", arr + i);

    // 배열의 각 성분에서 시작하는 연속합을 v에 push
    for (int i = 0; i < size; i++) {
        v.push_back(arr[i]);
        for (int j = i + 1; j < size; j++) 
            v.push_back(v.back() + arr[j]);
    }

    // v를 정렬
    sort(v.begin(), v.end());
}

int main() {
    int T;
    long long ans = 0;
    vec A, B;

    scanf("%d", &T);

    // A와 B를 각각 입력받아 부분합을 모두 저장
    make_array(A);
    make_array(B);

    // A의 각 부분합 a에 대해
    for (auto a : A) {
        int t = T - a;
        // B의 부분합 중 T - a의 수만큼 ans를 더한다
        ans += upper_bound(B.begin(), B.end(), t) 
             - lower_bound(B.begin(), B.end(), t);
    }

    // ans 출력
    printf("%lld\n", ans);

    return 0;
}