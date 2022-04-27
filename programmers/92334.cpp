#include <string>
#include <map>
#include <vector>

#define MAX_LEN 1000

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    bool rep[MAX_LEN][MAX_LEN] = {{ false, }};
    int len = id_list.size(), split, from, to, time[MAX_LEN] = { 0, };
    map<string, int> m;
    vector<int> answer(len);
    
    for (int i = 0; i < len; i++) m[id_list[i]] = i;
    
    for (auto log: report) {
        split = log.find(' ');
        from = m[log.substr(0, split)];
        to = m[log.substr(split + 1)];
        
        if (!rep[to][from]) {
            time[to]++;
            rep[to][from] = true;
        }
    }
    
    for (int i = 0; i < len; i++) if (time[i] >= k) {
        for (int j = 0; j < len; j++) answer[j] += rep[i][j];
    }
    
    return answer;
}
