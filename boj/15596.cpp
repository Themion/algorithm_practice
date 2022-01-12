#include <vector>

long long sum(std::vector<int> &a) {
	long long ans = 0;
    // a의 모든 성분을 더한 뒤 반환
    for (auto i : a) ans += i;
	return ans;
}
