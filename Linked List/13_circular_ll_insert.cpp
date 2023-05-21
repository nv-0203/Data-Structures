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

Node *insert_beg(Node *head, int x)
{
    Node *p;
    int temp;
    p=new Node(x);
    if (head==NULL)
        head=p;
    else 
    {

        p->next=head->next;
        head->next=p;
        temp=p->data;
        p->data=head->data;
        head->data=temp;
    }
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
    cout<<endl;
    head=insert_beg(head,55);
    printlist(head);
    return 0;
}