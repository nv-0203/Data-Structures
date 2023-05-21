#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 

bool isCircular(Node *head)
{
    Node *first=head;
    Node *second=head;
    
    while (second!=NULL)
    {
        second=second->next->next;
        first=first->next;
        
        if (first==second)
            return true;
    }
    
    return false;
}

int main()
{
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    head -> next -> next -> next -> next= new Node(50);
    head -> next -> next -> next -> next -> next= new Node(60);
    head -> next -> next -> next -> next -> next -> next = NULL;

    cout<<isCircular(head);
    return 0;
}