#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

// 이후 나올 컨테이너 C의 길이
int c_size;
// 메뉴를 전역변수로 저장해 check_menu 함수의 인자 길이를 줄인다
string order;
// 세트메뉴 길이 중 가능한 길이의 집합
vector<int> C;
// m[i]: 메뉴 리스트에서 가능한 세트메뉴를
// 세트메뉴 문자열의 길이별로 분류해 저장
map<string, int> m[11];

//메뉴 리스트를 가져와 만들 수 있는 세트를 m에 저장
void check_menu(string menu, int idx) {
    // menu의 길이가 가능한 세트메뉴의 길이일 때 menu를 m에 저장
    for (int i = 0; i < c_size; i++)
        if (menu.size() == C[i]) {
            m[menu.size()][menu]++;
            break;
        }
    
    // 메뉴의 크기를 가져온 뒤
    int size = order.size();
    // 메뉴 중 아직 확인하지 않은 단품 메뉴가 있다면 세트메뉴에 넣어본다
    for (int i = idx; i < size; i++) 
        check_menu(menu + order[i], i + 1);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    // orders.size()를 자주 호출하지 않게끔 변수에 orders.size()를 저장
    int o_size = orders.size();
    
    // 다른 함수에서 course를 호출해야 하므로 전역변수에 course를 저장
    C = course;
    // course.size()를 자주 호출하지 않게끔 변수에 course.size()를 저장
    c_size = C.size();
    
    // 각 메뉴에서 만들 수 있는 세트메뉴를 계산
    for (int i = 0; i < o_size; i++) {
        sort(orders[i].begin(), orders[i].end());
        order = orders[i];
        check_menu(string(), 0);
    }
    
    // 각 세트메뉴의 길이에 대해
    for (auto c : C) {
        // 가장 많이 주문한 세트메뉴의 주문 수
        // 세트메뉴는 같은 메뉴를 주문한 사람이 둘 이상이어야 코스요리가 된다
        int max = 2;
        // 가장 많이 주문된 세트메뉴
        vector<string> menu;
        // 길이가 c인 세트메뉴의 집합
        auto &m_ = m[c];
        
        // 집합의 각 원소에 대해
        for (auto it = m_.begin(); it != m_.end(); it++) {
            // 주문 횟수가 max보다 많은 세트메뉴가 있다면 menu와 max를 초기화
            if (max < it->second) {
                menu = vector<string>();
                max = it->second;
            }
            
            // 주문 횟수가 max인 세트메뉴를 menu에 추가
            if (max == it->second) menu.push_back(it->first);
        }
        
        // 주문 횟수가 가장 많은 세트메뉴들을 answer에 추가
        for (auto it = menu.begin(); it != menu.end(); it++) 
            answer.push_back(*it);
        
        // 세트메뉴의 집합을 정렬해야 한다
        sort(answer.begin(), answer.end());
    }
    
    return answer;
}