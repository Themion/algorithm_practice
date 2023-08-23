package programmers;

import java.util.Arrays;

class Solution {
  public int solution(int[][] triangle) {
    Integer len = triangle.length;

    for (int i = 1; i < len; i++) {
      int[] layer = triangle[i - 1];

      triangle[i][0] += layer[0];
      triangle[i][i] += layer[i - 1];
      for (int j = 1; j < i; j++)
        triangle[i][j] += Math.max(layer[j - 1], layer[j]);
    }

    return Arrays.stream(triangle[len - 1]).max().getAsInt();
  }
}