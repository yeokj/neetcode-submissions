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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *next = nullptr;
        ListNode *prev = nullptr;
        while (slow != nullptr) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        ListNode *curr1 = head;
        ListNode *curr2 = prev;
        while (curr2 != nullptr) {
            if (curr1->val != curr2->val) return false;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return true;
    }
};