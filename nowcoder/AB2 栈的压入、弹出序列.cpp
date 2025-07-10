#include <iostream>
#include "../header.h"

using namespace std;


class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         * 
         * @param pushV int整型vector 
         * @param popV int整型vector 
         * @return bool布尔型
         */
        bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
            stack<int> stack;
            
            int j = 0;
            for (int i = 0; i < pushV.size(); i++) {
                while (j < pushV.size() && stack.empty() || stack.top() != popV[i]) {
                    stack.push(pushV[j++]);
                }

                if (stack.top() == popV[i]) {
                    stack.pop();
                } else {
                    return false;
                }
            }
            return true;
        }
};