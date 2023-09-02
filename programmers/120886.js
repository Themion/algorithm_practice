function solution(before, after) {
    const map = new Map();
    [...before].forEach(c => map.set(c, (map.get(c) ?? 0) + 1));
    [...after].forEach(c => map.set(c, (map.get(c) ?? 0) - 1));
    return [...before].reduce((acc, curr) => acc && (map.get(curr) == 0), true) ? 1 : 0;
}
