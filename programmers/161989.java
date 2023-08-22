package programmers;

class Solution {
  public int solution(int n, int m, int[] section) {
    int answer = 0;
    Integer lastPainted = -1;

    for (Integer loc : section) {
      if (lastPainted < loc) {
        answer += 1;
        lastPainted = loc + m - 1;
      }
    }

    return answer;
  }
}
