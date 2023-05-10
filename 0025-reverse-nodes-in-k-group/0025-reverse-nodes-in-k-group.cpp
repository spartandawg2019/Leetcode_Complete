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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // edge case
        if (k <= 1 || !head) return head;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        
        int count = 0;
        for (ListNode* curr = head; curr; curr = curr->next)
            count++;
        
        while (count >= k) {
            ListNode* curr = prev->next;
            for (int i = 1; i < k; i++) {
                ListNode* temp = curr->next;
                curr->next = temp->next;
                temp->next = prev->next;
                prev->next = temp;
            }
            prev = curr;
            count -= k;
        }
        
        return dummy->next;
    }
    
};
