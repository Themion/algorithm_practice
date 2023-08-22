package programmers;

class Solution {
  private Integer removedZero = 0;
  private Integer transformCount = 0;

  private String binaryTransform(String s) {
    Integer count = 0;
    char[] arr = s.toCharArray();
    for (char c : arr)
      if (c == '1')
        count++;

    removedZero += s.length() - count;
    transformCount++;

    return Integer.toBinaryString(count);
  }

  public int[] solution(String s) {
    do {
      s = this.binaryTransform(s);
    } while (!s.equals("1"));

    int[] answer = { this.transformCount, this.removedZero };

    return answer;
  }
}