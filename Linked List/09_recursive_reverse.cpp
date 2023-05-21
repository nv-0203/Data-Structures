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

Node *recrev(Node *head)
{
    if (head==NULL)
        return NULL;
    if (head->next==NULL)
        return head;
    
    Node *rest_head=recrev(head->next);
    Node *rest_tail=head->next;
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;

}

int main()
{
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    head -> next -> next -> next -> next= new Node(50);
    head -> next -> next -> next -> next -> next= new Node(60);
    
    Node *curr=head;
    while (curr != NULL)
    {
        cout<<(curr->data)<<" ";
        curr=curr->next;
    }
    cout<<endl;
    head=recrev(head);
    Node *cur=head;
    while (cur != NULL)
    {
        cout<<(cur->data)<<" ";
        cur=cur->next;
    }
    return 0;
}