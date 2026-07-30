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
private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = (list1 != nullptr) ? list1 : list2;
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;

        while (lists.size() > 1) {
            vector<ListNode*> mergedList;
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode *l1 = lists[i];
                ListNode *l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                mergedList.push_back(mergeTwoLists(l1, l2));
            }
            lists = mergedList;
        }
        return lists[0];
    }
};
