function solution(id) {
    const maskingLen = parseInt(id.length / 2);
    const startLen = parseInt(maskingLen / 2);

    const start = id.substr(0, startLen);
    const middle = "".padEnd(maskingLen, "*");
    const end = id.substr(startLen + maskingLen);

    return `${start}${middle}${end}`;
}

const ids = ["hcmsjfb2e5", "k9t0nio7e", "da2ssb3v", "k0r6k9", "7do98"];
ids.forEach((id) => console.log(solution(id)));
