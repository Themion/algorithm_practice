package programmers;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {
  public int solution(int n, int[] lost, int[] reserve) {
    Set<Integer> lostSet = new HashSet<>();
    Set<Integer> reserveSet = new HashSet<>();

    for (Integer num : lost)
      lostSet.add(num);
    for (Integer num : reserve)
      reserveSet.add(num);

    Arrays.sort(lost);

    for (Integer val : lost) {
      if (reserveSet.contains(val)) {
        lostSet.remove(val);
        reserveSet.remove(val);
      }
    }

    for (Integer val : lost) {
      if (reserveSet.contains(val - 1)) {
        lostSet.remove(val);
        reserveSet.remove(val - 1);
      } else if (reserveSet.contains(val + 1)) {
        lostSet.remove(val);
        reserveSet.remove(val + 1);
      }
    }

    return n - lostSet.size();
  }
}