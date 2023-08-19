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

//BFS but in alternating manner
void zigzag(Node *root)
{
    vector<vector<int>> ans;
    queue<Node*> que;
    que.push(root);
    int flag = 0;
    while (!que.empty())
    {
        
        int size = que.size();
        vector<int> level;
        for (int i=0; i<size; i++)
        {
            Node *curr = que.front();
            if (curr->left != NULL)
                que.push(curr->left);
            if (curr->right != NULL)
                que.push(curr->right);

            level.push_back(curr->key);
            que.pop();
        }
        if (flag == 1)
        {
            reverse(level.begin(), level.end());
            flag=0;
        }
        else
            flag = 1;
        ans.push_back(level);
    }

    for (int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
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
    root -> right -> left -> left = new Node(10);
    root -> right -> left -> right -> right = new Node(8);
    root -> right -> left -> right -> left = new Node(11);

    zigzag(root);    
}

//           1
//    2             3
// 4     5        6     
//             10     7
//                  11   8
