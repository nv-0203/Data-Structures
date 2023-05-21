#include <iostream>
using namespace std;

class Node
{
    public:
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
    Node *curr=head;
    while(curr != NULL)
    {
        cout<<(curr->data)<<" ";
        curr=curr->next;
    }
}

void rprint(Node *head)
{
    if (head==NULL)
        return;
    cout<<(head->data)<<" ";
    rprint(head->next);
}

int searchll(Node *head, int x)
{
    int pos=1;
    Node *curr=head;
    while(curr!=NULL)
    {
        if(curr->data==x)
            return pos;
        else 
        {
            pos++;
            curr=curr->next;
        }
    }
    return -1;
}

Node *insertbegin(Node *head, int x)
{
    Node *temp=new Node(x);
    temp->next=head;
    return temp;
}

Node *insertend(Node *head, int x)
{
    Node *temp=new Node(x);
    if (head==NULL)
        return temp;
    Node *curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    return head;
}

Node *delhead(Node *head)
{
    if (head==NULL)
        return NULL;
    Node *temp=head->next;
    delete head;
    return temp;
}

Node *delend(Node *head)
{
    if (head==NULL)
        return NULL;
    else if(head->next=NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        Node *curr=head;
        while (curr->next->next!=NULL)
        {
            curr=curr->next;
        }
        delete (curr->next);
        curr->next=NULL;
        return head;

    }
}

Node *insertpos(Node *head, int pos, int data)
{
    Node *temp=new Node(data);
    Node *curr=head;
    for (int i=1; i<pos-1 && curr!=NULL; i++)
    {
        curr=curr->next;
    }
    if (curr==NULL)
        return head;
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

Node *sortedinsert(Node *head, int x)
{
    Node *temp=new Node(x);
    Node *curr=head;
    while(curr->next->data < temp->data && curr->next!=NULL)
    {
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

void printmiddle(Node *head)
{
    int n=1;
    Node *curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
        n++;
    }
    Node *temp=head;
    for (int i=1; i<=n/2; i++)
    {
        temp=temp->next;
    }
    cout<<temp->data;
}

void printnthend(Node *head, int n)
{
    Node *curr=head;
    int len=1;
    while(curr->next!=NULL)
    {
        curr=curr->next;
        n++;
    }
    curr=head;
    for(int i=1; i<=(len-n); i++)
    {
        curr=curr->next;
    }
    cout<<curr->data;
}

void printnend(Node *head, int n)
{
    Node *first=head;
    for(int i=0; i<n; i++)
    {
        if (first==NULL)
            return;
        first=first->next;
    }
    Node *second = head;
    while(first!=NULL)
    {
        first=first->next;
        second=second->next;
    }
    cout<<(second->data);
}

Node *reverse(Node *head)
{
    Node *prev=NULL;
    Node *curr=head;
    Node *after;

    while(curr!=NULL)
    {
        after=curr->next;
        curr->next=prev;
        prev=curr;
        curr=after;
    }
    return prev;
}

Node *recursiverev(Node *head)
{
    if (head==NULL)
        return NULL;
    if (head->next==NULL)
        return head;

    Node *rest_head=recursiverev(head->next);
    Node *rest_tail=head->next;
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;
}

Node *remove_duplicate(Node *head)
{
    Node *curr=head;
    Node *temp;
    while(curr!=NULL)
    {
        if (curr->data == curr->next->data)
        {
            temp=curr->next;
            curr->next=curr->next->next;
            delete temp;
        }
        else
            curr=curr->next;
    }
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next -> next = new Node(20);
    head->next -> next -> next = new Node(20);
    printlist(head);
    return 0;
}