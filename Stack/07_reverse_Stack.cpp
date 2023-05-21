#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int elt)
{
    if (st.empty())
    {
        st.push(elt);
        return;
    }
    int topelt=st.top();
    st.pop();
    insertAtBottom(st, elt);

    st.push(topelt);
}

void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int elt=st.top();
    st.pop();
    reverse(st);

    insertAtBottom(st, elt);

}

int main()
{
    stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverse(s);
    while(s.empty()==false)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}