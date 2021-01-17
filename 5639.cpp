/*********************
insert함수를 통해 트리를 만들고 이 트리를 후위 순회 시킨다.
트리에서의 기본 노드 구조를 짤 때 참고하면 좋을 듯.
***********************/
#include <iostream>

using namespace std;

int cnt;

typedef struct Node
{
    int value;
    Node *leftChild, *rightChild;
    Node(int _value) : value(_value), leftChild(NULL), rightChild(NULL) {}
} Node;

Node *firstNode;

void insert(int num)
{
    Node *newNode = new Node(num);
    if (cnt == 0)
    {
        firstNode = newNode;
    }
    else
    {
        Node *temp = firstNode;
        while (1)
        {
            if (temp->value < num)
            {
                if (!temp->rightChild)
                {
                    temp->rightChild = newNode;
                    break;
                }
                temp = temp->rightChild;
            }
            else if (temp->value > num)
            {
                if (!temp->leftChild)
                {
                    temp->leftChild = newNode;
                    break;
                }
                temp = temp->leftChild;
            }
        }
    }
    cnt++;
    return;
}

void postOrder(Node *ptr)
{
    if (ptr)
    {
        postOrder(ptr->leftChild);
        postOrder(ptr->rightChild);
        cout << ptr->value << "\n";
    }
}
int main()
{
    int num;
    while (cin >> num) //이런 식으로 입력을 받으면 입력이 그만 되는 시점에 맞춰서 cin이 멈추게 된다. 이게 가장 간단하고 보기 쉬운 코드인듯.
    {
        insert(num);
    }
    postOrder(firstNode);
}