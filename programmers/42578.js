function solution(clothes) {
  const map = new Map();

  clothes.forEach(([name, type]) => {
    const set = map.has(type) ? map.get(type) : new Set();
    set.add(name);
    map.set(type, set);
  });

  return [...map.values()].reduce((acc, curr) => acc * (curr.size + 1), 1) - 1;
}
