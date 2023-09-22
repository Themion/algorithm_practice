#include <string>
#include <vector>
#include <queue>

using namespace std;

class node {
public:
    int val, idx;
    node() {}
    node(int val, int idx) {
        this->val = val;
        this->idx = idx;
    }
};

bool operator<(node a, node b) { return a.val < b.val; }
bool operator>(node a, node b) { return a.val > b.val; }

vector<int> solution(vector<int> prices) {
    int local_max = 0, size = prices.size();
    priority_queue<node, vector<node>, less<node>> q;
    vector<int> answer = vector<int>(size);

    for (int i = 0; i < size; i++) {
        int price = prices[i];

        while (!q.empty() && q.top().val > price) {
            node n = q.top();
            q.pop();
            answer[n.idx] = i - n.idx;
        }
        
        q.push(node(price, i));
    }
    
    while (!q.empty()) {
        node n = q.top();
        q.pop();
        
        answer[n.idx] = (size - 1) - n.idx;
    }
 
    return answer;
}
