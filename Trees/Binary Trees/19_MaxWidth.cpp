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

// max width = max no of nodes in a level between any two nodes of that level
int maxwidth(Node *root)
{
    queue<pair<Node*, int>> que; //Node index
    que.push({root, 1});
    int maxi = 0;
    while (!que.empty())
    {
        int size = que.size();
        auto at = que.front();
        int start, end;
        start = at.second;
        for (int i=0; i<size; i++)
        {
            auto it = que.front();
            que.pop();

            Node *curr = it.first;
            int x = it.second;

            if (curr->left != NULL)
                que.push({curr->left, 2*x});
            if (curr->right != NULL)
                que.push({curr->right, 2*x+1});

            end = x;
        }
        maxi = max(maxi, end - start + 1);
    }

    return maxi;
}

int main()
{
    Node *root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right = new Node(3);
    root -> right -> right = new Node(6);
    root -> right -> right -> left = new Node(7);
    root -> right -> right -> left -> right = new Node(8);

    cout<<maxwidth(root);
}
//                          max width b/w any 2 nodes of that level
//         1                1
//    2          3          2
// 4     5          6       4
//               7          1
//                  8       1
