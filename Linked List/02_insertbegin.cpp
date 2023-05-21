#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
};

Node *insertbegin(Node *head, int x)
{
    Node *temp = new Node(x);
    temp -> next = head;
    return temp;
}

int main()
{
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    
    head=insertbegin(head, 100);

    Node *curr=head;
    while (curr != NULL)
    {
        cout<<(curr->data)<<" ";
        curr=curr->next;
    }

    return 0;
}