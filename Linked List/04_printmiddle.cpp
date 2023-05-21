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

void printmiddle(Node *head)
{
    if (head == NULL)
        return;
    Node *curr=head;
    int count=1;
    while (curr->next != NULL)
    {
        count++;
        curr=curr->next;
    }
    Node *middle=head;

    for (int i=0; i<(count/2); i++)
    {
        middle=middle->next;
    }
    int mid=middle->data;
    cout<<mid;
}

int main()
{
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    
    Node *curr=head;
    while (curr != NULL)
    {
        cout<<(curr->data)<<" ";
        curr=curr->next;
    }
    cout<<endl;
    printmiddle(head);
    return 0;
}