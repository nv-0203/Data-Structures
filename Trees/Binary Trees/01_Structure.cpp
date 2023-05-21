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

}

//         1
//    2          3
// 4     5    6     
//               7
//                  8
