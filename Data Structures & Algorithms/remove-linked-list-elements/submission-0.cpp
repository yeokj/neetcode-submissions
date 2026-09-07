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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return nullptr;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *tail = dummy;

        while (tail->next != nullptr) {
            if (tail->next->val == val) tail->next = tail->next->next;
            else tail = tail->next;
        }
        return dummy->next;
    }
};