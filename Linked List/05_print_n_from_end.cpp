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
/* Method 1
void printnend(Node *head, int n)
{
    Node *curr=head;
    int len=1;
    while (curr->next != NULL)
    {
        len++;
        curr=curr->next;
    }

    if (len<n)
        return;
    curr=head;
    for (int i=1; i<(len-n+1); i++)
    {
        curr=curr->next;
    }
    cout<<len<<endl;
    cout<<(curr->data);
}
*/

//Metod 2
void printnend(Node *head, int n)
{
    Node *first=head;
    Node *second =head;
    for (int i=0; i<n; i++)
        first=first->next;
    
    while(first != NULL)
    {
        first=first->next;
        second=second->next;
    }
    cout<<(second->data);
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
    printnend(head,4);

    return 0;
}