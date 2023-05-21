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

bool root_to_node(Node *root, int val, vector<int> &v)
{
    if (root == NULL)
        return false;
    
    v.push_back(root->key);
    if (root->key == val)
        return true;
    
    if (root_to_node(root->left, val, v) || root_to_node(root->right, val, v))
        return true;
    
    v.pop_back();
    return false;
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

    vector<int> res;
    if(root_to_node(root, 8, res))
    {
        for (int x:res)
            cout<<x<<" ";
    }
    else
        cout<<"Element not present";
    

}

//         1
//    2          3
// 4     5    6     
//               7
//                  8
