#include <iostream>
#include <stack>
#include <math.h>
#include <string>

using namespace std;

int postfix(string s)
{
    int op1, op2;
    stack<int> stk;
    for(int i=0; i<s.length(); i++)
    {
        if (s[i]>='0' && s[i]<='9')
        {    
            stk.push(s[i]-'0');
        }
        else
        {
            op2=stk.top();
            stk.pop();
            op1=stk.top();
            stk.pop();

            switch(s[i])
            {
                case '+':
                    stk.push(op1+op2);
                    break;
                case '-':
                    stk.push(op1-op2);
                    break;
                case '*':
                    stk.push(op1*op2);
                    break;
                case '/':
                    stk.push(op1/op2);
                    break;
            }
        }

    }
    return stk.top();
    
}
 
int main()
{
    cout<<postfix("46+2/5*7+");
}