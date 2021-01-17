/***************
 신장 트리=Spanning Tree
 Spanning tree의 간선의 개수는 항상 정점의 개수-1이다.

****************/
#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    while (num--)
    {
        int node1, node2;
        cin >> node1 >> node2;
        for (int i = 0; i < node2; i++)
        {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
        }
        cout << node1 - 1 << "\n";
    }
}
