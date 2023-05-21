#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};

Node* insertbeg(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next=head;
    if (head!=NULL)
        head->prev=temp;
    return temp;
}

Node *reverse_dll(Node *head)
{
    if (head==NULL || head->next==NULL)
        return head;
    Node *temp=head;
    Node *p=NULL;
    while(temp!=NULL)
    {
        p=temp->prev;
        temp->prev=temp->next;
        temp->next=p;

        temp=temp->prev;
    }
    return p->prev;
}

Node *delhead(Node *head)
{
    if (head==NULL)
        return NULL;
    if (head->next==NULL)
    {
        delete head;
        return NULL;
    }
    Node *temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;
    return temp;
}

void deleteNode(Node *head, int x)
{
    int pos=1;
    if (head->data == x)
    {
        cout<<pos<<" ";
        return;
    }
    Node *curr=head;
    while (curr->data != x)
    {
        curr=curr->next;
        pos++;
    }
    Node *temp2=curr->next;
    Node *temp1=curr->prev;
    temp1->next=temp2;
    temp2->prev=temp1;

    delete curr;
    
    cout<<pos<<" ";

    Node *temp = new Node(x);
    temp->next=head;
    head->prev=temp;
    head = temp;
}

Node *delNode(Node *head, int x)
{
    int pos=1;
    if (head->data == x)
    {
        cout<<pos<<" ";
        return head;
    }
    Node *curr=head;
    while (curr->data != x)
    {
        curr=curr->next;
        pos++;
    }
    Node *temp2=curr->next;
    Node *temp1=curr->prev;
    temp1->next=temp2;
    temp2->prev=temp1;

    delete curr;
    
    cout<<pos<<" ";

    Node *temp = new Node(x);
    temp->next=head;
    head->prev=temp;
    return temp;
}

int main()
{
    Node *head = new Node(1);
    head = insertbeg(head, 3);
    head = insertbeg(head, 3);
    head = insertbeg(head, 4);
    head = insertbeg(head, 1);
    head = insertbeg(head, 1);
    head = insertbeg(head, 2);

    head = delNode(head, 3);

    head = delNode(head, 2);

    head = delNode(head, 1);

    head = delNode(head, 1);

    head = delNode(head, 4);

    return 0;


}