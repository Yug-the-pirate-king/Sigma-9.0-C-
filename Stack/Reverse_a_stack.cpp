#include <iostream>
#include <stack>

/**
 * @brief Recursively inserts a value at the bottom of a stack.
 * @param s The stack to modify.
 * @param value The value to insert at the bottom.
 */
template <typename T>
void insert_at_bottom(std::stack<T>& s, T value) {
    if (s.empty()) {
        s.push(value);
        return;
    }

    T top = s.top();
    s.pop();
    insert_at_bottom(s, value);
    s.push(top);
}

/**
 * @brief Recursively reverses a stack in-place.
 * @param s The stack to reverse.
 */
template <typename T>
void reverse_stack(std::stack<T>& s) {
    if (s.empty()) {
        return;
    }

    T top = s.top();
    s.pop();
    reverse_stack(s);
    insert_at_bottom(s, top);
}

/**
 * @brief Prints a stack from top to bottom.
 * @param s A copy of the stack to print.
 *
 * The stack is passed by value so the caller's stack remains unchanged.
 */
template <typename T>
void print_stack(std::stack<T> s) {
    while (!s.empty()) {
        std::cout << s.top() << '\n';
        s.pop();
    }
}

int main() {
    std::stack<char> s;
    s.push('E');
    s.push('D');
    s.push('C');
    s.push('B');
    s.push('A');

    reverse_stack(s);
    print_stack(s);

    return 0;
}