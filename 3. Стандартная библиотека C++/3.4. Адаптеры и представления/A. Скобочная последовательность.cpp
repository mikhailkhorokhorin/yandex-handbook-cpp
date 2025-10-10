#include <iostream>
#include <stack>

bool matches(char open, char close) {
    return (open == '(' && close == ')') || (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int main() {
    std::string str;
    std::cin >> str;

    std::stack<char> st;

    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty() || !matches(st.top(), c)) {
                std::cout << "NO" << std::endl;
                return 0;
            }
            st.pop();
        }
    }

    std::cout << (st.empty() ? "YES" : "NO") << std::endl;
}
