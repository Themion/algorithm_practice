#include <algorithm>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

vector<int> emp[3][2][2][2];

string strtok(string str, int &idx);

// info와 query를 분석해 class의 형태로 저장
class employee {
public:
    // 각각 언어, 직군, 경력, 소울푸드
    string lang, group, career, food;
    // 코딩테스트 점수
    int rank;
    
    employee() {}
    // str을 분석하여 employee의 형태로 저장
    // and가 들어가 있는 문장일 경우 and를 패싱
    employee(string str, bool is_and) {
        int idx = 0;

        this->lang   = strtok(str, idx);        // 언어
        if (is_and)    strtok(str, idx);        // and 제거
        this->group  = strtok(str, idx);        // 직군
        if (is_and)    strtok(str, idx);        // and 제거
        this->career = strtok(str, idx);        // 경력
        if (is_and)    strtok(str, idx);        // and 제거
        this->food   = strtok(str, idx);        // 소울푸드
        this->rank   = stoi(strtok(str, idx));  // 점수
    }
};

// a와 b가 같거나 둘 중 하나가 -일 때 true
bool str_cmp(string a, string b) {
    return a == b || a == "-" || b == "-";
}

// str[idx:]에서 ' '가 나오기 직전까지의 문자열
// 편의를 위해 idx는 레퍼런스로 사용
string strtok(string str, int &idx) {
    string ret = "";

    // ' '이 나올 때까지 ret에 각 문자열을 push
    while (str[idx] != ' ') ret.push_back(str[idx++]);
    // str[idx] == ' '이므로 편의를 위해 idx에 1을 더한다
    idx++;

    return ret;
}

// e를 사용언어, 직군, 경력, 소울푸드에 따라 분류하여 emp에 저장
void push(employee e) {
    int lang = (e.lang == "cpp") ? 0 : ( (e.lang=="java") ? 1 : 2 );
    int group = e.group == "frontend";
    int career = e.career == "senior";
    int food = e.food == "pizza";
    
    emp[lang][group][career][food].push_back(e.rank);
}

// 합격자 정보 info를 받아 조건 query에 맞는 사용자의 수를
// vector<int>로 반환
vector<int> solution(vector<string> info, vector<string> query) {
    int i_size = info.size(), q_size = query.size();
    vector<int> answer(q_size);
    
    // info의 각 항목을 employee 클래스로 parse해 emp에 저장
    for (auto i: info) push(employee(i + ' ', false));
    
    // emp의 각 항목을 lower_bound 함수를 위해 저장
    for (int i = 0; i < 3; i++) for (int j = 0; j < 2; j++) 
        for (int k = 0; k < 2; k++) for (int l = 0; l < 2; l++)
            sort(emp[i][j][k][l].begin(), emp[i][j][k][l].end());
    
    // query의 각 항목을 employee 클래스로 parse해 emp에서 탐색
    for (int idx = 0; idx < q_size; idx++) {
        employee e = employee(query[idx] + ' ', true);
        
        // query의 조건에 맞는 값을 항목별로 배열에 저장
        vector<int> lang, group, career, food;
        
        if (str_cmp(e.lang, "cpp")) lang.push_back(0);
        if (str_cmp(e.lang, "java")) lang.push_back(1);
        if (str_cmp(e.lang, "python")) lang.push_back(2);
        
        if (str_cmp(e.group, "backend")) group.push_back(0);
        if (str_cmp(e.group, "frontend")) group.push_back(1);
        
        if (str_cmp(e.career, "junior")) career.push_back(0);
        if (str_cmp(e.career, "senior")) career.push_back(1);
        
        if (str_cmp(e.food, "chicken")) food.push_back(0);
        if (str_cmp(e.food, "pizza")) food.push_back(1);
        
        // 배열의 각 성분에 대해 lower_bound를 이용해
        // 점수가 query의 rank 이상인 info의 수를 계산
        for (auto l: lang) for (auto g: group) 
            for (auto c: career) for (auto f: food) {
            auto v = emp[l][g][c][f];
            int p = lower_bound(v.begin(), v.end(), e.rank) - v.begin();
            answer[idx] += v.size() - p;
        }
    }
    
    return answer;
}