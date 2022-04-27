function solution(id_list, report, k) {
    const len = id_list.length
    const map = new Map()
    const rep = new Array(len).fill(0).map(() => new Array(len).fill(false))
    const time = new Array(len).fill(0)
    const answer = new Array(len).fill(0)
    
    let i = 0
    id_list.forEach(id => map.set(id, i++))
    
    report.forEach(log => {
        log = log.split(' ')
        
        const f = map.get(log[0])
        const t = map.get(log[1])
        
        if (!rep[t][f]) {
            time[t]++
            rep[t][f] = true
        }
    })
    
    for (i = 0; i < len; i++) if (time[i] >= k)
        for (let j = 0; j < len; j++) if (rep[i][j]) answer[j]++
    
    return answer
}
