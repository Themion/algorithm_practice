package programmers;

class Solution {
  public int solution(int n, int[][] results) {
    int answer = 0;

    Boolean[][] edges = new Boolean[100][100];

    for (int[] result : results) {
      int win = result[0] - 1, lose = result[1] - 1;
      edges[win][lose] = true;
      edges[lose][win] = false;
    }

    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if (edges[i][k] != null && edges[i][k] == edges[k][j]) {
            edges[i][j] = edges[i][k];
            edges[j][i] = edges[k][i];
          }

    for (int i = 0; i < n; i++) {
      int count = 0;
      for (int j = 0; j < n; j++)
        if (i == j || edges[i][j] != null)
          count += 1;
      if (count == n)
        answer += 1;
    }

    return answer;
  }
}