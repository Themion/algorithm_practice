function solution(citations) {
  let h = 0;
  const arr = citations.map((c) => parseInt(c)).sort((a, b) => b - a);
  while (h < arr.length && arr[h] >= h + 1) h += 1;
  return h;
}
