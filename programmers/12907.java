package programmers;

class Solution {
  public int solution(int n, int[] money) {
    int[] answer = new int[n + 1];

    for (int i = 0; i <= n; i++)
      answer[i] = 0;
    answer[0] = 1;

    for (int m : money)
      for (int i = m; i <= n; i++)
        answer[i] = (answer[i] + answer[i - m]) % 1000000007;

    return answer[n];
  }
}
