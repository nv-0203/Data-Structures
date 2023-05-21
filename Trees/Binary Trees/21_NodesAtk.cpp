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

//task:print nodes at distance k from target node
void markParents(Node *root, unordered_map<Node *, Node*> &mp_parent)
{
    queue<Node*> que;
    que.push(root);
    while (!que.empty())
    {
        Node *curr = que.front();
        que.pop();

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
}

void printnodes(Node *root, Node *target, int k)
{
    unordered_map<Node*, Node*> mp_parent;    //child - parent
    markParents (root, mp_parent);
    

    int dist = 0;
    unordered_map<Node*, bool> visited;
    queue<Node*> que;
    que.push(target);
    visited[target]=true;
    while (dist <= k && !que.empty())
    {
        int size = que.size();
        if (dist++ == k)
            break;

        for(int i=0; i<size; i++)
        {
            Node *curr = que.front();
            que.pop();

            if (curr->left && visited[curr->left]==false)
            {
                que.push(curr->left);
                visited[curr->left]=true;
            }
            if (curr->right && visited[curr->right]==false)
            {
                que.push(curr->right);
                visited[curr->right]=true;
            }
            if(mp_parent[curr] && visited[mp_parent[curr]]==false)
            {
                que.push(mp_parent[curr]);
                visited[mp_parent[curr]]=true;
            }
        }
        
    }
    while (!que.empty())
    {
        auto it = que.front();
        cout<<it->key<<" ";
        que.pop();
    }
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

    printnodes(root, d, 2);
}

//         1
//    2          3
// 4     5    6     
//               7
//                  8
