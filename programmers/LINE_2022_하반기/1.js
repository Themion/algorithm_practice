class Array {
    len = 1;
    items = 0;

    constructor() { }

    push(newItems) {
        const ret = this.items
        const flag = this.len < (this.items += newItems)

        while (this.len < this.items) this.len <<= 1;

        return flag ? ret : 0;
    }
}

function solution(queries) {
    let answer = 0;
    const map = {}

    queries.forEach(([key, newItems]) => {
        if (map[key] === undefined) map[key] = new Array()
        answer += map[key].push(newItems) 
    })

    return answer;
}
