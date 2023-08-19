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

string serialize(Node* root) 
{
    string s;
    queue<Node*> que;
    que.push(root);
    while (!que.empty())
    {
        Node *node = que.front();
        que.pop();
        if (node)
        {
            s += to_string(node->key);
            que.push(node->left);
            que.push(node->right);
        }
        else
            s.push_back('N');
        s.push_back(',');
    }
    return s;
}

// Decodes your encoded data to tree.
Node* deserialize(string s) 
{
    Node *root;

    stringstream ss(s);
    string token;

    getline(ss, token, ',');
    if (token == "N")
        return NULL;
    root = new Node(stoi(token));

    queue<Node*> que;
    que.push(root);

    while (!que.empty())
    {
        Node *curr = que.front();
        que.pop();

        if (getline(ss, token, ','))
        {
            if (token != "N")
            {
                curr->left = new Node(stoi(token));
                que.push(curr->left);
            }
        }

        if (getline(ss, token, ','))
        {
            if (token != "N")
            {
                curr->right = new Node(stoi(token));
                que.push(curr->right);
            }
        }
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