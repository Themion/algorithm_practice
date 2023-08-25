package programmers;

import java.util.*;

class Node {
  public Integer pos = 0, status = 0;

  Node() {
  }

  Node(Integer pos, Integer status) {
    this.pos = pos;
    this.status = status;
  }
}

class Solution {
  public int solution(int[][] routes) {
    int answer = 0;
    Node[] line = new Node[routes.length * 2];
    Set<Integer> observed = new HashSet<>(), entered = new HashSet<>();

    for (int i = 0; i < routes.length; i++) {
      line[2 * i] = new Node(routes[i][0], i + 1);
      line[2 * i + 1] = new Node(routes[i][1], -i - 1);
    }

    Arrays.sort(line, (a, b) -> {
      if (a.pos == b.pos)
        return b.status - a.status;
      return a.pos - b.pos;
    });

    for (Node node : line) {
      if (node.status > 0)
        entered.add(node.status);
      else {
        node.status *= -1;

        if (!observed.contains(node.status)) {
          answer++;
          observed.addAll(entered);
        }
      }
    }

    return answer;
  }
}
