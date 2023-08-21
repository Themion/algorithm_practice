package programmers;

import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.stream.IntStream;

class Solution {
  public int[] solution(String[] id_list, String[] report, int k) {
    int[] answer = IntStream.range(0, id_list.length).toArray();
    Arrays.fill(answer, 0);

    Map<String, Integer> idMap = new HashMap<>();
    Map<Integer, Set<Integer>> reportMap = new HashMap<>();

    for (int i = 0; i < id_list.length; i++)
      idMap.put(id_list[i], i);

    for (String r : report) {
      String[] reportInfo = r.split(" ");
      Integer reporter = idMap.get(reportInfo[0]);
      Integer reportee = idMap.get(reportInfo[1]);

      if (reportMap.get(reportee) == null)
        reportMap.put(reportee, new HashSet<>());

      reportMap.get(reportee).add(reporter);
    }

    reportMap.values().stream().forEach((reportSet) -> {
      if (reportSet.size() < k)
        return;
      reportSet.stream().forEach((reporter) -> answer[reporter] += 1);
    });

    return answer;
  }
}