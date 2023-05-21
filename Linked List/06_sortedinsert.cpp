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

Node *sortedinsert(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head==NULL)
        return temp;
    if (x < head->data)
    {
        temp->next=head;
        return temp;
    }
    Node *curr = head;
    while (((curr->next)->data)<x && curr->next != NULL)
        curr=curr->next;

    temp->next = curr->next;
    curr->next = temp;

    return head;
}

int main()
{
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);

    head=sortedinsert(head, 22);
    
    Node *curr=head;
    while (curr != NULL)
    {
        cout<<(curr->data)<<" ";
        curr=curr->next;
    }

    return 0;
}
