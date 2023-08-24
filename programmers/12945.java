package programmers;

class Solution {
  public int solution(int n) {
    Integer[] fibo = new Integer[100001];
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= n; i++)
      fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1234567;
    return fibo[n];
  }
}
