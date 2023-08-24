package programmers;

class Solution {
  public String solution(String new_id) {
    new_id = new_id.toLowerCase();

    new_id = new_id.replaceAll("[^0-9a-z_.-]", "");
    new_id = new_id.replaceAll("[.]{2,}", ".");
    new_id = new_id.replaceAll("^[.]", "");
    new_id = new_id.replaceAll("[.]$", "");
    if (new_id.equals(""))
      new_id = "a";
    if (new_id.length() >= 16)
      new_id = new_id.substring(0, 15);
    new_id = new_id.replaceAll("^[.]", "");
    new_id = new_id.replaceAll("[.]$", "");

    int len = new_id.length();

    while (new_id.length() <= 2)
      new_id += new_id.charAt(len - 1);

    return new_id;
  }
}