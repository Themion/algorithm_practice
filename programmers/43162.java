package programmers;

import java.util.HashSet;
import java.util.Set;

class Solution {
  public int solution(int n, int[][] computers) {
    int answer = 0;
    Set<Integer> set = new HashSet<>();

    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          computers[i][j] |= computers[i][k] & computers[k][j];

    for (int i = 0; i < n; i++)
      if (!set.contains(i)) {
        answer++;
        for (int j = 0; j < n; j++)
          if (computers[i][j] == 1)
            set.add(j);
      }

    return answer;
  }
}