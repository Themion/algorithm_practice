package programmers;

import java.math.BigInteger;

class Solution {
  public int solution(String number) {
    BigInteger num = new BigInteger(number);
    BigInteger nine = new BigInteger("9");

    return num.remainder(nine).intValue();
    // return number.chars().map(c -> c - '0').sum() % 9;
  }
}