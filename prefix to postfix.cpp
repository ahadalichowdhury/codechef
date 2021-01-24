#include<iostream>
#include<sstream>
#include<stack>
using namespace std;

int precedence(char x)
{
    if (x=='^') return 3;
    else if(x=='/' || x=='*') return 2;
    else if (x=='+' || x=='-') return 1;
    else return -1;
}
void infixToPostfix( string s)
{
    int n= s.size();
    stack<char>st;
    for( int i=0; i<n; i++)
    {
        if ((s[i]>='a' && s[i]<='z')|| (s[i]>= 'A' && s[i]<='Z'))
        {
            cout<<" "<<s[i];
        }
        else if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                cout<< " "<< st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && precedence (s[i])<=precedence(st.top()))
            {
                cout<<st.top();
                st.pop();
            }
            st.push(s[i]);

        }

    }
    while(!st.empty ())
    {
        cout<<" "<<st.top();
        st.pop();

    }

}
int main()
{
    string s;
    cout<< "Enter an infix expression : " ;
    cin>>s ;
    cout<< "The equivalent postfix expression is :";
    infixToPostfix(s);
    return 0;
}
