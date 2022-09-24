const EMPTY = 'EMPTY'

class Cell {
    constructor(r, c) {
        this.coords = [{ r, c }]
        this.value = EMPTY
    }

    static mergedCell(cell1, cell2) {
        const ret = new Cell()
        ret.coords = cell1.coords.concat(cell2.coords)
        ret.value = (cell1.value === EMPTY) ? cell2.value : cell1.value

        return ret
    }
}

class Table {
    constructor() {
        this.table = new Array(51).fill(0).map((_ ,r) => 
            new Array(51).fill(0).map((_, c) => new Cell(r, c))
        )
    }

    update(r, c, value) {
        this.table[r][c].value = value
    }

    updateAll(from_, to_) {
        this.table.forEach(row => row.forEach(cell => {
            if (cell.value === from_) cell.value = to_
        }))
    }

    merge(r1, c1, r2, c2) {
        r1 = parseInt(r1)
        c1 = parseInt(c1)
        r2 = parseInt(r2)
        c2 = parseInt(c2)

        const mergedCell = Cell.mergedCell(this.table[r1][c1], this.table[r2][c2])
        const { coords } = mergedCell

        coords.forEach(({r, c}) => this.table[r][c] = mergedCell)
    }

    unmerge(r_, c_) {
        r_ = parseInt(r_)
        c_ = parseInt(c_)

        const { coords, value } = this.table[r_][c_]
        coords.forEach(({r, c}) => {
            this.table[r][c] = new Cell(r, c)
        })

        this.table[r_][c_].value = value
    }

    get(r, c) {
        r = parseInt(r)
        c = parseInt(c)

        return this.table[r][c].value
    }
}

function solution(commands) {
    const answer = [];
    const updateRegExp = /^UPDATE /
    const mergeRegExp = /^MERGE /
    const unmergeRegExp = /^UNMERGE /
    const printRegExp = /^PRINT /

    const table = new Table()

    commands.forEach(command => {
        const [_, arg1, arg2, arg3, arg4] = command.split(' ')
        switch (true) {
            case (updateRegExp.test(command)):
                if (arg3 === undefined) table.updateAll(arg1, arg2)
                else table.update(arg1, arg2, arg3)
                break
            case (mergeRegExp.test(command)):
                table.merge(arg1, arg2, arg3, arg4)
                break
            case (unmergeRegExp.test(command)):
                table.unmerge(arg1, arg2)
                break
            case (printRegExp.test(command)):
                answer.push(table.get(arg1, arg2))
                break
        }
    })

    return answer;
}
