package programmers;

import java.util.Stack;

class Solution {
  public int solution(int[][] board, int[] moves) {
    int depth = board.length, answer = 0;
    int[] pos = new int[board[0].length];
    Stack<Integer> stack = new Stack<>();

    for (int i = 0; i < pos.length; i++) {
      int j = 0;
      while (j < board.length && board[j][i] == 0)
        j++;
      pos[i] = j;
    }

    for (int move : moves) {
      move -= 1;
      if (pos[move] >= depth)
        continue;

      int p = Math.min(pos[move]++, board[0].length - 1);
      Integer newItem = board[p][move];

      if (stack.empty() || stack.lastElement() != newItem)
        stack.push(newItem);
      else {
        answer++;
        stack.pop();
      }
    }

    return answer << 1;
  }
}
