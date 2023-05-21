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

    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

int maxpathdown(Node *root, int &maxi) // returns the max sum of every node
{
    if (root == NULL)
        return 0;

    int left = max (0, maxpathdown(root->left, maxi));
    int right = max(0, maxpathdown(root->right, maxi));

    maxi = max(maxi, (root->key) + left + right);

    return (root->key) + max(left, right);
}

int maxpathsum(Node *root)
{
    int sum = INT_MIN;
    maxpathdown(root, sum);
    return sum;
}

int main()
{
    Node *root = new Node(-10);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->left->right = new Node(7);
    root->right->left->right->right = new Node(8);
    cout << maxpathsum(root);
}

//        -10
//    2          3
// 4     5    6
//               7
//                  8
