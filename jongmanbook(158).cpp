#include <iostream>
#include <cstring>

using namespace std;

int n;
bool areFriends[10][10];

int countPairings(bool taken[10])
{
    int firstFree = -1;
    for (int i = 0; i < n; i++)
    {
        if (!taken[i])
        {
            firstFree = i;
            break;
        }
    }
    if (firstFree == -1)
        return 1;
    int ret = 0;
    for (int pairWith = firstFree + 1; pairWith < n; pairWith++)
    {
        if (!taken[pairWith] && areFriends[firstFree][pairWith])
        {
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count;
    cin >> count;
    while (count--)
    {
        int pairofStudents;
        cin >> n >> pairofStudents;
        while (pairofStudents--)
        {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            areFriends[tmp1][tmp2] = true;
            areFriends[tmp2][tmp1] = true;
        }
        bool freinds[10] = {
            0,
        };
        int answer = countPairings(freinds);
        cout << answer << "\n";
        memset(areFriends, 0, sizeof(areFriends));
    }
}