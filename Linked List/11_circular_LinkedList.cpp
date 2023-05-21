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
    Node *temp;
    if (head==NULL)
        return;
    else 
    {
        cout<<(head->data)<<" ";
        for (temp=head->next; temp!=head; temp=temp->next)
        {
            cout<<(temp->data)<<" ";
        }
    }
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
    return 0;
}