# [백준(7579)_dp(knapsack)](https://www.acmicpc.net/problem/7579)

---

```javascript
function solve(N, M, m, c) {
    let dp = Array.from(new Array(101), () => new Array(10001).fill(0))
    let bag = []
    bag.push([0, 0])
    for (let i = 0; i < N; i++) {
        bag.push([m[i], c[i]])
    }
    let result = 987654321
    for (let i = 1; i <= N; i++) {
        for (let j = 0; j <= 10000; j++) {
            dp[i][j] = dp[i - 1][j]
            if (j - bag[i][1] >= 0)
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - bag[i][1]] + bag[i][0])

            if (dp[i][j] >= M)
                result = Math.min(result, j)
        }
    }
    console.log(result)
}

const fs = require('fs');
const stdin = (process.platform === 'linux'
    ? fs.readFileSync('/dev/stdin').toString()
    : `5 60
30 10 20 35 40
3 0 3 5 4`
).split('\n');

const input = (() => {
    let line = 0;
    return () => stdin[line++];
})();

const [N, M] = input().split(' ').map(Number)
const m = input().split(' ').map(Number)
const c = input().split(' ').map(Number)

solve(N, M, m, c)
```

설명은 따로 알고리즘 폴더에 정리해서 올리겠습니다.!! 올리면 밑에 링크 남기겠습니다.