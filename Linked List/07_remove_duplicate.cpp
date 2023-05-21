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

void remove_duplicate(Node *head)
{
    Node *curr;
    Node *temp;
    curr=head;
    
    while (curr->next != NULL && curr != NULL)
    {
        if (curr->data == curr->next->data)
        {
            temp=curr->next;
            curr->next = curr->next->next;
            delete(temp);
        }
        else
            curr=curr->next;
    }
}

int main()
{
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(20);
    head -> next -> next -> next = new Node(30);
    head -> next -> next -> next -> next= new Node(30);
    head -> next -> next -> next -> next -> next= new Node(40);
    
    Node *currp=head;
    while (currp != NULL)
    {
        cout<<(currp->data)<<" ";
        currp=currp->next;
    }
    cout<<endl;

    remove_duplicate(head);
    Node *cur=head;
    while (cur != NULL)
    {
        cout<<(cur->data)<<" ";
        cur=cur->next;
    }
    cout<<endl;
    return 0;
}