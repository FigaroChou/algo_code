#include <iostream>
#include "../header.h"

class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         * 返回表达式的值
         * @param s string字符串 待计算的表达式
         * @return int整型
         */
        int solve(string s) {
            stack<int> numbers;
            stack<char> ops;

            for (int i = 0; i < s.size();) {
                char c = s[i];
                if (c == '+' || c == '-' || c == '*') {
                    ops.push(c);
                } else if (c == '}' || c == ')' || c == ']') {
                    int right = numbers.top();
                    numbers.pop();
                    int left = numbers.top();
                    numbers.pop();
                                        
                    char op = ops.top();
                    ops.pop();
                    if (op == '+') numbers.push(left + right);
                    else if (op == '-') numbers.push(left - right);
                    else if (op == '*') numbers.push(left * right);
                } else if (isdigit(c)){
                    int number = (c - '0');
                    while (++i < s.size() && isdigit(s[i])) {
                        number *= 10;
                        number += (s[i] - '0');
                    }
                    numbers.push(number);
                    continue;
                }
                ++i;
            }

            while (!ops.empty()) {
                char op = ops.top();
                ops.pop();

                int right = numbers.top();
                numbers.pop();
                int left = numbers.top();
                numbers.pop();

                if (op == '+') numbers.push(left + right);
                else if (op == '-') numbers.push(left - right);
                else if (op == '*') numbers.push(left * right);
            }

            return numbers.top();
        }
};

int main() {
    Solution s;
    cout << s.solve("(2*(3-4))*5") << "\n";
    return 0;
}