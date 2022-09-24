class DateClass {
    constructor(str, idx) {
        const [year, month, date] = str.split('.')
        this.year = parseInt(year)
        this.month = parseInt(month) - 1
        this.date = parseInt(date)
        this.idx = idx
    }

    addMonth(addMonth) {
        this.month += addMonth
        this.year += parseInt(this.month / 12)
        this.month = parseInt(this.month % 12)
    }

    isBefore(dateClass) {
        if (this.year === dateClass.year) {
            if (this.month === dateClass.month) return this.date <= dateClass.date
            else return this.month < dateClass.month
        }
        else return this.year < dateClass.year
    }
}

function solution(today, terms, privacies) {
    today = new DateClass(today)

    terms = terms.reduce((prev, term) => {
        const [name, month] = term.split(' ')
        return {
            ...prev,
            [name]: parseInt(month)
        }
    }, {})

    const answer = privacies.map((str, idx) => {
        const [date, term] = str.split(' ')
        const dateClass = new DateClass(date, idx + 1)
        dateClass.addMonth(terms[term])
        return dateClass
    }).filter(dateClass => dateClass.isBefore(today)).map(date => date.idx)

    return answer;
}
