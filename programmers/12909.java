package programmers;

class Solution {
  boolean solution(String s) {
    Integer count = 0;
    char[] arr = s.toCharArray();

    for (Character c : arr) {
      if (c.equals('('))
        count += 1;
      else {
        count -= 1;
        if (count < 0)
          break;
      }
    }

    return count == 0;
  }
}
