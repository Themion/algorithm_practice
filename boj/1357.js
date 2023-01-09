const fs = require("fs");

const inputData = fs
    .readFileSync("../input.txt")
    // 백준 서버
    // .readFileSync("/dev/stdin")
    .toString()
    .replace("\n", "")
    .split(" ");

// 수를 뒤집는 함수
const Rev = (num) => parseInt([...num.toString()].reverse().join(""));

// 입력을 뒤집은 뒤 더해 다시 뒤집어 출력
const Y = Rev(inputData.pop());
const X = Rev(inputData.pop());
console.log(Rev(X + Y));
