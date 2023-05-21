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

int lh(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + lh(root->left);
}

int rh(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + rh(root->right);
}

int no_of_nodes(Node *root)
{
    int left = lh(root);
    int right = rh(root);

    if (left == right)
        return (pow(2, left) - 1);
    else
        return 1 + no_of_nodes(root->left) + no_of_nodes(root->right);

}

int main()
{
    Node *root = new Node(1);
    Node *a = root -> left = new Node(2);
    Node *b = root -> left -> left = new Node(4);
    Node *c = root -> left -> right = new Node(5);
    Node *d = root -> right = new Node(3);
    Node *e = root -> right -> left = new Node(6);
    Node *f = root -> right -> right = new Node(7);
    Node *g = root -> left -> left -> left = new Node(8);
    
    cout<<no_of_nodes(root);
}

//           1
//      2          3
//   4     5    6     7
//8               
//                  
