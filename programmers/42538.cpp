#include <string>
#include <vector>
#include <queue>

using namespace std;

class node {
public:
    int time, weight;
    node() {}
    node(int time, int weight) {
        this->time = time;
        this->weight = weight;
    }
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int on_bridge = 0, passed = 0, all_passed = 0, time = 0, idx = 0;
    queue<node> q;
    
    for (auto w : truck_weights) all_passed += w;
    
    for (; passed < all_passed; time++) {
        int w = truck_weights[idx];

        if (q.size() > 0) {
            node n = q.front();
            if (time - n.time >= bridge_length) {
                q.pop();
                on_bridge -= n.weight;
                passed += n.weight;
            }
        }
        if (on_bridge + w < weight) {
            idx += 1;
            q.push(node(time, w));
            on_bridge += w;
        }
    }
    
    return time;
}

int main () {
  int bridge_length = 100, weight = 100;
  vector<int> truck_weights = vector<int>(10, 10);
  solution(bridge_length, weight, truck_weights);
}