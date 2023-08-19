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

    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

void iterative_preorder(Node *root)
{
    stack<Node *> stk;
    if (root == NULL)
        return;
    stk.push(root);
    while (!stk.empty())
    {
        Node *curr = stk.top();
        stk.pop();
        cout << (curr->key) << " ";
        if (curr->right != NULL)
            stk.push(curr->right);
        if (curr->left != NULL)
            stk.push(curr->left);
    }
}

void iterative_preorder1(Node *root) // space optimized solution
{
    stack<Node *> stk;
    if (root == NULL)
        return;
    stk.push(root);
    Node *curr = root;
    while (curr != NULL && !stk.empty())
    {
        while (curr != NULL)
        {
            cout << (curr->key) << " ";
            if (curr->right != NULL)
                stk.push(curr->right);
            curr = curr->left;
        }
        if (!stk.empty())
        {
            curr = stk.top();
            stk.pop();
        }
    }
}

void iterative_inorder(Node *root)
{
    stack<Node *> stk;
    if (root == NULL)
        return;

    Node *curr = root;
    while (true)
    {
        if (curr != NULL)
        {
            stk.push(curr);
            curr = curr->left;
        }
        else
        {
            if (stk.empty())
                break;
            curr = stk.top();
            stk.pop();
            cout << (curr->key) << " ";
            curr = curr->right;
        }
    }
}

void iterative_postorder2(Node *root)   //using 2 stacks
{
    stack<Node*> stk1;
    stack<Node*> stk2;
    if (root == NULL)
        return;
    Node *curr = root;
    stk1.push(root);
    while (!stk1.empty())
    {
        curr=stk1.top();
        stk1.pop();
        stk2.push(curr);
        if (curr->left!=NULL)
            stk1.push(curr->left);
        if (curr->right!=NULL)
            stk1.push(curr->right);
    }
    while (!stk2.empty())
    {
        cout<<(stk2.top()->key)<<" ";
        stk2.pop();
    }
}

void iterative_postorder1(Node *root)   //using 1 stack
{
    Node *curr = root;
    if (root == NULL)
        return;
    stack<Node*> stk;
    while (curr != NULL || !stk.empty())
    {
        if (curr != NULL)
        {
            stk.push(curr);
            curr=curr->left;
        }
        else if (curr == NULL)
        {
            Node *temp = stk.top() -> right;
            if (temp == NULL)
            {
                temp = stk.top();
                stk.pop();
                cout<< (temp->key) << " ";

                while (!stk.empty() && temp == stk.top()->right)
                {
                    temp = stk.top();
                    stk.pop();
                    cout<< (temp -> key)<<" ";
                }
            }
            else
                curr = temp;
        }
    }
}

void all_in_one(Node *root)
{
    if (root == NULL)
        return;
    
    stack<pair<Node*, int>> stk;
    stk.push({root, 1});

    vector<int> preorder, inorder, postorder;
    
    while (!stk.empty())
    {
        auto it = stk.top();
        stk.pop();

        if (it.second == 1)
        {
            preorder.push_back(it.first -> key);
            it.second++;
            stk.push(it);

            if (it.first -> left != NULL)
                stk.push({it.first->left, 1});
        }

        else if (it.second == 2)
        {
            inorder.push_back(it.first->key);
            it.second++;
            stk.push(it);

            if (it.first -> right != NULL)
                stk.push({it.first->right, 1});
        }

        // don't push it again
        else if (it.second == 3)
        {
            postorder.push_back(it.first->key);
        }
    }

    cout<<"Preorder: ";
    for (int i=0; i<preorder.size(); i++)
    {
        cout<<preorder[i]<<" ";
    }
    cout<<endl;

    cout<<"Inorder: ";
    for (int i=0; i<inorder.size(); i++)
    {
        cout<<inorder[i]<<" ";
    }
    cout<<endl;

    cout<<"Postorder: ";
    for (int i=0; i<postorder.size(); i++)
    {
        cout<<postorder[i]<<" ";
    }
    cout<<endl;
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
    cout<<"Peorder: "<<endl;
    iterative_preorder(root);
    cout << endl;
    iterative_preorder1(root);
    cout << endl;
    cout<<"Inorder: "<<endl;
    iterative_inorder(root);
    cout<<endl;
    cout<<"Postorder: "<<endl;
    iterative_postorder2(root);
    cout<<endl;
    iterative_postorder2(root);
    cout<<endl;
    all_in_one(root);
}

//         1
//    2          3
// 4     5    6     
//               7
//                  8