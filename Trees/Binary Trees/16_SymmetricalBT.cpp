#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <math.h>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <set>
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

bool help(Node *left_node, Node *right_node) //symmetric means LHS and RHS must be mirror images of each other
{
    if (left_node==NULL || right_node==NULL)
        return left_node == right_node;

    if (left_node->key != right_node->key)
        return false;
    
    return help(left_node->left, right_node->right);
    return help(left_node->right, right_node->left);
}

bool isSymmetric(Node *root)
{
    return root == NULL || help(root->left, root->right);
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
    root -> right -> left -> right -> right = new Node(8);

    Node *tree2 = new Node(1);
    tree2 -> left = new Node(2);
    tree2 ->right = new Node(2);
    tree2 -> left ->right = new Node(3);
    tree2 ->right ->left = new Node(3);
    cout<<isSymmetric(root);
    cout<<endl;
    cout<<isSymmetric(tree2);
}

//         1
//    2          3
// 4     5    6     
//               7
//                  8
