package programmers;

class Solution {
  public int solution(int n, int s, int a, int b, int[][] fares) {
    int answer = n * 1000000;

    s -= 1;
    a -= 1;
    b -= 1;

    int[][] edges = new int[n][];
    for (int i = 0; i < n; i++) {
      edges[i] = new int[n];
      for (int j = 0; j < n; j++)
        edges[i][j] = i == j ? 0 : 1000000;
    }

    for (int[] fare : fares) {
      int c = fare[0] - 1, d = fare[1] - 1, f = fare[2];
      edges[c][d] = edges[d][c] = f;
    }

    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          edges[i][j] = Math.min(edges[i][j], edges[i][k] + edges[k][j]);

    for (int i = 0; i < n; i++) {
      int sum = edges[s][i] + edges[i][a] + edges[i][b];
      if (answer > sum)
        answer = sum;
    }

    return answer;
  }
}
