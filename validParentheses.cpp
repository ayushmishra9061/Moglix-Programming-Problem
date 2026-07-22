#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int longestValidParentheses(string s)
{
    int left = 0, right = 0;
    int maxLength = 0;

    // Left to Right
    for (char c : s)
    {
        if (c == '(')
            left++;
        else
            right++;

        if (left == right)
            maxLength = max(maxLength, 2 * right);
        else if (right > left)
            left = right = 0;
    }

    left = right = 0;

    // Right to Left
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '(')
            left++;
        else
            right++;

        if (left == right)
            maxLength = max(maxLength, 2 * left);
        else if (left > right)
            left = right = 0;
    }

    return maxLength;
}

int main()
{
    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    cout << "Longest Valid Parentheses Length = "
         << longestValidParentheses(s);

    return 0;
}