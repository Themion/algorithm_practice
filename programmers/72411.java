package programmers;

import java.util.*;

class Solution {
  Map<String, Integer> menuMap = new HashMap<>();
  String[] orders;
  int[] course;

  public void setMenu(String menu, String order, int index) {
    for (int c : course)
      if (menu.length() == c) {
        Integer count = menuMap.get(menu);
        if (count == null)
          count = 0;
        menuMap.put(menu, count + 1);
      }

    for (int i = index; i < order.length(); i++)
      setMenu(menu + order.charAt(i), order, i + 1);
  }

  public String[] solution(String[] orders, int[] course) {
    List<String> answer = new ArrayList<>();
    Map<Integer, Integer> maxCalledCount = new HashMap<>();

    this.orders = orders;
    this.course = course;

    for (String order : orders) {
      char[] arr = order.toCharArray();
      Arrays.sort(arr);
      order = new String(arr);
      setMenu("", order, 0);
    }

    menuMap.keySet().stream().forEach(menu -> {
      int len = menu.length();
      Integer maxCalled = maxCalledCount.get(len);
      Integer called = menuMap.get(menu);
      if (maxCalled == null || maxCalled < called)
        maxCalledCount.put(len, called);
    });

    menuMap.keySet().stream().forEach(menu -> {
      int len = menu.length();
      Integer maxCalled = maxCalledCount.get(len);
      Integer called = menuMap.get(menu);

      if (maxCalled == called && called > 1)
        answer.add(menu);
    });

    String[] ret = answer.toArray(new String[0]);
    Arrays.sort(ret);
    return ret;
  }
}
