//제출란의 템플릿을 이용함
#include <vector>
long long sum(std::vector<int> &a) {
	long long ans = 0;
    //a의 모든 성분을 더한 뒤 출력한다
    for (auto i : a) ans += i;
	return ans;
}
