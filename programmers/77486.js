function solution(enroll, referral, seller, amount) {
  const nameToIdx = new Map();
  const answer = enroll.map(() => 0);

  const shareWithParent = (childName, value) => {
    const childIdx = nameToIdx.get(childName);

    if (childIdx < 0) return;

    const share = Math.floor(value / 10);
    const parentName = referral[childIdx];
    answer[childIdx] += value - share;

    if (share > 0) shareWithParent(parentName, share);
  };

  nameToIdx.set("-", -1);

  enroll.forEach((name, idx) => nameToIdx.set(name, idx));
  seller.forEach((name, idx) => shareWithParent(name, amount[idx] * 100));

  return answer;
}
