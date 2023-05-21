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

Node *buildTree(vector<int> &postorder, int postStart, int postEnd, 
            vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap)
{
    if (postStart < postEnd || inStart > inEnd)
        return NULL;
    
    Node *root = new Node(postorder[postStart]);

    int inRoot = inMap[postorder[postStart]];
    int NumsLeft = inEnd - inRoot;

    root -> left = buildTree(postorder, postStart-NumsLeft-1, postEnd, inorder, inStart, inRoot-1, inMap);
    root -> right = buildTree(postorder, postStart - 1, postStart - NumsLeft, inorder, inRoot+1, inEnd, inMap);

    return root;
}


Node *createTree(vector<int> &postorder, vector<int> &inorder)
{
    map<int, int> mp; //value - index of elements in inorder
    for (int i=0; i<inorder.size(); i++)
    {
        mp[inorder[i]]=i;
    }

    Node *root = buildTree(postorder, postorder.size()-1, 0, inorder, 0, inorder.size()-1, mp);
    return root;    
}

int main()
{
    vector<int> postorder = {50, 20, 60, 40, 30, 10};
    vector<int> inorder = {20, 50, 10, 40, 60, 30};
    Node *root = createTree(postorder, inorder);
    BFS(root);
}

//        10
// 20              30
//    50        40
//                 60