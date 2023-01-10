const fs = require("fs");

const inputData = fs
    .readFileSync("../input.txt")
    // 백준 서버
    // .readFileSync("/dev/stdin")
    .toString()
    .split("\n")
    .map((str) => str.split(/[+=]/g).filter((s) => s != ""))
    .filter((list) => list.length >= 2);

// 세그먼트로 나타낼 숫자 -> 10진법 세그먼트 코드
const digitToCode = [
    "063",
    "010",
    "093",
    "079",
    "106",
    "103",
    "119",
    "011",
    "127",
    "107",
];

// 10진법 세그먼트 코드 -> 세그먼트로 나타낼 숫자
const codeToDigit = digitToCode.reduce(
    (acc, curr, idx) => ({ ...acc, [curr]: idx.toString() }),
    {}
);

// 일렬로 나열된 10진법 코드를 세그먼트 숫자로 변환
const strToNumber = (str) => {
    const num = [...str]
        .reduce((acc, curr, idx) => {
            if (idx % 3 === 0) return [...acc, [curr]];
            else {
                acc.at(-1).push(curr);
                return acc;
            }
        }, [])
        .map((s) => codeToDigit[s.join("")])
        .join("");

    return parseInt(num);
};

// 일렬로 나열된 세그먼트 숫자를 10진법 코드로 변환
const numberToStr = (num) => {
    str = num.toString();
    return [...str].map((digit) => digitToCode[digit]).join("");
};

inputData.forEach((data) => {
    const sum = strToNumber(data[0]) + strToNumber(data[1]);
    console.log(`${data[0]}+${data[1]}=${numberToStr(sum)}`);
});
