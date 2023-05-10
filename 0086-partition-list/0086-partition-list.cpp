/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummyLess = new ListNode(-1);
        ListNode *dummyGreater = new ListNode(-1);
        ListNode *pLess = dummyLess, *pGreater = dummyGreater;
        while (head != nullptr) {
            if (head->val < x) {
                pLess->next = head;
                pLess = pLess->next;
            } else {
                pGreater->next = head;
                pGreater = pGreater->next;
            }
            head = head->next;
        }
        pLess->next = dummyGreater->next;
        pGreater->next = nullptr;
        return dummyLess->next;
    }
};
