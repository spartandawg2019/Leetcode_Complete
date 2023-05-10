class Solution {
public:
ListNode* deleteDuplicates(ListNode* head) {
if (!head) return head;
ListNode *dummy = new ListNode(-1);
dummy->next = head;
ListNode *prev = dummy;
while (head && head->next) {
if (head->val == head->next->val) {
int val = head->val;
while (head && head->val == val) {
ListNode *temp = head;
head = head->next;
delete temp;
}
prev->next = head;
} else {
prev = head;
head = head->next;
}
}
return dummy->next;
}
};