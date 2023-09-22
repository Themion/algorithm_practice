#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>> q;
    for (auto val : scoville) q.push(val);

    while (q.size() > 1 && q.top() < K) {
        int tmp = q.top();
        q.pop();
        tmp += q.top() * 2;
        q.pop();
        q.push(tmp);
        answer += 1;
    }
    
    return q.top() < K ? -1 : answer;
}
