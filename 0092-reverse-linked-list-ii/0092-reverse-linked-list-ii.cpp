class Solution {
public:
ListNode* reverseBetween(ListNode* head, int left, int right) {
if (!head) return nullptr;
ListNode* dummy = new ListNode(-1);
dummy->next = head;
ListNode* pre = dummy;
for (int i = 0; i < left - 1; i++) pre = pre->next;
ListNode* cur = pre->next;
for (int i = 0; i < right - left; i++) {
ListNode* temp = cur->next;
cur->next = temp->next;
temp->next = pre->next;
pre->next = temp;
}
return dummy->next;
}
};