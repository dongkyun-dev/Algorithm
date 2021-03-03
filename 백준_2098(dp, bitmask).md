```java
const fs = require('fs');
const stdin = (process.platform === 'linux'
    ? fs.readFileSync('/dev/stdin').toString()
    : `4
0 10 15 20
5 0 9 10
6 13 0 12
8 8 9 0`
).split('\n');

const input = (() => {
    let line = 0;
    return () => stdin[line++];
})();

const MAX = 16

const TSP = ((here, visited) => {
    if (visited == (1 << N) - 1) {
        if (W[here][0]) {
            return W[here][0]
        }
        return Infinity
    }
    let result = cache[here][visited]
    if (result !== -1) {
        return result
    }
    result = Infinity
    for (let next = 0; next < N; next++) {
        if (visited & (1 << next) || W[here][next] == 0)
            continue
        candidate = W[here][next] + TSP(next, visited + (1 << next))
        result = Math.min(result, candidate)
        cache[here][visited] = result
    }
    return result
})

const N = parseInt(input())
let cache = Array.from(Array(N), () => Array(1 << N).fill(-1))
let W = new Array(N)
for (let i = 0; i < N; i++) {
    let tmp = input().split(' ').map((A) => parseInt(A))
    let tmp2 = [...tmp]
    W[i] = tmp2
}
// console.log(W)
console.log(TSP(0, 1))

```

이번 주 중으로 자세한 설명을 추가하겠습니다.