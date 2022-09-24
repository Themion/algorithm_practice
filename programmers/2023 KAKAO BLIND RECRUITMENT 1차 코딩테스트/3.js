class Result {
    purchased = 0
    plus = 0

    constructor(users, discounted) {
        users.forEach(([uRate, uPrice]) => {
            const priceSum = discounted
                .filter(({ eRate }) => uRate <= eRate)
                .reduce((prev, { ePrice }) => prev + ePrice, 0)

            if (priceSum < uPrice) this.purchased += priceSum
            else this.plus++
        })
    }

    isBetter(result) {
        if (this.plus === result.plus) return this.purchased > result.purchased
        return this.plus > result.plus
    }
}

const discountEmoticon = (users, emoticons, discounted) => {
    if (emoticons.length === discounted.length) return new Result(users, discounted)
    else {
        const results = [10, 20, 30, 40].map(rate => {
            const len = discounted.length
            return discountEmoticon(users, emoticons, discounted.concat({
                eRate: rate, 
                ePrice: emoticons[len] * (100 - rate) / 100
            }))
        })

        let ret = results.pop()
        return results.reduce((prev, r) => {
            return prev.isBetter(r) ? prev : r
        }, ret)
    }
}

function solution(users, emoticons) {
    const result = discountEmoticon(users, emoticons, []);
    return [result.plus, result.purchased]
}

console.log(solution([[40, 10000], [25, 10000]], [7000, 9000]))