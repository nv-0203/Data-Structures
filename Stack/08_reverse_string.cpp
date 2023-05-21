#include <iostream>
using namespace std;

#define n 100
class stack
{
    int *arr;
    int top;
    public:
    stack()
    {
        arr=new int[n];
        top=-1;
    }

    void push(int x);
    void pop();
    int Top();
    bool isempty();
};

void stack::push (int x)
{
    if (top==n-1)
    {
        cout<<"Stack Overflow";
        return;
    }
    top++;
    arr[top]=x;
}

void stack::pop()
{
    if (top==-1)
    {
        cout<<"Stack Underflow";
        return;
    }
    top--;
}

int stack::Top()
{
    if (top==-1)
    {
        cout<<"Stack is Empty";
        return INT_MIN;
    }
    return arr[top];
}

bool stack::isempty()
{
    return top==-1;
}

void ReverseString(string s)
{
    stack stk;
    for(int i=0; i<s.length(); i++)
    {
        stk.push(s[i]);
    }
    string word="";
    for (int i=0; i<s.length(); i++)
    {
        word+=stk.Top();
        stk.pop();
    }
    cout<<word;
}



int main()
{
    ReverseString("nufail");
    return 0;
}