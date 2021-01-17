/****************
 유니온 파인드!!!
ㅋ

******************/
#include <iostream>

using namespace std;

int parent[1000001];

int getParent(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = getParent(parent[x]);
    //재귀함수를 통해 연결되있는 그래프에서의 가장 작은 vertex를 찾는다. 결국 이 vertex 값이 같다면 같은 그래프에 속한다고 할 수 있다.
}

void unionParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);
    if (a < b)
        parent[b] = a;
    else if (a > b)
        parent[a] = b;
    //a와 b 중 더 작은 값을 상대의 부모에 넣게 된다.
}

int findParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);
    if (a == b)
        return 1;
    else
        return 0;
} //부모가 같다면 같은 그래프이기 때문에 1을 return하고 부모가 다르다면 다른 그래프이기 때문에 0을 return 한다.
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;

    cin >> N >> M;
    for (int i = 0; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0)
        {
            unionParent(a, b);
        }
        else if (op == 1)
        {
            if (findParent(a, b))
                cout << "yes";
            else
                cout << "NO";
        }
    }
}