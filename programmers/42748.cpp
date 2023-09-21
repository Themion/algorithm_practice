#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto cmd : commands) {
        vector<int> arr = array;
        int start = cmd[0] - 1, end = cmd[1], order = start + cmd[2] - 1;
        nth_element(arr.begin() + start, arr.begin() + order, arr.begin() + end);
        answer.push_back(arr[order]);
    }
    
    return answer;
}