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
    int pairSum(ListNode* head) {
        vector<int> values;
        ListNode* curr = head;
        while (curr != nullptr) {
            values.push_back(curr->val);
            curr = curr->next;
        }
        int n = values.size();
        int max_sum = 0;
        for (int i = 0; i < n / 2; i++) {
            int sum = values[i] + values[n - 1 - i];
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};
