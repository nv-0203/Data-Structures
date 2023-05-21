#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>
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

//task: create a function "serialize" to convert a node 'root' into a string 'str; 
// create another function "de-serialize" that takes in 'str' and converts it back to 'root'

string serialize(Node *root)
{
    string ans;
    queue<Node*> que;
    que.push(root);
    while (!que.empty())
    {
        Node *curr = que.front();
        que.pop();

        if (curr == NULL)
            ans.append("#,");
        else
        {
            ans.append(to_string(curr->key)+',');
            que.push(curr->left);
            que.push(curr->right);
        }
    }
    return ans;
}


Node *deserialize(string s)
{
    if (s.size()==0)
        return NULL;
    queue<Node*> que;

    stringstream ss(s);
    string first;
    getline(ss, first, ',');

    Node *root = new Node(stoi(first));
    que.push(root);

    int i=0;

    while (!que.empty())
    {
        if (s[i]==',')
            continue;

        Node *top = que.front();
        que.pop();

        string temp;
        getline (ss, temp, ',');
        
        Node *leftNode;
        if (temp != "#")
        {
            leftNode = new Node(stoi(temp));
            que.push(leftNode);
        }
        else
            leftNode = NULL;
        top -> left = leftNode;

        getline(ss, temp, ',');
        Node *rightNode;
        if (temp != "#")
        {
            rightNode = new Node(stoi(temp));
            que.push(rightNode);
        }
        else
            rightNode = NULL;
        top -> right = rightNode;
    }
    return root;
}

int main()
{
    Node *root = new Node(1);
    Node *a = root -> left = new Node(2);
    Node *b = root -> left -> left = new Node(4);
    Node *c = root -> left -> right = new Node(50);
    Node *d = root -> right = new Node(3);
    Node *e = root -> right -> left = new Node(6);
    Node *f = root -> right -> left -> right = new Node(7);
    Node *g = root -> right -> left -> right -> right = new Node(8);

    string ans = serialize(root);
    cout<<ans<<endl;
    Node *check = deserialize(ans);
    BFS(check);
}

//         1
//    2          3
// 4    50    6     
//               7
//                  8