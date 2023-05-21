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

void bottom_view(Node *root)
{
    map<int, int> mp;       //vertical node //stores value of node and essentially replaces any other value present at that vertical
    queue<pair<Node*, int>> que;  //node vertical
    que.push({root, 0});
    while (!que.empty())
    {
        auto it = que.front();
        que.pop();

        Node *curr = it.first;
        int x = it.second;

        mp[x]=(curr->key);

        if (curr->left != NULL)
            que.push({curr->left, x-1});
        if (curr->right != NULL)
            que.push({curr->right, x+1});
    }

    for (auto it:mp)
    {
        cout<<it.second<<" ";
    }
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

    bottom_view(root);
}

//         1
//    2          3
// 4       56     
//               7
//                  8
