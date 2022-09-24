function solution(wall) {
    const yLen = wall.length
    const xLen = wall[0].length

    const answer = new Array(yLen).fill(0).map(() => {
        return new Array(xLen).fill(0).map(() => 0)
    });

    const visit = (y, x, hold) => {
        if (wall[y][x] !== 'H') return;
        if (answer[y][x] === -1) answer[y][x] = yLen * xLen
        if (answer[y][x] <= hold) return
        answer[y][x] = ++hold;

        if (y - 1 >= 0) {
            visit(y - 1, x, hold)
            if (y - 2 >= 0 && wall[y - 1][x] === '.')
                visit(y - 2, x, hold)
        }
        if (y + 1 < yLen) 
            visit(y + 1, x, hold)
        if (x - 1 >= 0) {
            visit(y, x - 1, hold)
            if (y - 1 >= 0) visit(y - 1, x - 1, hold)
        }
        if (x + 1 < xLen) {
            visit(y, x + 1, hold)
            if (y - 1 >= 0) visit(y - 1, x + 1, hold)
        }

        if (y - 1 >= 0 && answer[y - 1][x] === '.') {
            for (let d = 1; d <= 3; d++) {
                if (x - d < 0 || wall[y - 1][x - d] === 'X') break;
                visit(y - 1, x - d, hold)
                if (wall[y - 1][x - d] === 'H') break;
            }
            for (let d = 1; d <= 3; d++) {
                if (x + d > xLen || wall[y - 1][x + d] === 'X') break;
                visit(y - 1, x + d, hold)
                if (wall[y - 1][x + d] === 'H') break;
            }
        }
    }

    wall.forEach((line, yIdx) => {
        [...line].forEach((c, xIdx) => {
            if (c === 'H') answer[yIdx][xIdx] = -1
        })
    })

    const bottom = [...wall.at(-1)]

    bottom.forEach((_, xIdx) => {
        visit(yLen - 1, xIdx, 0)
    })

    return answer
}

solution(["H.H", ".HX", "H.H"]).forEach(arr =>console.log(arr))
