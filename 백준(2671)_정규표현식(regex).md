# [백준(2671)_정규표현식(regex)](https://www.acmicpc.net/problem/2671)

---

```javascript
const fs = require('fs');
const stdin = (process.platform === 'linux'
    ? fs.readFileSync('/dev/stdin').toString()
    : `10011001`
).split('\n');

const input = (() => {
    let line = 0;
    return () => stdin[line++];
})();

const submarine = input()
const re = /\b(100+1+|01)+\b/g

let tmp = submarine.match(re) || []
tmp[0] === submarine ? console.log('SUBMARINE') : console.log('NOISE')
```

정규표현식을 이미 문제에서 줘버려서 어렵지는 않았다. 하지만, 처음에 틀렸는데 \b 경계를 나타내는 이 코드를 쓰지 않아서 였다.(물론 ^ $ 앵커플래그로도 가능하다. ) 저번부터 이렇게 경계를 나타내지 않으면 틀리는 경우가 종종 발생하는 것 같다. 졍규표현 패턴이 문자열 전체와 일치하는 경우에는 반드시 경계 표시를 남겨야 한다는 것을 잊으면 안되겠다.