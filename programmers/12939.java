package programmers;

import java.util.Arrays;

class Solution {
  public String solution(String s) {
    int[] nums = Arrays.stream(s.split(" ")).map(str -> Integer.parseInt(str)).mapToInt(i -> i).toArray();
    return Arrays.stream(nums).min().getAsInt() + " " + Arrays.stream(nums).max().getAsInt();
  }
}