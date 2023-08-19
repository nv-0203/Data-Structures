#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <math.h>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
using namespace std;
typedef long long int ll;

struct Node
{
    int key;
    Node *left;
    Node *right;

    Node (int x)
    {
        key = x;
        left = right = NULL;
    } 
};

bool checkidentical(Node *node1, Node *node2)
{
    if (node1==NULL || node2==NULL)
        return (node1==node2);
    
    if (node1->key != node2->key)
        return false;
    
    bool left = checkidentical(node1->left, node2->left);
    bool right = checkidentical(node1->right, node2->right);

    return left && right;
}

int main()
{
    Node *root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> left -> right = new Node(7);
    root -> right -> left -> left = new Node(8);
    cout<<checkidentical(root->right, root->left);
    cout<<endl;
    cout<<checkidentical(root->left, root->right->left);
}

//         1
//    2          3
// 4     5    6     
//          8    7
//                  
