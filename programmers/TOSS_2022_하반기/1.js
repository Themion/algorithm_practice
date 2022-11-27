/*
 * str 인자 타입: string | undefined
 */
let arr = [];

function solution(str) {
    if (str === undefined) {
        const answer = arr.join(" ");
        arr = [];
        return answer;
    } else {
        arr.push(str);
        return solution;
    }
}

console.log(solution("hello")("world")());
console.log(
    solution("가")("나")("다라")("마")("바사")("아자차카")("파")("타")("하")()
);
