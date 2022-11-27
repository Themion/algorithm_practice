/*
 * 마켓 통합 추천 종목 목록을 반환하도록 함수를 작성해주세요.
 * (반환 타입: Promise<string[]>)
 */
async function solution(fetchMarkets, fetchStocks) {
    const markets = await fetchMarkets();
    const stockArr = await Promise.all(markets.map(fetchStocks));
    const answer = stockArr.reduce((prev, curr) => prev.concat(curr), []);
    return answer;
}
