const fs = require("fs");

const inputData = fs
    .readFileSync("../input.txt")
    // 백준 서버
    // .readFileSync("/dev/stdin")
    .toString()
    .replace("\n", "")
    .split(" ");

// const inputData = [
//     "1234",
//     "234092",
//     "999909",
//     "82340329923",
//     "32098221",
//     "1111111",
//     "00000000000000000000000000000000000000000000000000000000000000000000000",
//     "345029834023049820394802334909240982039842039483294792934790209",
// ];

function main(input) {
    let N = 1,
        stack = [...N.toString()];

    [...input].forEach((digit) => {
        let flag = false;

        while (!flag) {
            if (stack.length == 0) {
                do {
                    N = (parseInt(N) + 1).toString();
                } while (![...N].includes(digit));
                stack = [...N].reverse();
            }

            flag = stack.pop() === digit;
        }
    });

    console.log(N);
}

main(inputData);
