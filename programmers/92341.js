function solution(fees, records) {
  const [basicTime, basicFee, perTime, perFee] = fees;
  const times = {};

  records.forEach((record) => {
    const [clock, number, inOut] = record.split(" ");
    const [hr, min] = clock.split(":").map((item) => parseInt(item));
    const time = hr * 60 + min;
    if (times[number] === undefined) times[number] = [];

    times[number].push(time);
  });

  return Object.keys(times)
    .sort()
    .map((key) => {
      let fee = 0;
      let enterTime = 0;
      let sumTime = 0;

      if (times[key].length % 2 === 1) times[key].push(23 * 60 + 59);

      times[key].forEach((time, idx) => {
        if (idx % 2 === 0) {
          enterTime = time;
        } else {
          sumTime += time - enterTime;
        }
      });

      if (sumTime > basicTime)
        fee += Math.ceil((sumTime - basicTime) / perTime) * perFee;

      return fee + basicFee;
    });
}
