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

Node *reverse_head(Node *head)
{
    if (head==NULL || head->next==NULL)
        return head;
    Node *temp=head;
    Node *p=NULL;
    while (temp != NULL)
    {
        p=temp->prev;
        temp->prev=temp->next;
        temp->next=p;

        temp=temp->prev;

    }
    return p->prev;
}

int main()
{
    Node *head=new Node(10);
    head->prev=NULL;
    head->next=new Node(20);
    head->next->prev=head;
    head->next->next=new Node(30);
    head->next->next->prev=head->next;
    head->next->next->next=NULL;

    Node *curr=head;
    while (curr != NULL)
    {
        cout<<(curr->data)<<" ";
        curr=curr->next;
    }
    cout<<endl;

    head=reverse_head(head);
    
    Node *cur=head;
    while (cur != NULL)
    {
        cout<<(cur->data)<<" ";
        cur=cur->next;
    }
    cout<<endl;
    return 0;
}