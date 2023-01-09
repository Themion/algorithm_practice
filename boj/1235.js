const fs = require("fs");

const inputData = fs
    .readFileSync("../input.txt")
    // 백준 서버
    // .readFileSync("/dev/stdin")
    .toString()
    .split("\n")
    .filter((str) => str !== "")
    .reverse();

inputData.pop();

const validate = (count) => {
    const set = new Set();
    let ret = true;
    inputData.forEach((str) => {
        const key = str.substring(str.length - count, str.length);
        if (set.has(key)) ret = false;
        else set.add(key);
    });
    return ret;
};

let i = 1;
while (!validate(i)) i++;
console.log(i);
