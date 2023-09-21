function solution(nums) {
  const size = nums.length;
  const set = new Set(nums);
  return Math.min(set.size, size / 2);
}
