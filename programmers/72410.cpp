#include <string>
#include <vector>

using namespace std;

bool is_character(char c) {
    return c >= 'a' && c <= 'z';
}

bool is_special(char c) {
    return c == '.' || c == '-' || c == '_';
}

bool is_number(char c) {
    return c >= '0' && c <= '9';
}

string solution(string new_id) {
    int size = new_id.size();
    string answer = "";

    for (int i = 0; i < size; i++) {    
        char c = new_id[i];
        
        // 1단계 규칙
        if (c >= 'A' && c <= 'Z')
            c += 'a' - 'A';
        
        // 2단계 규칙
        else if (!(is_character(c) || is_special(c) || is_number(c))) 
            continue;
        
        // 3단계 규칙
        else if (i > 0 && c == '.' && answer.back() == '.')
            continue;
        
        answer += c;
    }
    
    // 4단계 규칙
    if (answer.back() == '.') answer.pop_back();
    if (!answer.empty() && answer.front() == '.') answer = answer.substr(1, 1001);
    
    // 5단계 규칙
    if (answer.empty()) answer = "a";
    
    // 6단계 규칙
    while (answer.size() > 15 || answer.back() == '.') answer.pop_back();
    
    // 7단계 규칙
    while (answer.size() < 3) answer.push_back(answer.back());
    
    return answer;
}