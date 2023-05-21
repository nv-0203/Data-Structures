#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
};

void printlist(Node *head)
{
    if (head==NULL)
        return;
    Node *curr=head;
    cout<<curr->data;
    while(curr!=head)
    {
        curr=curr->next;
        cout<<curr->data<<" ";
    }
    
}

Node *insertbeg(Node *head, int x)
{
    Node *curr=new Node(x);
    int temp;
    if (head==NULL)
    {
        head=curr;
        head->next=head;
    }
    else
    {
        curr->next=head->next;
        head->next=curr;
        temp=head->data;
        head->data=curr->data;
        curr->data=temp;
    }
    return head;
    
}

Node *delete_head(Node *head)
{
    if (head==NULL)
        return NULL;
    if (head->next==NULL)
    {
        delete head;
        return NULL;
    }
    Node *temp=head->next;
    head->data=temp->data;
    head->next=head->next->next;
    delete temp;
    return head;
}

int main()
{
    
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=head;
    printlist(head);
    return 0;
}