#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {
    std::string str;
    cin >> str;

    stack<char> stack;
    for (auto c : str) {
        if (stack.empty() || c != stack.top()) {
            stack.push(c);
        } else if (c == stack.top()){
            stack.pop();
        }
    }

    if (stack.empty()) std::cout << 0 << std::endl;
    std::string res;
    while (!stack.empty()) {
        res = stack.top() + res;
        stack.pop();
    }

    std::cout << res << std::endl;

    return 0;
}
