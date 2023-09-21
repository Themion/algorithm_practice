function solution(progresses, speeds) {
  const answer = [];

  progresses = progresses.reverse();
  speeds = speeds.reverse();

  while (progresses.length > 0) {
    speeds.forEach((speed, i) => {
      if (progresses[i] >= 100) return false;
      progresses[i] += speed;
    });
    let done = 0;
    while (progresses.at(-1) >= 100) {
      done += 1;
      progresses.pop();
      speeds.pop();
    }
    if (done > 0) answer.push(done);
  }

  return answer;
}
