function solution(numbers, target) {
    let answer = new Array(numbers.length + 1).fill(0).map(() => ({}));

    answer[0][0] = 1;

    numbers.forEach((number, idx) => {
        Object.keys(answer[idx]).forEach((key) => {
            const numKey = parseInt(key);
            [numKey + number, numKey - number].forEach((num) => {
                answer[idx + 1][num] =
                    answer[idx][numKey] + (answer[idx + 1][num] ?? 0);
            });
        });
    });

    return answer[numbers.length][target];
}
