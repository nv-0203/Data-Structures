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

    Node(int x)
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

// task: construct a binary tree given its inorder and preorder

int findpos(int node, int val, vector<int> &inorder)
{
    int flag = 0; //left (if flag = 1; then right)
    for (int i=0; i<inorder.size(); i++)
    {
        if (inorder[i] == node)
        {
            flag = 1;
            break;
        }
        else if (inorder[i] == val)
            break;
    }
    return flag;
}

Node *buildTree(vector<int> &preorder, int preStart, int preEnd, 
    vector<int> &inorder, int inStart, int inEnd, map<int, int> inMap)
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;
    Node *root = new Node(preorder[preStart]);

    int inRoot = inMap[preorder[preStart]];
    int NumsLeft = inRoot - inStart;

    root->left = buildTree(preorder, preStart + 1, preStart + NumsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTree(preorder, preStart + NumsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
    return root;
}

Node *createTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> map;  //value - index
    for (int i=0; i<inorder.size(); i++)
    {
        map[inorder[i]]=i;
    }

    Node *root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, map);
    return root;

}

int main()
{
    vector<int> inorder = {20, 50, 10, 40, 60, 30};
    vector<int> preorder = {10, 20, 50, 30, 40, 60};
    Node *root = createTree(preorder, inorder);
    BFS(root);
}

//        10
// 20              30
//    50        40
//                 60