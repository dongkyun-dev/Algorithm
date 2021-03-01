# [백준(17472)_dfs, floyd_warshall, greedy](https://www.acmicpc.net/problem/17472)

```javascript
// 가장 기본적인 접근은 건설 가능한 다리들을 모두 확인한다는 것이다. 
// 모두 확인한 이후에 비용이 적은 것부터 연결해나간다. 
// 이때! 단순히 1차원 배열을 선언해놓고 연결되었는지를 확인하게 되면 바로 아래와
// 같은 테스트케이스에서 틀리게 된다. 통해서 갈 수 있는 모든 곳들을 확인해야지 
// 제대로 이 문제를 풀 수 있고 때문에 2차원 배열을 활용한 플로이드 와샬 개념이 필요했다. 

const fs = require('fs');
const stdin = (process.platform === 'linux'
    ? fs.readFileSync('/dev/stdin').toString()
    : `10 10
0 0 0 1 1 0 0 0 0 0
0 0 0 1 0 0 0 0 0 1
0 0 0 1 1 0 0 0 0 0
0 0 0 1 1 0 0 0 0 0
1 0 0 1 0 0 0 0 0 1
0 0 0 1 1 0 0 0 0 0
0 0 0 1 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1
0 0 1 1 1 1 0 0 1 1`
).split('\n');

const input = (() => {
    let line = 0;
    return () => stdin[line++];
})();

function solution(N, M, graph) {
    let visited = Array.from(Array(N), () => Array(M).fill(0))
    let islandNum = 1
    let queue = []
    const Directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]

    //기본적인 bfs 함수. (물론 dfs로 하는게 훨씬 더 깔끔하고 더 적절했을 것 같지만, bfs를 연습할 필요가 있어 일부로 이렇게 하였다.)
    //또한, 일반적인 bfs와는 달리 섬의 번호를 붙여주면서 순회하였다.
    const bfs = (() => {
        while (queue.length) {
            let tmp = queue.shift()
            let currX = tmp.currX
            let currY = tmp.currY
            for (let dir of Directions) {
                let nextX = currX + dir[0]
                let nextY = currY + dir[1]
                if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M) {
                    if (graph[nextX][nextY] && !visited[nextX][nextY]) {
                        visited[nextX][nextY] = 1
                        graph[nextX][nextY] = islandNum
                        queue.push({ currX: nextX, currY: nextY })
                    }
                }
            }
        }
    })
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < M; j++) {
            if (graph[i][j] && !visited[i][j]) {
                queue.push({ currX: i, currY: j })
                visited[i][j] = 1
                graph[i][j] = islandNum
                bfs()
                islandNum++
            }
        }
    }

    //만들 수 있는 모든 다리를 저장한다. 이때 다리의 시작과 도착에 관한 섬 번호, 비용에 대한 기록이 필요하다. 
    let possiblePath = []
    const findBridge = ((x, y, currIslandNum, dir, cnt) => {
        let nextX = x + dir[0]
        let nextY = y + dir[1]
        if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M) {
            if (graph[nextX][nextY] !== 0 && graph[nextX][nextY] !== currIslandNum && cnt > 1) {
                possiblePath.push({ from: currIslandNum, to: graph[nextX][nextY], cost: cnt })
                return
            }
        }
        if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M && !graph[nextX][nextY]) {
            findBridge(nextX, nextY, currIslandNum, dir, cnt + 1)
        }

    })
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < M; j++) {
            if (graph[i][j]) {
                //주요했던 것이 상하좌우 모든 방면을 확인할 필요가 없다. 어짜피 좌측상단에서 우측하단으로 가기 때문에
                //각 섬에서 아래, 오른쪽으로 갈 수 있는 길만을 파악하면 된다.(방향성이 없는 다리이기 때문에) 
                for (let k = 0; k < 2; k++) {
                    findBridge(i, j, graph[i][j], Directions[k], 0)
                }
            }
        }
    }

    let bridgeVisited = Array.from(Array(islandNum), () => Array(islandNum).fill(0))
    //비용을 기준으로 정렬한다.
    possiblePath.sort((a, b) => {
        return a.cost - b.cost
    })
    let ans = 0

    const floyd_warshall = (() => {
        for (let via = 0; via < islandNum; via++) {
            for (let from = 0; from < islandNum; from++) {
                for (let to = 0; to < islandNum; to++) {
                    if (bridgeVisited[from][via] == 1 && bridgeVisited[via][to] == 1)
                        bridgeVisited[from][to] = 1;
                }
            }
        }
    })
    //플로이드 와샬 알고리즘 어떠한 곳을 경유해서 갈 수 있는 모든 곳들을 기록한다.
    for (let i = 0; i < possiblePath.length; i++) {
        if (!bridgeVisited[possiblePath[i].from][possiblePath[i].to]) {
            bridgeVisited[possiblePath[i].from][possiblePath[i].to] = 1
            bridgeVisited[possiblePath[i].to][possiblePath[i].from] = 1
            ans += possiblePath[i].cost
            floyd_warshall()
        }
    }

    let flag = 0
    for (let i = 1; i < bridgeVisited.length; i++) {
        for (let j = 1; j < bridgeVisited.length; j++) {
            if (!bridgeVisited[i][j]) {
                flag = 1
                break
            }
        }
    }
    //다 방문되었다면 다리를 놓을 수 있는 경우, 그렇지 않다면 다리를 놓을 수 없는 경우이다.
    if (flag) return -1
    else return ans
}

const [N, M] = input().split(' ').map((A) => parseInt(A))
let graph = new Array()
for (let i = 0; i < N; i++) {
    let tmp = input().split(' ').map((A) => parseInt(A))
    graph.push(tmp)
}
console.log(solution(N, M, graph))
```

부분 부분 모두 지나왔던 알고리즘들이기 때문에 특별하거나 어려울건 없었다. 하지만, 아이디어를 생각해내고 이를 바탕으로 구현하는게 까다로웠다.