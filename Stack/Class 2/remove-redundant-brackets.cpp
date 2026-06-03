#include <iostream>
#include <stack>
using namespace std;

bool hasRedundantBrackets(string expr)
{
    stack<char> st;

    for (char ch : expr)
    {
        // Push opening brackets and operators
        if (ch == '(' || ch == '+' || ch == '-' ||
            ch == '*' || ch == '/')
        {
            st.push(ch);
        }

        // When closing bracket is found
        else if (ch == ')')
        {
            bool hasOperator = false;

            while (!st.empty() && st.top() != '(')
            {
                char top = st.top();

                if (top == '+' || top == '-' ||
                    top == '*' || top == '/')
                {
                    hasOperator = true;
                }

                st.pop();
            }

            // Remove opening bracket
            if (!st.empty())
                st.pop();

            // No operator inside brackets
            if (!hasOperator)
                return true;
        }
    }

    return false;
}

int main()
{
    string expr = "((a+b))";

    if (hasRedundantBrackets(expr))
        cout << "Redundant Brackets Present";
    else
        cout << "No Redundant Brackets";

    return 0;
}