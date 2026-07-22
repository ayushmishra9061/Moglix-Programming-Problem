#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
                return false;

            if (c == ')' && st.top() != '(')
                return false;

            if (c == ']' && st.top() != '[')
                return false;

            if (c == '}' && st.top() != '{')
                return false;

            st.pop();
        }
    }

    return st.empty();
}

int main()
{
    string s;

    cout << "Enter the string: ";
    cin >> s;

    if (isValid(s))
        cout << "Valid Parentheses" << endl;
    else
        cout << "Invalid Parentheses" << endl;

    return 0;
}