package programmers;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Date {
  Integer year, month, day;

  Date() {
  }

  Date(String date) {
    String[] splits = date.split("[.]");

    this.year = Integer.parseInt(splits[0]);
    this.month = Integer.parseInt(splits[1]);
    this.day = Integer.parseInt(splits[2]);
  }

  Integer toInteger() {
    return ((this.year * 12) + this.month) * 28 + this.day;
  }

  void addMonth(Integer month) {
    this.month += month;
    if (this.month > 12) {
      this.year += this.month / 12;
      this.month %= 12;
    }
  }

  Boolean isBiggerThan(Date d) {
    return this.toInteger() > d.toInteger();
  }
}

class Solution {
  public int[] solution(String today, String[] terms, String[] privacies) {
    List<Integer> answer = new ArrayList<>();
    Date todayAsDate = new Date(today);
    Map<String, Integer> termMap = new HashMap<>();

    for (String term : terms) {
      String[] splits = term.split(" ");
      termMap.put(splits[0], Integer.parseInt(splits[1]));
    }

    for (int i = 0; i < privacies.length; i++) {
      String[] splits = privacies[i].split(" ");
      Date termDate = new Date(splits[0]);
      String term = splits[1];

      termDate.addMonth(termMap.getOrDefault(term, 0));

      if (todayAsDate.isBiggerThan(termDate))
        answer.add(i + 1);
    }

    return answer.stream().mapToInt(i -> i).toArray();
  }
}
