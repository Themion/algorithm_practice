package programmers;

class Solution {
  int[][] sum = new int[2001][2002];

  public int binarySearch(int height, int start, int end, int target) {
    int mid = 0;
    int[] arr = sum[height];

    while (start < end) {
      mid = (start + end) / 2;

      if (arr[mid] == target)
        break;
      else if (arr[mid] < target) {
        if (start + 1 == end)
          return 0;
        start = mid;
      } else
        end = mid;
    }

    return mid;
  }

  public int solution(int[] cookie) {
    int answer = 0, len = cookie.length;
    for (int i = 0; i <= len; i++)
      for (int j = 0; j <= len; j++)
        sum[i][j] = 0;

    for (int i = 0; i < len; i++)
      for (int j = 0; i + j < len; j++)
        sum[i][i + j + 1] = sum[i][i + j] + cookie[i + j];

    for (int i = 0; i < len - 1; i++)
      for (int cnt = 2; i + cnt <= len; cnt++) {
        if (sum[i][i + cnt] % 2 != 0)
          continue;

        int m = binarySearch(i, i + 1, i + cnt + 1, sum[i][i + cnt] / 2);
        if (sum[i][m] == sum[m][i + cnt])
          answer = Math.max(sum[i][m], answer);
      }

    return answer;
  }
}
