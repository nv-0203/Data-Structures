#include <iostream>
#include <stack>
#include <string>
#include <math.h>

using namespace std;

int prefix(string s)
{
    stack <int> stk;
    int op1;
    int op2;

    for (int i=s.length()-1; i>=0; i--)
    {
        if( s[i]>='0' && s[i]<='9')
        {
            stk.push(s[i]-'0');
        }
        else
        {
            op1=stk.top();
            stk.pop();
            op2=stk.top();
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
    
    cout<<prefix("-+7*45+20");
    return 0;

}
