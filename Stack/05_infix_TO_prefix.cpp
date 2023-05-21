#include <iostream>
#include <string>
#include <algorithm>
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

string infixtoprefix(string s)
{
    string res;
    reverse(s.begin(), s.end());

    stack<char> stk;

    for (int i=0; i<s.length(); i++)
    {
        if (s[i]=='(')
            s[i]=')';
        else if (s[i]==')')
            s[i]='(';
        

        if (s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
            res+=s[i];
        else if (s[i]=='(')
            stk.push(s[i]);
        else if (s[i]==')')
        {
            while(!stk.empty() && stk.top()!='(')
            {
                res+=stk.top();
                stk.pop();
            }
            if (!stk.empty())
                stk.pop();
        }
        else
        {
            while(!stk.empty() && prec(stk.top())>prec(s[i]))
            {
                res+=stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        }
    }
    while(!stk.empty())
    {
        res+=stk.top();
        stk.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    cout<<infixtoprefix("(a-b/c)*(a/k-l)");
}