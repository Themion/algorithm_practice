package programmers;

class Solution {
  public int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++)
      answer += i * (Math.sqrt(i) % 1 != 0 ? 1 : -1);
    return answer;
  }
}