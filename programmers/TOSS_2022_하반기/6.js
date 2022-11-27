function solution(html) {
    const tags = html.split("<").map((tag) => tag.split(">")[0]);
    tags.shift();

    const stack = [];
    return (
        tags.reduce((prev, curr) => {
            if (curr.at(-1) === "/") return prev;
            else if (curr[0] !== "/") stack.push(curr);
            else if (curr.substr(1) !== stack.at(-1)) return false;
            else stack.pop();

            return prev;
        }, tags.length > 0) && stack.length == 0
    );
}

console.log(solution("<img />"));
console.log(solution("asdaf<asdaf"));
