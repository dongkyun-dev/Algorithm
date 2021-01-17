/**********************
크루스칼 알고리즘을 이용한 최소 스패닝 트리 구하기.

크루스칼의 내용은  https://yabmoons.tistory.com/186 이곳에 정리가 잘 되어 있다.

1. 모든 간선들의 가중치를 오름차순으로 정렬한다.
2. 가중치가 가장 작은 간선을 선택한다.(sort를 통해 정렬할 것이므로 배열의 첫 원소를 고르면 된다.)
3. 2에서 선택한 간선이 연결하려는 2개의 노드가 아직 서로 연결되지 않은 상태라면, 2개의 노드를 서로 연결한다.
4. 위의 과정을 반복한다.

***********************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10001;
int parent[MAX];
int V, E;

int findParent(int x) //이전 유니온파인드 문제와는 다른 함수명을 사용했다. 다른 블로그를 참고하다가 이런 이름이 조금 더 직관적으로 파악하기 좋을 것 같아서.
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = findParent(parent[x]);
}

void merge(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    if (a < b)
        parent[b] = a;
    else if (a > b)
        parent[a] = b;
}

struct Edge
{
    int start, end, weight;

    bool operator<(Edge const &e) //정렬을 위해 연산자 오버로딩을 이곳에 만들어준다. 가중치를 기준으로 정렬한다.
    {
        return weight < e.weight;
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<Edge> edge;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        edge.push_back({start, end, weight});
    }
    sort(edge.begin(), edge.end()); //정렬!
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }
    int result = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        Edge tmp = edge[i];
        if (findParent(tmp.start) != findParent(tmp.end))
        {
            result += tmp.weight;
            merge(tmp.start, tmp.end);
        }
    }
    cout << result;
}
