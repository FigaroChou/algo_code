#include <iostream>
#include "../header.h"

using namespace std;

class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         * 
         * @param tokens string字符串vector 
         * @return int整型
         */
        int evalRPN(vector<string>& tokens) {
            stack<int> opValues;
            for (string val : tokens) {
                if (val == "+" || val == "-" || val == "*" || val == "/") {
                    int right = opValues.top();
                    opValues.pop();
                    int left = opValues.top();
                    opValues.pop();
                    if (val == "+") opValues.push(left + right);
                    else if (val == "-") opValues.push(left - right);
                    else if (val == "*") opValues.push(left * right);
                    else if (val == "/") opValues.push(left / right);
                }else {
                    opValues.push(std::stoi(val));
                }
            }

            return opValues.top();
        }
};