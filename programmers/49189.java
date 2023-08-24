package programmers;

import java.util.*;

class Solution {
  public int solution(int n, int[][] edge) {
    Integer[] dist = new Integer[n + 1];
    int maxDist = 0, answer = 0;
    Set<Integer>[] graph = new Set[n + 1];
    Queue<Integer> q = new LinkedList<>();

    for (int i = 1; i <= n; i++)
      graph[i] = new HashSet<>();

    for (int[] e : edge) {
      Integer node1 = e[0];
      Integer node2 = e[1];

      graph[node1].add(node2);
      graph[node2].add(node1);
    }

    q.add(1);
    dist[1] = 0;

    while (!q.isEmpty()) {
      Integer node = q.poll();
      maxDist = Math.max(maxDist, dist[node]);

      graph[node].stream().forEach(nextNode -> {
        if (dist[nextNode] == null) {
          dist[nextNode] = dist[node] + 1;
          q.add(nextNode);
        }
      });
    }

    for (int i = 1; i <= n; i++)
      if (dist[i] == maxDist)
        answer++;
    return answer;
  }
}