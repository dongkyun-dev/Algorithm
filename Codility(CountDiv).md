# [Codility(CountDiv)](https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/)

---

```javascript
function solution(A, B, K) {
    // write your code in JavaScript (Node.js 8.9.4)
    let start
    if(A % K == 0){
        start = parseInt(A / K)
    }
    else{
        start = parseInt(A / K) + 1
    }
    const end = parseInt(B / K)
    return end-start+1
}
```

---

A이상 B 이하에서 K로 나누어 떨어지는 수의 개수를 구하는 문제였다. A와 B 사이가 최대 20억이 될 수 있기 때문에 반드시 O(1)의 시간복잡도를 가져야 했다.

때문에 일반적인 접근과는 조금 다른 접근이 필요했고 A를 K로 나눈 값과 B를 K로 나눈 값 사이의 개수를 구해서 반환하면 된다는 것을 알게 되었다.

하지만, 여기서 주의해야 할 것이 end의 경우에는 문제가 되지 않지만 start의 경우 나눗셈의 결과가 실수가 되는 경우 결과값이 조금 달라진다는 것이다. start가 나누어 떨어질 때는 start가 포함될 수 있지만 start가 나누어떨어지지 못하고 실수가 되는 경우에는 start를 포함할 수 없다.



