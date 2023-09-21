function solution(numbers) {
  const str = numbers
    .map((num) => num.toString())
    .sort((a, b) => parseInt(a + b) - parseInt(b + a))
    .reverse()
    .join("");
  const digitArr = [...str].reverse();
  while (digitArr.at(-1) === "0") digitArr.pop();
  return digitArr.length > 0 ? digitArr.reverse().join("") : "0";
}
