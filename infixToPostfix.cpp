#include<iostream>
#include<stack>
#include<string>
using namespace std;


int prec(char c)
{
    if(c=='^')
      return 3;
    else if(c=='/'||c=='*')
      return 2;
    else if(c=='+'||c=='-')
      return 1;
    else
      return -1;
}

void inToPost(string s)
{
    stack<char> st;
    string post;

    int len=s.length();
    
    for(int i=0;i<len;i++)
    {
      char c = s[i];

      if((c>='a'&& c<='z')|| (c>='A' && c<='Z')||(c>='0' && c<='9'))
      {
          post+=c;
      }

      else if(c=='(')
      {
         st.push('(');
      }

      else if(c==')')
      {
        while(st.top()!='(')
        {
          post+=st.top();
          st.pop();
        }
        st.pop();
      }

      else
      {
        while(!st.empty() && prec(c)<=prec(st.top()))
        {
          post+=st.top();
          st.pop();
        }
        st.push(c);
      }

    }
    while(!st.empty())
      {
        post+=st.top();
        st.pop();
      }
      cout<<post<<endl;

}

int main()
{
    string infix="a+b*(c^d-e)^(f+g*h)-i";
    inToPost(infix);

    return 0;

}