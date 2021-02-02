# [Codility(FrogRiverOne)](https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/)

---

```javascript
//77%가 나오는 내 기존 코드

let visited = new Array()
visited.fill(0)
const chk = ((X)=>{
    for(let i=1;i<=X;i++){
        if(!visited[i]) return false
    }
    return true
})
function solution(X, A) {
    // write your code in JavaScript (Node.js 8.9.4)
     for(let i=0;i<A.length;i++){
        if(!visited[A[i]])
        visited[A[i]]=true;
        if(chk(X)) return i;
    }
    return -1;
}
```

```javascript
//100%가 나오는 수정된 코드

function solution(X, A) {
    // write your code in JavaScript (Node.js 8.9.4)
    let visited = Array(X+1).fill(0)
    let count = 0
     for(let i=0;i<A.length;i++){
        if(!visited[A[i]]){
        visited[A[i]]=1
        count++
        }
        if(count==X) return i;
    }
    return -1;
}
```

---

문제 자체는 굉장히 간단하기 때문에 문제를 한 번 읽고 코드를 보면 쉽게 이해가 될 것이라 생각한다. 기존에 나는 `visited` 배열은 만들어두고 매번 그 배열을 순회하는 식으로 코드를 짰다.

시간복잡도는 `O(n^2)` 들어올 수 있는 X의 최대값인 100,000이 들어올 경우 1억을 훌쩍 넘게 된다.(아마도 이 문제는 1초내에 답이 나와야 하는듯?) 때문에 시간복잡도를 줄여야 했다. `visited` 배열이 수정될 때마다 `count` 개수를 늘려서 `count`개수와 X의 개수가 동일해지는 시점이 개구리가 강을 건널 수 있는 시점이기 때문에 그때 i를 출력하도록 했다.(다른 스터디원분의 코드를 참고하였다.) 

---

## ❓느낀점

사실 이렇게 시간복잡도를 고려하면서 효율적인 코드를 짜는 문제를 처음 풀어봤다. 지금까지 해왔던 것처럼 마구잡이로 문제를 풀어서는 안되겠다는 생각이 들었다. 조금 더 효율적인 코드를 짜는 노력을 해야 한다.