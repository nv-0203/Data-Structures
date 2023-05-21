#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

class queue
{
    Node *front;
    Node *back;
    public:
    queue()
    {
        front=NULL;
        back=NULL;
    }

    void enqueue(int x)
    {
        Node *n=new Node(x);
        if(front==NULL)
        {
            front=n;
            back=n;
            return;
        }
        back->next=n;
        back=n;
    }

    void dequeue()
    {
        if (front==NULL)
        {
            cout<<"No elements present in stack";
            return;
        }
        Node *todelete = front;
        front=front->next;
        delete todelete;
    }

    int peek()
    {
        if (front==NULL)
        {
            cout<<"No elements present in stack";
            return 0;
        }
        return front->data;
    }

    bool empty()
    {
        if (front==NULL)
            return true;
        return false;
    }
};

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    while(!q.empty())
    {
        cout<<q.peek()<<" ";
        q.dequeue();
    }
}