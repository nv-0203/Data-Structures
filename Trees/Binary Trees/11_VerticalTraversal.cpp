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

//map<int, map<int, multiset<int>>> mp

void vertical_traversal(Node *root)
{
    map<int, map<int, multiset<int>>> mp;   // vertical  level  node(s)

    queue <pair<Node*, pair<int, int>>> que; //Node vertical level
    que.push({root, {0, 0}});
    while (!que.empty())
    {
        auto it = que.front();
        que.pop();
        Node *curr = it.first;

        int x = it.second.first;    //vertical
        int y = it.second.second;   //level

        mp[x][y].insert(curr->key);

        if (curr->left != NULL)
            que.push({curr->left, {x-1, y+1}});
        if (curr->right != NULL)
            que.push({curr->right, {x+1, y+1}});
    }

    vector<vector<int>> ans;
    for (auto at:mp)
    {
        vector<int> col;
        for (auto bt: at.second) {                                          //vector_name.insert(position, iterator1, iterator2)
            col.insert(col.end(), bt.second.begin(), bt.second.end());      //position – It specifies the position at which insertion is to be done in the vector.
        }                                                                   //iterator1 – It specifies the starting position from which the elements are to be inserted
        ans.push_back(col);                                                 //iterator2 – It specifies the ending position till which elements are to be inserted
    }

    for (int i=0; i<ans.size(); i++)
    {
        for (int j=0; j<ans[i].size(); j++)
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
    root -> right -> left -> right -> right = new Node(8);

    vertical_traversal(root);
}

//         1
//    2          3
// 4      5 6     
//               7
//                   8
