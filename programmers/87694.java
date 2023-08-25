package programmers;

class Solution {
  boolean[][] map = new boolean[103][103];

  public int getDir(int x, int y) {
    boolean tl = map[x - 1][y + 1],
        tr = map[x + 1][y + 1],
        bl = map[x - 1][y - 1],
        br = map[x + 1][y - 1];

    int dir = 0;
    if (tl)
      dir += 1 << 3;
    if (tr)
      dir += 1 << 2;
    if (bl)
      dir += 1 << 1;
    if (br)
      dir += 1 << 0;

    return dir;
  }

  public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
    int[] answer = new int[2];
    int flag = 0;
    answer[0] = answer[1] = 0;

    for (int i = 0; i <= 100; i++)
      for (int j = 0; j <= 100; j++)
        map[i][j] = false;

    for (int[] r : rectangle) {
      int a = r[0] * 2, b = r[1] * 2, c = r[2] * 2, d = r[3] * 2;
      for (int i = a; i <= c; i++)
        for (int j = b; j <= d; j++)
          map[i][j] = true;
    }

    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;

    int x = characterX, y = characterY;

    do {
      int dir = getDir(x, y);
      answer[flag] += 1;

      switch (dir) {
        // UP
        case 0b0100:
        case 0b0101:
        case 0b0111:
          y += 2;
          break;
        // RIGHT
        case 0b0001:
        case 0b0011:
        case 0b1011:
          x += 2;
          break;
        // DOWN
        case 0b0010:
        case 0b1010:
        case 0b1110:
          y -= 2;
          break;
        // LEFT
        case 0b1000:
        case 0b1100:
        case 0b1101:
          x -= 2;
          break;
        default:
          return -1;
      }

      if (x == itemX && y == itemY)
        flag++;
    } while (x != characterX || y != characterY);

    return Math.min(answer[0], answer[1]);
  }
}