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
        else if (i === j) {
            dp[i][j] = BigInt(1)
        }
        else {
            dp[i][j] = BigInt(dp[i - 1][j - 1] + dp[i - 1][j])
        }
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
```

$$
nCr = n-1Cr-1 + n-1Cr
$$

중복없이 n개에서 r개를 순서에 상관없이 고르는 것 => 조합

이 수식을 dp 형태로 표현하게 되면

```javascript
for (let i = 0; i < N + 1; i++) {
    for (let j = 0; j < i + 1; j++) {
        if (i === 0 || j === 0) {
            dp[i][j] = BigInt(1)
        }
        else if (i === j) {
            dp[i][j] = BigInt(1)
        }
        else {
            dp[i][j] = BigInt(dp[i - 1][j - 1] + dp[i - 1][j])
        }
    }
}
```

이런 코드가 완성된다.

이 문제에서 까다로웠던 것은 이 dp 점화식을 구하는 것 보다는 Bigint를 사용하는 것이었다.

다행히도 저번에 최대공약수를 구하는 문제에서 같은 스터디 팀원분께서 유용한 팁을 알려주셨고 그 내용을 바탕으로 해결할 수 있었다. 

다만 주의해야 할 부분은 바로 

`const _n = ("" + n).replace(/[^0-9]/g, "")` 이 부분이다.

일단 뒤의 정규표현식은 BigInt로 변환했을 때 맨마지막에 붙게되는 `n`을 제거하기 위함이다.

이 BigInt에 replace 메서드를 사용하기 위해서는 `n`을 문자열로 형변환시켜야 하는데 `toString()`, `JSON.stringify()` 모두 작동하지 않는다. 정확한 이유는 모르겠으나 `("" + n)` 빈 문자열을 더해서 문자열로 변환하는 묵시적 형변환만이 제대로 작동한다. 때문에 이런 변환 방법도 잘 기억해둘 필요가 있다.