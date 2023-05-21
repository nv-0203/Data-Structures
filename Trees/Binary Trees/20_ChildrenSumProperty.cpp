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

void BFS(Node *root)
{
    //vector<vector<int>> ans;
    queue<Node*> que;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        //vector<int> level;
        for (int i=0; i<size; i++)
        {
            Node *curr = que.front();
            if (curr->left != NULL)
                que.push(curr->left);
            if (curr->right != NULL)
                que.push(curr->right);

            //level.push_back(curr->key);
            cout<<(curr->key)<<" ";
            que.pop();
        }
        cout<<endl;
        //ans.push_back(level);
    }
}

//Children Sum Property: every node should be equal to sum of its two child nodes
//task: convert given tree to a tree that satisfies children sum property

//f both children sum is less than parent, make children's value to parent's value.
//if both children values sum is greater than or equal to parent, make parent's value to children's sum.
//hen coming back up the tree, take children sum and replace it in parent.

void changeTree(Node *root)
{
    if (root == NULL)
        return;

    int child = 0;
    if (root -> left != NULL)
        child += root->left->key;
    if (root -> right != NULL)
        child += root->right->key;

    if (child < root->key)
    {
        if (root->left) root->left->key = root -> key;
        if (root->right) root->right->key = root -> key;
    }
    else
        root -> key = child;

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if (root->left) total+=root->left->key;
    if (root->right) total+=root->right->key;
    if (root->left || root->right) root->key = total;
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

    BFS(root);
    cout<<endl;
    changeTree(root);
    BFS(root);
}

//         1
//    2          3
// 4     5    6     
//               7
//                  8
