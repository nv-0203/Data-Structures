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

//diameter: longest distance between any two nodes
//doesn't need to necessarily pass through root node

int maxheight(Node *root, int &maxi) //returns the maxheight for every node
{
    if (root == NULL)
        return 0;
    
    int lh = maxheight(root->left, maxi);
    int rh = maxheight(root->right, maxi);

    maxi = max(maxi, lh+rh); //stores max diameter considering that particular node to be vertex

    return 1 + max(lh, rh);

}

int diameterofBT(Node *root)
{
    int diameter = 0;
    maxheight(root, diameter);
    return diameter;
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

    cout<<diameterofBT(root);
}

//         1
//    2          3
// 4     5    6     
//               7
//                  8
