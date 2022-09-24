function solution(cap, n, deliveries, pickups) {
    const houses = new Array(n).fill(0).map((_, i) => ({ 
        d: deliveries[i], 
        p: pickups[i],
        i: i + 1
    }))
    let d = 0, p = 0, answer = 0, start = 0

    while (houses.at(-1).d === 0 && houses.at(-1).p === 0)
        houses.pop()

    houses.reverse().forEach((house, idx, houses) => {
        if (d + house.d <= cap && p + house.p <= cap) {
            d += house.d
            p += house.p
        }
        else {
            if ((d + house.d) > cap) d = (d + house.d) % cap
            else d = 0
            if ((p + house.p) > cap) p = (p + house.p) % cap
            else p = 0

            answer += start
            start = house.i
        }
    })

    return (answer + start) * 2
}

console.log(solution(4, 5, [1, 0, 3, 1, 2], [0, 3, 0, 4, 0]))
console.log(solution(2, 7, [1, 0, 2, 0, 1, 0, 2], [0, 2, 0, 1, 0, 2, 0]))
