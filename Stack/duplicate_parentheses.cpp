#include <iostream>
#include <stack>
#include <string>
using namespace std;

/**
 * Returns true if the given expression does NOT contain duplicate parentheses.
 *
 * A duplicate (or empty) pair of parentheses is detected when a closing
 * parenthesis ')' immediately follows an opening parenthesis '(' on the stack.
 *
 * @param expr The expression to inspect.
 * @return false if duplicate parentheses are found, true otherwise.
 */
bool hasDuplicateParentheses(const string& expr) {
    if (expr.empty()) {
        return true;
    }

    auto isEmptyPair = [](const stack<char>& s) -> bool {
        return !s.empty() && s.top() == '(';
    };

    auto popUntilOpeningParenthesis = [](stack<char>& s) {
        while (!s.empty() && s.top() != '(') {
            s.pop();
        }
        if (!s.empty()) {
            s.pop();  // Remove the matching '('.
        }
    };

    stack<char> s;

    for (char ch : expr) {
        if (ch == ')') {
            if (isEmptyPair(s)) {
                return false;
            }
            popUntilOpeningParenthesis(s);
        } else {
            s.push(ch);
        }
    }

    return true;
}

int main() {
    string str = "((a+b))";

    cout << hasDuplicateParentheses(str);
    return 0;
}