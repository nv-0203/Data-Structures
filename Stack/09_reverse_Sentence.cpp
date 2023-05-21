#include <iostream>
#include <stack>
#include <string>
using namespace std;

void ResverseSentence(string s)
{
    stack<string> stk;
    
    for (int i=0; i<s.length(); i++)
    {
        string word=" ";
        while(s[i] !=' ' && i < s.length())
        {
            word+=s[i];
            i++;
        }
        stk.push(word);
    }

    while (stk.empty()==false)
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }

}

int main()
{
    string s;
    s="my name is nufail";
    ResverseSentence(s);
}