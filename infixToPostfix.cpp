#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;

int precisionCalc(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string chk)
{
    Stack<char> st;
    string result;

    for (int i = 0; i < chk.length(); i++)
    {
        if (chk[i] >= '0' && chk[i] <= '9')
        {
            result += chk[i];
        }
        else if (chk[i] == '(')
        {
            st.Push(chk[i]);
        }
        else if (chk[i] == ')')
        {
            while (!st.Empty() && st.Top() != '(')
            {
                result += st.Pop();
            }
            if (!st.Empty())
                st.Pop();
        }
        else
        {
            while (!st.Empty() && precisionCalc(st.Top()) >= precisionCalc(chk[i]))
            {
                result += st.Pop();
            }
            st.Push(chk[i]);
        }
    }

    while (!st.Empty())
    {
        result += st.Pop();
    }
    return result;
}

int postfixEvaluation(string chk)
{
    Stack<int> st;
    for (int i = 0; i < chk.length(); i++)
    {
        if (chk[i] >= '0' && chk[i] <= '9') // Check 0 to 9 operand
        {
            st.Push(chk[i] - '0');
        }
        else
        {
            int a = st.Pop();
            int b = st.Pop();
            if (a < b)
            {
                int temp = a;
                a = b;
                b = temp;
            }
            switch (chk[i])
            {
            case '+':
                st.Push(a + b);
                break;
            case '-':
                st.Push(a - b);
                break;
            case '*':
                st.Push(a * b);
                break;
            case '/':
                st.Push(a / b);
                break;
            case '^':
                st.Push(pow(a, b));
                break;

            default:
                break;
            }
        }
    }
    return st.Top();
}

int main()
{
    string infix = "(4*(3+5))-(2+0)";
    string postfix;
    postfix = infixToPostfix(infix);
    cout << endl
         << postfix << endl
         << postfixEvaluation(postfix) << endl
         << endl;
    return 0;
}