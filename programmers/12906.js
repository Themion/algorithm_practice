function solution(arr) {
  return arr.filter((_, i, array) => i === 0 || array[i] !== array[i - 1]);
}
