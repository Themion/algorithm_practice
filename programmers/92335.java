package programmers;

import java.util.Arrays;

class Solution {
  private Boolean isPrime(Long num) {
    if (num <= 1L)
      return false;

    Long pivot = (long) Math.floor(Math.sqrt(num));
    for (Long i = 2L; i <= pivot; i++)
      if (num % i == 0)
        return false;

    return true;
  }

  public int solution(int n, int k) {
    String str = "";

    for (; n > 0; n /= k)
      str += (char) ((n % k) + '0');

    String[] arr = new StringBuffer(str).reverse().toString().split("0");
    return Arrays
        .stream(arr)
        .filter((s) -> !s.equals(""))
        .map(s -> Long.parseLong(s))
        .filter(s -> isPrime(s))
        .toArray().length;
  }
}