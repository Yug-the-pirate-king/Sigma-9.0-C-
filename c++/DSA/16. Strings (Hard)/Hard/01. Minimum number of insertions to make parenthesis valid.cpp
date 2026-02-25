/*
QUESTION:
A parentheses string is valid if and only if:
- It is the empty string,
- It can be written as AB (A concatenated with B), where A and B are valid strings, or
- It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
Return the minimum number of moves required to make s valid.

Example:

Input: s = "())"
Output: 1

Approach:
- We can keep track of the balance of parentheses using two variables: open and close.
- Traverse through the string, and for each character:
  - If it's an opening parenthesis '(', increment the open count.
  - If it's a closing parenthesis ')':
    - If there are open parentheses available (open > 0), decrement the open count.
    - Otherwise, increment the close count.
- The total number of moves required to make the string valid would be equal to open + close.

Complexity Analysis:
- The solution traverses the input string once, so the time complexity is O(n), where n is the length of the string.
- The space complexity is O(1) as we are using only two extra variables.

CODE:
*/

int minAddToMakeValid(string s) {
    int open = 0, close = 0;
    for(char c : s) {
        if(c == '(') {
            open++;
        } else {
            if(open > 0) {
                open--; // balance it with an open parenthesis
            } else {
                close++;
            }
        }
    }
    return open + close; // total moves required
}
