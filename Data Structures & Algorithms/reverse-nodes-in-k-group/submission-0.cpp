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
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = head;
        ListNode *prev = dummy;
        ListNode *next = nullptr;

        while (curr != nullptr) {
            ListNode *node = prev;
            int i = 0;
            while (i < k && node != nullptr) {
                node = node->next;
                ++i;
            }
            if (i < k || node == nullptr) break;

            ListNode *groupHead = curr;
            ListNode *prevNode = nullptr;
            next = node->next;
            while (curr != next) {
                ListNode *tempNext = curr->next;

                curr->next = prevNode;
                prevNode = curr;
                curr = tempNext;
            }
            prev->next = prevNode;
            groupHead->next = next;
            prev = groupHead;
        }

        return dummy->next;
    }
};
