package programmers;

class Solution {
  public String solution(String s) {
    String answer = "";
    Boolean flag = true;
    char[] arr = s.toCharArray();

    for (char c : arr) {
      answer += flag ? Character.toUpperCase(c) : Character.toLowerCase(c);
      flag = c == ' ';
    }

    return answer;
  }
}