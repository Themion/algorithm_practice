package programmers;

class Solution {
  private Integer removedZero = 0;
  private Integer transformCount = 0;

  private String binaryTransform(String s) {
    Integer count = s.replaceAll("0", "").length();

    removedZero += s.length() - count;
    transformCount++;

    return Integer.toBinaryString(count);
  }

  public int[] solution(String s) {
    while (!s.equals("1"))
      s = this.binaryTransform(s);

    int[] answer = { this.transformCount, this.removedZero };

    return answer;
  }
}