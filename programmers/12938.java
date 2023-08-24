package programmers;

class Solution {
  public int[] solution(int n, int s) {
    if (n > s)
      return new int[] { -1 };

    int[] answer = new int[n];
    int div = s / n, diff = s - (div * n);

    for (int i = 0; i < n; i++) {
      int index = n - i - 1;
      answer[index] = div + (i < diff ? 1 : 0);
    }

    return answer;
  }
}
