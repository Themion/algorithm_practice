package programmers;

class Solution {
  public String solution(String s) {
    String answer = "";
    Boolean flag = true;
    char[] arr = s.toCharArray();

    for (char c : arr) {
      if (c != ' ') {
        c = flag ? Character.toUpperCase(c) : Character.toLowerCase(c);
        flag = !flag;
      } else
        flag = true;

      answer += c;
    }

    return answer;
  }
}
