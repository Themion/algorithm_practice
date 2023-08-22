package programmers;

import java.math.BigInteger;

class Solution {
  public int solution(String t, String p) {
    int answer = 0;
    Integer tLen = t.length(), pLen = p.length(), range = tLen - pLen;
    BigInteger P = new BigInteger(p);

    for (int i = 0; i <= range; i++) {
      BigInteger T = new BigInteger(t.substring(i, i + pLen));
      if (T.compareTo(P) != 1)
        answer += 1;
    }

    return answer;
  }
}