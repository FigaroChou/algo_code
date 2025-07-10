#include <iostream>
#include "../header.h"

using namespace std;

class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         * 
         * @param s string字符串 
         * @return bool布尔型
         */
        bool isValid(string s) {
            if (s.size() <= 1) {
                return false;
            }

            stack<int> stack;
            for (auto c : s) {
                // push
                if (c == '(') {
                    stack.push(')');
                } else if (c == '{') {
                    stack.push('}');
                } else if (c == '[') {
                    stack.push(']');
                }

                // pop
                if (c == ')' || c == '}' || c == ']') {
                    // 右括号多了
                    if (stack.empty() || c != stack.top()) {
                        return false;
                    }
                    stack.pop();
                }
            }

            // 左括号多了
            return stack.size() == 0;
        }
};
