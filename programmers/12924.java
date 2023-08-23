package programmers;

class Solution {
  public int solution(int n) {
    int answer = 0;
    int sum = 0, l = 1, r = 1;

    do {
      if (sum < n)
        sum += r++;
      else {
        if (sum == n)
          answer += 1;
        sum -= l++;
      }
    } while (l < r);

    return answer;
  }
}