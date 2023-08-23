package programmers;

class Heap {
  public int[] heap = new int[1000000];
  public int length = 0;
  public boolean isMinHeap = true;

  Heap() {
  }

  void orderUp(int index) {
    if (index == 0)
      return;
    if (heap[index] < heap[index / 2] == isMinHeap) {
      int temp = heap[index];
      heap[index] = heap[index / 2];
      heap[index / 2] = temp;

      orderUp(index / 2);
    }
  }

  void orderDown(int index) {
    int nextIndex = heap[index * 2 + 1] < heap[index * 2 + 2] == isMinHeap ? index * 2 + 1 : index * 2 + 2;
    if (index * 2 + 2 >= length)
      nextIndex = index * 2 + 1;
    if (nextIndex >= length)
      return;

    if (heap[nextIndex] < heap[index] == isMinHeap) {
      int temp = heap[index];
      heap[index] = heap[nextIndex];
      heap[nextIndex] = temp;

      orderDown(nextIndex);
    }
  }

  void setIsMinHeap(boolean b) {
    isMinHeap = b;
    for (int i = 1; i < length; i++)
      orderUp(i);
  }

  int add(int i) {
    heap[length++] = i;
    orderUp(length - 1);
    return i;
  }

  int pop() {
    if (length <= 0)
      return 0;
    int ret = heap[0];
    heap[0] = heap[--length];
    orderDown(0);
    return ret;
  }
}

class Solution {
  public int[] solution(String[] operations) {
    int[] answer = new int[2];
    Heap heap = new Heap();

    for (String str : operations) {
      String[] command = str.split(" ");
      if (command[0].equals("I"))
        heap.add(Integer.parseInt(command[1]));
      else {
        boolean isMinHeap = command[1].equals("-1");
        heap.setIsMinHeap(isMinHeap);
        heap.pop();
      }
    }

    heap.setIsMinHeap(false);
    answer[0] = heap.pop();
    heap.setIsMinHeap(true);
    answer[1] = heap.pop();

    return answer;
  }
}
