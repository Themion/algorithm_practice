function solution(s) {
    const count = "abcdefghijklmnopqrstuvwxyz"
        .split("")
        .reduce((acc, char) => ({ ...acc, [char]: -1 }), {});
    [];

    return s.split("").map((char, idx) => {
        const ret = count[char] === -1 ? -1 : idx - count[char];
        count[char] = idx;
        return ret;
    });
}
