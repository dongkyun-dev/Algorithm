#include <iostream>

using namespace std;

typedef struct Node{
    char data;
    Node *leftChild;
    Node *rightChild;
}node;

void preorder_traverse(Node *R){
    cout<<R->data;
    if(R->leftChild)
        preorder_traverse(R->leftChild);
    if(R->rightChild)
        preorder_traverse(R->rightChild);

}
void inorder_traverse(Node *R){
    if(R->leftChild)
        inorder_traverse(R->leftChild);
    
    cout<<R->data;
    
    if(R->rightChild)
        inorder_traverse(R->rightChild);
}
void postorder_traverse (Node *R){
    if(R->leftChild)
        postorder_traverse(R->leftChild);
    if(R->rightChild)
        postorder_traverse(R->rightChild);
    
    cout<<R->data;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    char tmp1,tmp2,tmp3;
    cin>>num;
    Node *tree = new Node[num];
    for(int i=0;i<num;i++)
    {
        cin>>tmp1>>tmp2>>tmp3;
        int value=tmp1-'A'; //A를 root로 잡기 위해 A일 경우 이렇게 0이 되게 만든다.
        tree[value].data=tmp1;
        if(tmp2=='.')
        {
            tree[value].leftChild=NULL;
        }
        else
        {
            tree[value].leftChild=&tree[tmp2-'A']; //tree 전체가 딸려와야한다.
        }
        if(tmp3=='.')
        {
            tree[value].rightChild=NULL;
        }
        else
        {
            tree[value].rightChild=&tree[tmp3-'A'];
        }
        
    }
    preorder_traverse(&tree[0]);
    cout<<"\n";
    inorder_traverse(&tree[0]);
    cout<<"\n";
    postorder_traverse(&tree[0]);
    
}