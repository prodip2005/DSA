#include <iostream>
#include <stack>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int main()
{
    string infix;
    cout << "Enter infix: ";
    cin >> infix;

    stack<char> st;
    string postfix = "";

    for (char c : infix)
    {
        if (isalnum(c))
            postfix += c;

        else if (c == '(')
            st.push(c);

        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            while (!st.empty() && precedence(st.top()) >= precedence(c))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    cout << "Postfix: " << postfix;

    return 0;
}