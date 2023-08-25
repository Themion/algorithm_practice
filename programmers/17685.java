class Trie {
  static int MAX_LEN = 1000000;
  static int EOW = 26;
  Integer[][] trie = new Integer[Trie.MAX_LEN][];
  int len = 0;

  Trie() {
    for (int i = 0; i < Trie.MAX_LEN; i++)
      trie[i] = new Integer[Trie.EOW + 1];
  }

  private int cToIdx(char c) {
    return c - 'a';
  }

  private void visit(int idx) {
    trie[idx][Trie.EOW] = (trie[idx][Trie.EOW] == null) ? 1 : trie[idx][Trie.EOW] + 1;
  }

  void push(String word) {
    char[] arr = word.toCharArray();
    Integer idx = 0;

    for (int i = 0; i < arr.length; i++) {
      int cIdx = cToIdx(arr[i]);
      if (trie[idx][cIdx] == null)
        trie[idx][cIdx] = ++len;

      visit(idx);
      idx = trie[idx][cIdx];
    }
    visit(idx);
  }

  int getMinWordLen(String word) {
    char[] arr = word.toCharArray();
    Integer idx = 0, ret = 0;

    for (; ret < arr.length; ret++) {
      if (trie[idx][Trie.EOW] == null || trie[idx][Trie.EOW] <= 1)
        break;
      int cIdx = cToIdx(arr[ret]);
      idx = trie[idx][cIdx];
    }

    return ret;
  }
}

class Solution {
  public int solution(String[] words) {
    int answer = 0;
    Trie trie = new Trie();

    for (String word : words)
      trie.push(word);
    for (String word : words)
      answer += trie.getMinWordLen(word);

    return answer;
  }
}
