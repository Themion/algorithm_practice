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

// 뒤에서 count 자리만 추려 서로 다른 학생 번호를 만들 수 있는지 계산
const validate = (count) => {
    // 추려낸 학생 번호를 저장할 공간
    const set = new Set();
    // 중복된 학생 번호가 있는지 여부
    let ret = true;

    // 모든 학생 번호에 대해
    inputData.forEach((str) => {
        // 학생 번호의 뒤에서 count 자리만 추린 값을 저장
        const key = str.substring(str.length - count, str.length);
        // 해당 값이 있다면 ret는 false
        if (set.has(key)) ret = false;
        // 그렇지 않다면 해당 학생 번호를 set에 저장
        else set.add(key);
    });
    return ret;
};

// 뒤에서 한 자리부터 차례로 자리수를 늘려가며 테스트
let i = 1;
while (!validate(i)) i++;
console.log(i);
