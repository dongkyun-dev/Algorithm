# [Codility(missing_integer, perm_check)](https://app.codility.com/programmers/lessons/4-counting_elements/missing_integer/)

---

```javascript
//missing_integer

function solution(A) {
    let visited = new Array(1000000).fill(0)
    for(let i=0;i<A.length;i++){
        if(A[i]<=0)
        continue
        visited[A[i]] = 1
    }
    for(let i=1;i<1000000;i++){
        if(!visited[i])
        return i
    }    
}
```

```javascript
//perm_check

function solution(A) {
    let visited = new Array(100000).fill(0)
    for(let i=0;i<A.length;i++){
        visited[A[i]] = 1
    }
    for(let i=1;i<=A.length;i++){
        if(!visited[i])
        return 0
    }
    return 1
}
```

---

어렵지 않은 문제들이었다.

---

## 💫느낀점

`for(let i=0;i<A.length;i++)` 항상 이런 식으로 코드를 적어왔다. 그런데 이렇게 하게 되면 이 for loop에 들어갈 때 마다 A의 길이를 계산하게 된다. A의 길이는 달라지지 않는데도 불구하고 말이다. 때문에 가장 처음에 `let len = A.length` 이런 식으로 변수에 할당해두고 사용하는 편이 훨씬 좋은 선택지 이다. 

위 아래 둘다 시간복잡도는 O(N) or O(N * log(N)) 이다.