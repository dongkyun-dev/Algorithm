# [백준(2407)_dp, BigInt](https://www.acmicpc.net/problem/2407)

---

```javascript
const fs = require('fs');
const stdin = (process.platform === 'linux'
    ? fs.readFileSync('/dev/stdin').toString()
    : `100 50`
).split('\n');

const input = (() => {
    let line = 0;
    return () => stdin[line++];
})();

const [N, M] = input().split(' ').map((e) => parseInt(e))
let dp = Array.from(Array(N + 1), () => new Array(N + 1).fill(0))


for (let i = 0; i < N + 1; i++) {
    for (let j = 0; j < i + 1; j++) {
        if (i === 0 || j === 0) {
            dp[i][j] = BigInt(1)
        }
        else if (j === i) {
            dp[i][j] = BigInt(1)
        }
        else {
            dp[i][j] = BigInt(dp[i - 1][j - 1] + dp[i - 1][j])
        }
    }
}
for (let i = 0; i < N + 1; i++) {
    for (let j = 0; j < N + 1; j++) {
        dp[i][j] = BigInt(dp[i][j])
    }
}
if (dp[N][M] === undefined) {
    console.log(0)
}
else {

    const n = dp[N][M]
    const _n = ("" + n).replace(/[^0-9]/g, "")
    console.log(_n)
}
// dp[N][M] >= 0 ? console.log(dp[N][M].replace(/n/g, "")) : console.log(0)
```

좀만 쉬고와서 정리할 예쩡