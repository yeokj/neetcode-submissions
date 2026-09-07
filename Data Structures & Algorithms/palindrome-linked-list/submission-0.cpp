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
        if (head == nullptr) return false;

        stack<int> st;
        ListNode *tail = head;
        while (tail != nullptr) {
            st.push(tail->val);
            tail = tail->next;
        }

        ListNode* curr = head;
        while (curr != nullptr) {
            int end = st.top();
            if (curr->val != end) return false;

            st.pop();
            curr = curr->next;
        }
        return true;
    }
};