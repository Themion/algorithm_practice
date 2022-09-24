const validateTree = (tree) => {
    const len = tree.length

    if (len === 1) return true

    const root = Math.floor(len / 2)

    if (tree[root] === '0') return false

    return validateTree(tree.substr(0, root)) && validateTree(tree.substr(root + 1))
}

const testTree = (number) => {
    let tree = ''
    let lenEstimate = 1
    while (number > 0) {
        tree += (number % 2)
        number = Math.floor(number / 2)
        if (tree.length > lenEstimate) lenEstimate = 2 * (lenEstimate + 1) - 1
    }

    return new Array(lenEstimate - tree.length + 1).fill(0).map((_, i) => {
        tree = ''.padStart(i, '0') + tree
        return validateTree(tree.padEnd(lenEstimate, '0'))
    }).reduce((prev, val) => prev + val, 0)
}

function solution(numbers) {
    return numbers.map(testTree);
}

console.log(solution([7, 5, 63, 111, 95]))