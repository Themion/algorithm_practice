package programmers;

import java.util.ArrayList;
import java.util.List;

class Solution {
  public int[] solution(int[] num_list) {
    List<Integer> list = new ArrayList<>();
    for (Integer num : num_list)
      list.add(num);
    if (num_list[num_list.length - 1] > num_list[num_list.length - 2])
      list.add(num_list[num_list.length - 1] - num_list[num_list.length - 2]);
    else
      list.add(num_list[num_list.length - 1] * 2);

    return list.stream().mapToInt(i -> i).toArray();
  }
}
