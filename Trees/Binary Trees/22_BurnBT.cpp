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

//task: Find minimum time taken to burn the entire binary tree from a given point

Node* MakeParent(Node *root, unordered_map<Node*, Node*> &mp_parent, int start)
{
    Node *res; //will store the target node that i need
    queue<Node*> que;
    que.push(root);
    while (!que.empty())
    {
        Node *curr = que.front();
        que.pop();

        if (curr->key == start)
            res = curr;

        if (curr->left != NULL)
        {
            que.push(curr->left);
            mp_parent[curr->left] = curr;
        }
        if (curr->right != NULL)
        {
            que.push(curr->right);
            mp_parent[curr->right] = curr;
        }
    }
    return res;
}

int time_to_burn(Node *root, int start_val)
{
    unordered_map<Node*, Node*> mp_parent;  //child - parent
    Node *start = MakeParent(root, mp_parent, start_val); //this function makes the child parent map and also returns the node that contains the start value

    queue<Node*> que;
    unordered_map<Node*, bool> visited;

    que.push(start);
    visited[start]=true;
    int time = 0;

    while (!que.empty())
    {
        int size = que.size();

        int flag = 0; //becomes 1 only if any adjacent node is burned
        for(int i=0; i<size; i++)
        {
            Node *curr = que.front();
            que.pop();

            if (curr->left && visited[curr->left]==false)
            {
                flag = 1;
                que.push(curr->left);
                visited[curr->left]=true;
            }
            if (curr->right && visited[curr->right]==false)
            {
                flag = 1;
                que.push(curr->right);
                visited[curr->right]=true;
            }
            if(mp_parent[curr] && visited[mp_parent[curr]]==false)
            {
                flag = 1;
                que.push(mp_parent[curr]);
                visited[mp_parent[curr]]=true;
            }
        }
        if (flag) time++;
    }
    return time;

}

int main()
{
    Node *root = new Node(1);
    Node *a = root -> left = new Node(2);
    Node *b = root -> left -> left = new Node(4);
    Node *c = root -> left -> right = new Node(5);
    Node *d = root -> right = new Node(3);
    Node *e = root -> right -> left = new Node(6);
    Node *f = root -> right -> left -> right = new Node(7);
    Node *g = root -> right -> left -> right -> right = new Node(8);

    cout<<time_to_burn(root, 5)<<endl;
    cout<<time_to_burn(root, 1)<<endl;
    cout<<time_to_burn(root, 3);
}

//         1
//    2          3
// 4     5    6     
//               7
//                  8
