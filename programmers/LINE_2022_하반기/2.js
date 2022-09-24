function solution(k, dic, chat) {
    let answer = chat.split(' ').map(word => {
        const flag = dic.reduce((prev, filterWord) => {
            const dotCount = [...word].filter(c => c === '.').length
            const wLenMin = word.length
            const wLenMax = wLenMin + (k - 1) * dotCount

            if (wLenMin > filterWord.length || filterWord.length > wLenMax) return prev

            const wordToArr = [...word].filter(c => c !== '.').reverse();
            [...filterWord].forEach(c => {
                if (c === wordToArr.at(-1)) wordToArr.pop()
            })

            return prev || wordToArr.length === 0
        }, false)

        return flag? ''.padStart(word.length, '#') : word
    })

    return answer.join(' ');
}
