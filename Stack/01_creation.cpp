#include <iostream>
using namespace std;

#define n 100
class stack{
    int *arr;
    int top;

    public:
    stack()
    {
        top=-1;
        arr=new int[n];
    }

    void push(int x)
    {
        if (top==n-1)
        {
            cout<<"Stack overflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }

    void pop()
    {
        if (top==-1)
        {
            cout<<"No element present to be popped"<<endl;
            return;
        }
        top--;
    }

    int Top()
    {
        if (top==-1)
        {
            cout<<"No element present in stack"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool empty()
    {
        return top==-1;
    }
};

int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    while (s.empty()==false)
    {
        cout<<s.Top()<<" ";
        s.pop();
    }
}