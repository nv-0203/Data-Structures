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

void printlist(Node *head)
{
    Node *curr;
    if (head==NULL)
        return;
    else 
    {
        cout<<(head->data)<<" ";
        for (curr=head->next; curr!=head; curr=curr->next)
        {
            cout<<(curr->data)<<" ";
        }
    }
    cout<<endl;
}

Node *delete_k(Node *head, int k)
{
    if (head==NULL)
        return NULL;
    Node *curr=head;
    Node *temp;
    for (int i=1; i<(k-1) && curr !=NULL; i++)
    {
        curr=curr->next;
    }
    temp=curr->next;
    curr->next=curr->next->next;
    delete(temp);
    return head;
    
}


int main()
{
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    head -> next -> next -> next -> next= new Node(50);
    head -> next -> next -> next -> next -> next= new Node(60);
    head -> next -> next -> next -> next -> next -> next = head;

    printlist(head);
    head=delete_k(head,4);
    printlist(head);
    return 0;
}