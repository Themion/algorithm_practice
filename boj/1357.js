const fs = require("fs");

const inputData = fs
    .readFileSync("../input.txt")
    // 백준 서버
    // .readFileSync("/dev/stdin")
    .toString()
    .replace("\n", "")
    .split(" ");

const Rev = (num) => parseInt([...num.toString()].reverse().join(""));

const Y = Rev(inputData.pop());
const X = Rev(inputData.pop());
console.log(Rev(X + Y));
