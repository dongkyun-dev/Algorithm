# [백준(13904)_greedy](https://www.acmicpc.net/problem/13904)

---

```javascript
const fs = require('fs');
const stdin = (process.platform === 'linux'
    ? fs.readFileSync('/dev/stdin').toString()
    : `7
4 60
4 40
1 20
2 50
3 30
4 10
6 5`
).split('\n');

const input = (() => {
    let line = 0;
    return () => stdin[line++];
})();

const N = parseInt(input())
let homeworks = []
let maxDay = 0
for (let i = 0; i < N; i++) {
    homeworks.push(input().split(' ').map((A) => parseInt(A)))
    if (maxDay < homeworks[i][0]) {
        maxDay = homeworks[i][0]
    }
}
let dayofScore = new Array(maxDay + 1)
homeworks.sort((a, b) => {
    if (a[1] !== b[1]) {
        return b[1] - a[1]
    }
    else {
        return a[0] - b[0]
    }
})

for (let i = 0; i < N; i++) {
    day = homeworks[i][0]
    while (1) {
        //이 문제는 풀 수 없는 문제
        if (day === 0)
            break
        if (dayofScore[day] === undefined) {
            dayofScore[day] = homeworks[i][1]
            break
        }
        day--
    }
}
console.log(dayofScore.reduce((sum, currValue) => { return sum + currValue }))


```

---

아이디어가 중요했던 문제. 아무리 생각해도 모르겠어서 다른 사람의 아이디어를 보고 풀었다.

가장 기본적으로 점수가 높은 순으로 정렬하는데, 만약 점수가 같은 경우 끝나는 시점이 더 빠른 것을 앞에 위치하도록 해야 했다.

그 이후에 하나씩 순회하면서 해당 날짜에 풀 수 있는 문제가 채워지지 않은 상태라면 해당 문제로 채우고, 이미 채워져있는 상태라면 날짜를 하루씩 앞으로 당겨가면서 비어있을 경우 채우는 식으로 구성하면 됐다.

이런 식으로 순회하게 되면 점수가 작고 빨리 끝내야 하는 과제들은 자동으로 걸러지게 된다.