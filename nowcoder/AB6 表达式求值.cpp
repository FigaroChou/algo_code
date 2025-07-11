#include <iostream>
#include "../header.h"

class Solution {
public:
    Solution() {
        _map.insert({'-', 1});
        _map.insert({'+', 1});
        _map.insert({'*', 2});
    }

    void calc(stack<int>& numbers, stack<char>& ops) {
        if (numbers.empty() || numbers.size() < 2) return;
        if (ops.empty()) return;

        int right = numbers.top();
        numbers.pop();
        int left = numbers.top();
        numbers.pop();

        char op = ops.top();
        ops.pop();
        if (op == '+') numbers.push(left + right);
        else if (op == '-') numbers.push(left - right);
        else if (op == '*') numbers.push(left * right);
    }

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

        numbers.push(0);
        int size = s.size();
        for (int i = 0; i < size; ++i) {
            char c = s[i];
            if (c == '(') {
                ops.push(c);
            } else if (c == ')') {
                while (!ops.empty()) {
                    if (ops.top() != '(') {
                        calc(numbers, ops);
                    } else {
                        ops.pop();
                        break;
                    }
                }
            } else {
                // numbers
                int j = i;
                int number = 0;
                if (isdigit(c)) {
                    while (j < size && isdigit(s[j])) {
                        number = number * 10 + (s[j++] - '0');
                    }
                    numbers.push(number);
                    i = j - 1;
                } else {
                    if (i > 0 && (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-')) {
                        numbers.push(0);
                    }

                    while (!ops.empty() && ops.top() != '(') {
                        char prev = ops.top();
                        if (_map[prev] >= _map[c]) {
                            calc(numbers, ops);
                        } else {
                            break;
                        }
                    }
                    ops.push(c);
                }
            }
        }

        // 计算剩余的内容
        while (!ops.empty() && ops.top() != '(') {
            calc(numbers, ops);
        }

        return numbers.top();
    }
private:
    map<char, int> _map;
};

int main() {
    Solution s;
    cout << s.solve("(2*(3-4))*5") << "\n";
    return 0;
}