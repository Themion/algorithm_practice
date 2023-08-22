package programmers;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
  public int[] solution(String[] name, int[] yearning, String[][] photo) {
    Map<String, Integer> score = new HashMap<>();
    List<Integer> answer = new ArrayList<>();

    for (int i = 0; i < name.length; i++)
      score.put(name[i], yearning[i]);

    for (String[] names : photo) {
      Integer val = 0;
      for (String str : names)
        val += score.getOrDefault(str, 0);
      answer.add(val);
    }

    return answer.stream().mapToInt(i -> i).toArray();
  }
}