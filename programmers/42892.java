package programmers;

import java.util.Arrays;

class Node {
  public Integer x, y, val;
  public Node left = null, right = null;

  Node() {
  }

  Node(Integer val, Integer x, Integer y) {
    this.val = val;
    this.x = x;
    this.y = y;
  }
}

class Solution {
  int frontIdx = 0, backIdx = 0;

  private int midSearch(Node[] nodes, int start, int end) {
    if (start + 1 == end)
      return start;
    if (start + 1 > end)
      return -1;

    int maxY = 0, maxPos = -1, left, right;

    for (int i = start; i < end; i++)
      if (maxY < nodes[i].y) {
        maxY = nodes[i].y;
        maxPos = i;
      }

    left = midSearch(nodes, start, maxPos);
    right = midSearch(nodes, maxPos + 1, end);

    if (left >= 0)
      nodes[maxPos].left = nodes[left];
    if (right >= 0)
      nodes[maxPos].right = nodes[right];

    return maxPos;
  }

  private void frontSearch(Node node, int[] answer) {
    answer[frontIdx++] = node.val;
    if (node.left != null)
      frontSearch(node.left, answer);
    if (node.right != null)
      frontSearch(node.right, answer);
  }

  private void backSearch(Node node, int[] answer) {
    if (node.left != null)
      backSearch(node.left, answer);
    if (node.right != null)
      backSearch(node.right, answer);
    answer[backIdx++] = node.val;
  }

  public int[][] solution(int[][] nodeinfo) {
    Integer len = nodeinfo.length, root;
    int[][] answer = new int[2][nodeinfo.length];
    Node[] nodes = new Node[len];

    for (int i = 0; i < len; i++)
      nodes[i] = new Node(i + 1, nodeinfo[i][0], nodeinfo[i][1]);

    Arrays.sort(nodes, (a, b) -> a.x - b.x);
    root = midSearch(nodes, 0, len);

    frontSearch(nodes[root], answer[0]);
    backSearch(nodes[root], answer[1]);

    return answer;
  }
}