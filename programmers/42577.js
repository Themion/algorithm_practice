function solution(phone_book) {
  const set = new Set(phone_book);

  for (let i = 0; i < phone_book.length; i++) {
    const num = phone_book[i];
    const len = num.length;

    let str = num[0];
    for (let j = 1; j < len; j++) {
      if (!set.has(str)) str += num[j];
      else return false;
    }
  }
  return true;
}
