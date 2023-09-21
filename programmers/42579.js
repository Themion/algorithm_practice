function solution(genres, plays) {
  const map = new Map();
  genres.forEach((genre, i) => {
    const count = map.has(genre) ? map.get(genre) : 0;
    map.set(genre, count + plays[i]);
  });
  const arr = plays
    .map((_, i) => i)
    .map((i) => ({ genre: genres[i], play: plays[i], idx: i }))
    .sort((a, b) => {
      if (a.genre !== b.genre) return map.get(b.genre) - map.get(a.genre);
      if (a.play !== b.play) return b.play - a.play;
      return a.idx - b.idx;
    })
    .map(({ genre, idx }) => ({ genre, idx }));

  const selected = new Map();
  return arr
    .filter(({ genre }) => {
      const count = selected.has(genre) ? selected.get(genre) : 0;
      if (count >= 2) return false;

      selected.set(genre, count + 1);
      return true;
    })
    .map(({ idx }) => idx);
}
