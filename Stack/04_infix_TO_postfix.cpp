#include <iostream>
#include <string>
#include <stack>
using namespace std;

int prec(char c)
{
    if (c=='^')
        return 3;
    else if (c=='/' || c=='*')
        return 2;
    else if (c=='+' || c=='-')
        return 1;
    else 
        return -1;
}

string infixtopostfix(string s)
{
    stack<char> stk;
    string ans;
    for (int i=0; i<s.length(); i++)
    {
        if (s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
        {
            ans+=s[i];
        }
        else if (s[i] == '(')
        {
            stk.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while(!stk.empty() && stk.top()!='(')
            {
                ans+=stk.top();
                stk.pop();
            }
            if (!stk.empty())
                stk.pop();
        }
        else if(s[i]=='^' || s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-')
        {
            while(!stk.empty() && prec(stk.top())>prec(s[i]))
            {
                ans+=stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        }

    }
    while (stk.empty()==false)
    {
        ans+=stk.top();
        stk.pop();
    }
    return ans;
}

int main()
{
    cout<<infixtopostfix("(a-b/c)*(a/k-l)");
    
}