const fs = require("fs");

const inputData = fs
    .readFileSync("../input.txt")
    // 백준 서버
    // .readFileSync("/dev/stdin")
    .toString()
    .split("\n")
    .reverse();
const N = parseInt(inputData.pop());
const pattern = inputData.pop().split("*");
const regexp = new RegExp(`^${pattern[0]}\\w*${pattern[1]}$`);

inputData
    .reverse()
    .filter((str) => str !== "")
    .forEach((str) => {
        console.log(regexp.test(str) ? "DA" : "NE");
    });
