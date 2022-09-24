function solution(n, m, fires, ices) {
    const answer = new Array(n).fill(0).map(() => {
        return new Array(n).fill(0).map(() => 0)
    });

    const outOfRange = (p) => p < 0 || p >= n

    fires.forEach(([fireY, fireX]) => {
        fireY -= 1
        fireX -= 1

        for (let yd = -m; yd <= m; yd++) {
            if (outOfRange(fireY + yd)) continue;
    
            for (let xd = -m; xd <= m; xd++) {
                if (outOfRange(fireX + xd)) continue;

                const point = m + 1 - Math.max(Math.abs(yd), Math.abs(xd), 1)
                
                answer[fireY + yd][fireX + xd] += point
            }
        }
    })

    ices.forEach(([iceY, iceX]) => {
        iceY -= 1
        iceX -= 1

        for (let yd = -m; yd <= m; yd++) {
            if (outOfRange(iceY + yd)) continue;

            const diff = m - Math.abs(yd)
    
            for (let xd = -diff; xd <= diff; xd++) {
                if (outOfRange(iceX + xd)) continue;

                let point = m - Math.abs(yd) - Math.abs(xd)
                if (yd !== 0 || xd !== 0) point += 1
                
                answer[iceY + yd][iceX + xd] -= point
            }
        }
    })

    return answer;
}

console.log(solution(3, 2, [[1, 1]], [[3, 3]]))