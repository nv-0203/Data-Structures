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

Node *insertend(Node *head, int x)
{
    Node *curr=head;
    while (curr->next != NULL)
        curr=curr->next;
    Node *temp = new Node(x);
    if (head==NULL)
        return temp;
    curr->next=temp;
    return head;
}

int main()
{
    Node *head = new Node(10);
    head=insertend(head,45);
    head=insertend(head, 22);

    Node *cur = head;
    while (cur != NULL)
    {
        cout<<(cur->data)<<" ";
        cur=cur->next;
    }
    return 0;
}