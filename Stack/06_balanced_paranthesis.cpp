#include <iostream>
#include <stack>
#include <string>
using namespace std; 

string balancedParenthesis(string s)
{
    stack<char> stk;
    int flag=0;
    for (int i=0; i<s.length(); i++)
    {
        if (s[i]=='{' || s[i]=='(' || s[i]=='[')
            stk.push(s[i]);
        
        if (s[i]=='}')
        {
            if (!stk.empty() && stk.top()=='{')
            {
                stk.pop();
                continue;
            }
            else if (stk.top()=='[' || stk.top()=='(')
            {
                flag=1;
                break;
            }
        }

        else if (s[i]==']')
        {
            if (!stk.empty() && stk.top()=='[')
            {
                stk.pop();
                continue;
            }
            else if (stk.top()=='{' || stk.top()=='(')
            {
                flag=1;
                break;
            }
        }

        else if (s[i]==')')
        {
            if (!stk.empty() && stk.top()=='(')
            {
                stk.pop();
                continue;
            }
            else if (stk.top()=='[' || stk.top()=='{')
            {
                flag=1;
                break;
            }
        }
    }
    if (flag==0)
        return "VALID STRING";
    else
        return "INVALIDE STRING";
}

int main()
{
    cout<<balancedParenthesis("{abcd[efg(i)]}");
    return 0;
}