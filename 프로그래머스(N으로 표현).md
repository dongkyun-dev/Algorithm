# [프로그래머스(N으로 표현)](https://programmers.co.kr/learn/courses/30/lessons/42895)

---

### &#10060;코드들


```c++
#include <string>
#include <vector>

using namespace std;

int ans = 9;
void dfs(int N, int number, int numofN, int result){
    if(numofN > 8) return;
    if(number == result){
        ans = min(ans, numofN);
        return;
    }
    int continuous_N = 0;
    for(int i = 1; i <= 9 ; i++){
        continuous_N = continuous_N * 10 + N;
        dfs(N, number, numofN + i, result + continuous_N);
        dfs(N, number, numofN + i, result - continuous_N );
        dfs(N, number, numofN + i, result * continuous_N );
        if(continuous_N){
             dfs(N, number, numofN + i, result / continuous_N );
        }
    }
}

int solution(int N, int number) {
    dfs(N, number, 0, 0);
    if(ans==9)
        return -1;
    else
        return ans;
}
```

```javascript
let ans = 9

const dfs = ((N, number, numofN, result)=>{
    if(numofN > 8) return -1
    if(number == result){
       ans = Math.min(ans, numofN)
        return ans
    }
    let continuous_N = 0
    for(let i = 1; i <= 9; i++){
        continuous_N = continuous_N * 10 + N;
        dfs(N, number, numofN + i, result + continuous_N)
        dfs(N, number, numofN + i, result - continuous_N )
        dfs(N, number, numofN + i, result * continuous_N )
        dfs(N, number, numofN + i, result / continuous_N )
    }
})

function solution(N, number) {
    dfs(N, number, 0, 0)
    if(ans == 9)
        return -1
    else
        return ans
}
```

---

### &#10060;설명

와.... 너무 어려웠다😪😪 이것 저것 생각해봤지만 지금 내 수준에서 절대 풀 수 없는 문제였다. 때문에 구글에 있는 여러 코드들을 봤다. 그중 [이곳](https://dvpzeekke.tistory.com/73)의 코드가 가장 이해하기 쉬웠고 편했다. dp문제가 아닌 dfs 방식으로 문제를 푸셨다. 연산을 하나씩 늘려가며 dfs를 돌려가는 코드이다. 내 생각에 이 코드에서 가장 핵심은

```c++
 continuous_N = continuous_N * 10 + N;
```

이 부분이지 않을까 라는 생각이 들었다. 만약 N이 5라면 이 수는 dfs의 재귀 깊이에 따라 5, 55, 555, 5555 .... 이런 식으로 변화한다. 때문에 이 수를 가지로 dfs를 돌려서 답을 구해낼 수 있는 것이다.

---

### &#10060;C++과 JS에서의 차이

c++과 자바스크립트 코드에서 가장 큰 차이점은 ` dfs(N, number, numofN + i, result / continuous_N )` 이 부분이었다. 자바스크립트에서는 `0`으로 나누어도 문제를 발생시키지 않는다. 때문에 따로 이 구문을 실행시키기 위한 조건을 달지 않아도 된다. 하지만, c++에서는 `0`으로 나눌 수 없다. 때문에 `0`이 아닐 때만 나눌 수 있도록 코드를 구성하였다.

또한, c++에서는 그냥 min으로 쓰면 되는 최솟값 반환 함수가 자바스크립트에서는 Math.min이다. 기억해두자.

---

### &#10060;느낀점

항상 느끼지만 너무 실력이 부족하다.... 언제쯤 나도 저런 아이디어를 생각해내고 코드로 구현할 수 있을지에 대한 걱정이 앞선다... 이런 걱정을 원동력 삼아 더 열심히 해야겠다.