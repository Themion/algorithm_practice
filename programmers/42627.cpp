#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include <iostream>

using namespace std;

class node {
public:
    int work, req;
    node() {}
    node(int work, int req) {
        this->work = work;
        this->req = req;
    }
};

bool operator<(node a, node b) { return a.work < b.work; }
bool operator>(node a, node b) { return a.work > b.work; }

int solution(vector<vector<int>> jobs) {
    int answer = 0, current = 0;
    vector<node> v;
    priority_queue<node, vector<node>, greater<node>> q;
    
    for (auto job : jobs) {
        int req = job[0], work = job[1];
        v.push_back(node(work, req));
    }
    
    sort(v.begin(), v.end(), [](node a, node b) { return a.req > b.req; });

    q.push(v.back());
    v.pop_back();
    
    while (!q.empty()) {
        node n = q.top();
        q.pop();

        current = max(current, n.req);
        answer += n.work + current - n.req;
        current += n.work;
        
        while (!v.empty() && (v.back().req < current || q.empty())) {
            q.push(v.back());
            v.pop_back();
        }
    }
    
    return answer / jobs.size();;
}
