package programmers;

import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

class Solution {
  private boolean isAdjacent(String word1, String word2) {
    Integer len = word2.length(), match = 0;
    char[] arr1 = word1.toCharArray(), arr2 = word2.toCharArray();

    for (int i = 0; i < len; i++)
      if (arr1[i] == arr2[i])
        match += 1;

    return match == len - 1;
  }

  private Map<String, Set<String>> createMap(String begin, String[] words) {
    Map<String, Set<String>> map = new HashMap<>();

    map.put(begin, new HashSet<>());
    for (String word : words)
      map.put(word, new HashSet<>());

    for (String word1 : words) {
      if (isAdjacent(begin, word1)) {
        map.get(begin).add(word1);
        map.get(word1).add(begin);
      }

      for (String word2 : words)
        if (isAdjacent(word1, word2)) {
          map.get(word1).add(word2);
          map.get(word2).add(word1);
        }
    }

    return map;
  }

  public int solution(String begin, String target, String[] words) {
    Map<String, Set<String>> map = createMap(begin, words);
    Map<String, Integer> dist = new HashMap<>();
    Queue<String> q = new LinkedList<>();

    q.add(begin);
    dist.put(begin, 0);

    while (!q.isEmpty()) {
      String now = q.poll();
      Integer currDist = dist.get(now);

      map.get(now).stream().forEach(next -> {
        Integer nextDist = dist.get(next);

        if (nextDist != null && nextDist <= currDist + 1)
          return;
        q.add(next);
        dist.put(next, currDist + 1);
      });
    }

    return dist.containsKey(target) ? dist.get(target) : 0;
  }
}
