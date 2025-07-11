struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead1 ListNode类 
     * @param pHead2 ListNode类 
     * @return ListNode类
     */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (pHead1 != nullptr && pHead2 != nullptr) {
            if (pHead1->val > pHead2->val) {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            } else {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            }

            cur = cur->next;
        }

        cur->next = pHead1 ? pHead1 : pHead2;

        return dummy->next;
    }
};