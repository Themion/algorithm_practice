package programmers;

class Position {
  public int r = -1, c = -1;

  Position() {
  }

  Position(int r, int c) {
    this.r = r;
    this.c = c;
  }

  static int dist(Position a, Position b) {
    return Math.abs(a.r - b.r) + Math.abs(a.c - b.c);
  }
}

class Solution {
  private String answer = "";
  private Position left = new Position(3, 0), right = new Position(3, 2);

  static Position[] pos = {
      new Position(3, 1),
      new Position(0, 0), new Position(0, 1), new Position(0, 2),
      new Position(1, 0), new Position(1, 1), new Position(1, 2),
      new Position(2, 0), new Position(2, 1), new Position(2, 2)
  };

  private void moveLeft(int n) {
    this.left = Solution.pos[n];
    this.answer += 'L';
  }

  private void moveRight(int n) {
    this.right = Solution.pos[n];
    this.answer += 'R';
  }

  public String solution(int[] numbers, String hand) {
    Boolean isLeft = hand.equals("left");

    for (int n : numbers) {
      switch (n) {
        case 1:
        case 4:
        case 7:
          this.moveLeft(n);
          break;

        case 3:
        case 6:
        case 9:
          this.moveRight(n);
          break;

        case 2:
        case 5:
        case 8:
        case 0:
        default:
          int leftDist = Position.dist(this.left, Solution.pos[n]),
              rightDist = Position.dist(this.right, Solution.pos[n]);
          Boolean doLeft = leftDist == rightDist ? isLeft : leftDist < rightDist;
          if (doLeft)
            this.moveLeft(n);
          else
            this.moveRight(n);

          break;
      }
    }

    return answer;
  }
}