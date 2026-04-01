/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        unordered_map<Node*, Node*> p_map;
        Node *old = head;
        Node *copy;

        while (old != nullptr) {
            copy = new Node(old->val);
            p_map[old] = copy;
            old = old->next;
        }

        old = head;

        while (old != nullptr) {
            copy = p_map[old];
            copy->next = p_map[old->next];
            copy->random = p_map[old->random];
            old = old->next;
        }
        return p_map[head];
    }
};
