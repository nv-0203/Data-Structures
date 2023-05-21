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

int height(Node *root)
{
    if (root == NULL)
        return 0;
    
    return max(height(root->right), height(root->left)) + 1;
}

// Balanced BT if for every node
// height(left subtree) - height(right subtree) <= 1
bool checkBalanaced(Node *root) //naive solution
{
    if (root == NULL)
        return true;
    
    int lh = height(root -> left);
    int rh = height(root->right);

    if (abs(lh-rh) > 1)
        return false;

    bool left = checkBalanaced(root -> left);
    bool right = checkBalanaced(root -> right);

    if (left==false || right==false)
        return false;

    return checkBalanaced(root);
}

//improvised sol for check of balanced tree
int ht(Node *root)
{
    if (root== NULL)
        return 0;

    int lh = ht(root -> left);
    int rh = ht (root -> right);

    if (lh == -1 || rh==-1)
        return -1;
    if ( abs (lh - rh) > 1)
        return -1;

    return max(lh, rh) + 1;
}

bool check (Node *root)
{
    if (ht(root)==-1)
        return false;
    else
        return true;
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

    cout<<height(root->left);
    cout<<endl;
    cout<<checkBalanaced(root);
    cout<<endl;
    cout<<check(root->left);
}

//         1
//    2          3
// 4     5    6     
//               7
//                  8
