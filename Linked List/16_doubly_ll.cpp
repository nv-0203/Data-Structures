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
    
    return 0;
}