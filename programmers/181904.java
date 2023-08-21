package programmers;

class Solution {
  public String solution(String my_string, int m, int c) {
    String answer = "";
    for (int i = c - 1; i < my_string.length(); i += m)
      answer += my_string.charAt(i);
    return answer;
    // import java.util.stream.*
    // return IntStream.range(0, myString.length())
    // .filter(i -> i % m == c - 1)
    // .mapToObj(i -> String.valueOf(myString.charAt(i)))
    // .collect(Collectors.joining());
  }
}