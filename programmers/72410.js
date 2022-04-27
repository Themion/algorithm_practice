function solution(new_id) {
    var answer = '';

    let step1 = new_id.toLowerCase()

    const regexp = /\w|\d/
    let step2 = []
    Array.from(step1).forEach(c => {
        if (regexp.test(c) || c == '-' || c == '_' || c == '.')
            step2.push(c)
    })

    let step3 = []
    step2.forEach(c => {
        const len = step3.length
        if (len == 0 || !(c == '.' && step3[len - 1] == '.')) step3.push(c)
    })

    let step4 = []
    for (let i = 0; i < step3.length; i++) {
        if ((i == 0 || i == step3.length - 1) && step3[i] == '.') continue;
        else step4.push(step3[i])
    }

    let step5 = step4.length == 0 ? ['a'] : step4

    let step6 = []
    for (let i = 0; i < step5.length && i < 15; i++) step6.push(step5[i])
    while (step6[step6.length - 1] == '.') step6.pop()

    let step7 = step6
    while (step7.length <= 2) step7.push(step6[step6.length - 1])

    return step7.join('');
}