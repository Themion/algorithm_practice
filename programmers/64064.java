package programmers;

import java.util.*;

class Solution {
  int[] infoArr;
  Set<Integer> set = new HashSet<>();

  public void backtrack(String[] user_id, int infoIdx, int selected) {
    if (infoIdx == infoArr.length) {
      set.add(selected);
      return;
    }

    for (int i = 0; i < user_id.length; i++) {
      boolean isMatch = (infoArr[infoIdx] & (1 << i)) != 0;
      boolean isNotSelected = (selected & (1 << i)) == 0;

      if (user_id[i] != null && isMatch && isNotSelected) {
        String temp = user_id[i];

        user_id[i] = null;
        selected |= 1 << i;

        backtrack(user_id, infoIdx + 1, selected);

        selected &= ~(1 << i);
        user_id[i] = temp;
      }
    }
  }

  public int solution(String[] user_id, String[] banned_id) {
    infoArr = new int[banned_id.length];

    for (int i = 0; i < banned_id.length; i++) {
      String regex = banned_id[i].replaceAll("[*]", ".");

      infoArr[i] = 0;
      for (int j = 0; j < user_id.length; j++)
        if (user_id[j].length() == regex.length() && user_id[j].matches(regex))
          infoArr[i] |= (1 << j);
    }

    backtrack(user_id, 0, 0);

    return set.size();
  }
}
