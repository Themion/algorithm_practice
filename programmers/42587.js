function solution(priorities, location) {
  const prioritySorted = [...priorities].sort((a, b) => a - b);
  let answer = 0,
    len = priorities.length;

  for (let i = 0; priorities[location] !== 0; i = (i + 1) % len) {
    if (priorities[i] !== prioritySorted.at(-1)) continue;

    priorities[i] = 0;
    prioritySorted.pop();
    answer += 1;
  }

  return answer;
}
