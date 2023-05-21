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

Node* lca(Node *root, Node *p, Node *q)
{
    if (root==NULL || root==p || root==q)
        return root;
    
    Node *left = lca(root->left, p, q);
    Node *right = lca(root->right, p, q);

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root;
    
}

int main()
{
    Node *root = new Node(1);
    root -> left = new Node(2);
    Node *p = root -> left -> left = new Node(4);
    Node *q = root -> left -> right = new Node(5);
    Node *r = root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> left -> right = new Node(7);
    root -> right -> left -> right -> right = new Node(8);

    Node *ans = lca (root, p, q);
    cout<<ans->key<<endl;
    Node *ans1 = lca (root, p, r);
    cout<<ans1->key;
}

//         1
//    2          3
// 4     5    6     
//               7
//                  8
