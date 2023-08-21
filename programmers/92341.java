package programmers;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
  private Integer parseTime(String time) {
    String[] arr = time.split(":");
    String hr = arr[0];
    String min = arr[1];

    return Integer.parseInt(hr) * 60 + Integer.parseInt(min);
  }

  public int[] solution(int[] fees, String[] records) {
    Integer basicTime = fees[0], basicFee = fees[1], deltaTime = fees[2], deltaFee = fees[3];

    Map<String, Integer> timePerPlate = new HashMap<>();
    Map<String, Integer> totalTimePerPlate = new HashMap<>();

    for (String record : records) {
      String[] recordArr = record.split(" ");
      Integer time = this.parseTime(recordArr[0]);
      String plate = recordArr[1];
      Boolean isIn = recordArr[2].equals("IN");

      if (isIn)
        timePerPlate.put(plate, time);

      else {
        Integer totalTime = totalTimePerPlate.getOrDefault(plate, 0);
        Integer prevTime = timePerPlate.get(plate);
        timePerPlate.remove(plate);
        totalTimePerPlate.put(plate, totalTime + time - prevTime);
      }
    }

    timePerPlate.entrySet().stream().forEach((entry) -> {
      String plate = entry.getKey();
      Integer prevTime = entry.getValue();

      Integer totalTime = totalTimePerPlate.getOrDefault(plate, 0);
      totalTimePerPlate.put(plate, totalTime + (23 * 60 + 59) - prevTime);
    });

    return Arrays.stream(totalTimePerPlate.keySet().toArray()).sorted()
        .mapToInt((key) -> (int) totalTimePerPlate.getOrDefault(key, 0)).map((time) -> {
          if (time < basicTime)
            return basicFee;
          else
            return basicFee + (int) Math.ceil((time - basicTime) / (double) deltaTime) * deltaFee;
        }).toArray();
  }
}