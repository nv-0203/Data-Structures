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

bool isLeaf(Node *node)
{
    return (node->left==NULL && node->right==NULL);
}

void addLeftBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
            res.push_back(curr->key);
            
        if (curr->left!=NULL)
            curr=curr->left;
        else
            curr=curr->right;
    }
}

void addLeaves(Node *root, vector<int> &res)
{
    if (isLeaf(root))
        res.push_back(root->key);
    if (root->left) addLeaves(root->left, res);
    if (root->right) addLeaves(root->right, res);
}

void addRightBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->right;
    vector<int> temp;
    while(curr)
    {
        if(!isLeaf(curr))
            temp.push_back(curr->key);
        if (curr->right) curr = curr->right;
        else    curr=curr->left;
    }
    for(int i=temp.size()-1; i>=0; i--)
    {
        res.push_back(temp[i]);
    }
}

void boundarytraversal(Node *root)
{
    if (root == NULL)
        return;
    vector<int> ans;
    if (!isLeaf(root))
        ans.push_back(root->key);
        
    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);

    for (int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
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

    boundarytraversal(root);
}

//         1
//    2          3
// 4     5    6     
//               7
//                  8
