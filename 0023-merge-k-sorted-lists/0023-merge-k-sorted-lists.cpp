class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr; // edge case: no lists to merge
        int k = lists.size();
        while (k > 1) {
            int i = 0;
            for (int j = 0; j < k; j += 2) {
                if (j + 1 < k) lists[i++] = mergeTwoLists(lists[j], lists[j + 1]);
                else lists[i++] = lists[j];
            }
            k = i;
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
