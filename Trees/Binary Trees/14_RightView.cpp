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

void right_recursive(Node *root, int level, vector<int> &v)
{
    if (root == NULL)
        return;
    
    if (level == v.size())
        v.push_back(root -> key);

    right_recursive(root->right, level + 1, v);
    right_recursive(root -> left, level + 1, v);
}

void right_view(Node *root)
{
    map<int, int> mp;       //level node //stores value of node and essentially replaces any other value present at that vertical
    queue<pair<Node*, int>> que;  //node level
    que.push({root, 0});
    while (!que.empty())
    {
        auto it = que.front();
        que.pop();

        Node *curr = it.first;
        int x = it.second;

        mp[x]=(curr->key);

        if (curr->left != NULL)
            que.push({curr->left, x+1});
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

    right_view(root);
    cout<<endl;
    vector<int> res;
    right_recursive(root, 0, res);
    for (int i=0; i<res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
}

//         1
//    2          3
// 4     5    6     
//               7
//                  8
