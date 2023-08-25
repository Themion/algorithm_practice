package programmers;

class Solution {
  int[][] matrix_sizes;

  // i부터 j - 1까지, j부터 k - 1까지 곱했을 때 남은 두 행렬의 곱
  public int getCalc(int i, int j, int k) {
    return matrix_sizes[i][0] * matrix_sizes[j][0] * matrix_sizes[k - 1][1];
  }

  public int solution(int[][] matrix_sizes) {
    this.matrix_sizes = matrix_sizes;
    int length = matrix_sizes.length;

    int[][] cost = new int[length + 1][length + 1];
    for (int i = 0; i < length - 1; i++)
      cost[i][i + 2] = getCalc(i, i + 1, i + 2);

    for (int dist = 2; dist <= length; dist++) {
      for (int i = 0; i + dist <= length; i++) {
        int min = 0x3f3f3f3f;

        for (int j = i + 1; j < i + dist; j++) {
          int memoized = cost[i][j] + cost[j][i + dist];
          int currCost = getCalc(i, j, i + dist);

          min = Math.min(min, memoized + currCost);
        }

        cost[i][i + dist] = min;
      }
    }

    return cost[0][length];
  }
}
