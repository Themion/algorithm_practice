function solution(participant, completion) {
  const map = new Map();

  participant.forEach((name) => {
    const val = map.get(name);
    map.set(name, val !== undefined ? val + 1 : 1);
  });

  completion.forEach((name) => {
    const val = map.get(name);
    map.set(name, val - 1);
  });

  return participant.filter((name) => map.get(name) > 0)[0];
}
