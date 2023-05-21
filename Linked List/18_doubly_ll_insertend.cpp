#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        data=d;
        next=prev=NULL;
    }
};

Node *insertend(Node *head, int x)
{
    Node *temp=new Node(x);
    if (head==NULL)
        return temp;
    Node *curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=temp;
    temp->next=NULL;
    temp->prev=curr;
    return head;
    
}

int main()
{
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->prev=head;
    head->next->next=new Node(30);
    head->next->next->prev=head->next;

    Node *curr=head;
    while (curr != NULL)
    {
        cout<<(curr->data)<<" ";
        curr=curr->next;
    }
    cout<<endl;
    head=insertend(head,40);
    Node *cur=head;
    while (cur != NULL)
    {
        cout<<(cur->data)<<" ";
        cur=cur->next;
    }
    cout<<endl;
    return 0;
}