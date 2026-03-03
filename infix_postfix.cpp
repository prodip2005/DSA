#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

int precedence(char op)
{
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int applyOperator(int a, int b, char op)
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '^') return pow(a, b);
    return 0;
}

string infixToPrefix(string infix)
{
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (isdigit(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
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
            while (!st.empty() && precedence(st.top()) > precedence(ch))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int evaluatePrefix(string prefix)
{
    stack<int> st;

    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        if (isdigit(ch))
        {
            st.push(ch - '0');
        }
        else
        {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            int result = applyOperator(a, b, ch);
            st.push(result);
        }
    }

    return st.top();
}

int main()
{
    string infix;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);

    cout << "Prefix Expression: " << prefix << endl;

    int result = evaluatePrefix(prefix);

    cout << "Final Result: " << result << endl;

    return 0;
}
