package programmers;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {
  public int[] solution(int[] numbers) {
    Set<Integer> set = new HashSet<>();

    for (int i = 0; i < numbers.length; i++)
      for (int j = i + 1; j < numbers.length; j++)
        set.add(numbers[i] + numbers[j]);

    int[] result = set.stream().mapToInt(i -> i).toArray();
    Arrays.sort(result);
    return result;
  }
}