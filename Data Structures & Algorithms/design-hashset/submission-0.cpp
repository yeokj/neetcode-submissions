class Node {
public:
    int val;
    Node *next;

    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};

class Bucket {
private:
    Node *dummy;

public:
    Bucket() {
        dummy = new Node(-1);
    }

    void insert(int key) {
        if (contains(key)) return;

        Node *newNode = new Node(key);
        newNode->next = dummy->next;
        dummy->next = newNode;
    }

    void erase(int key) {
        if (!contains(key)) return;

        Node *prev = dummy;
        Node *curr = dummy->next;
    
        while (curr != nullptr) {
            if (curr->val == key) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    bool contains(int key) {
        if (dummy->next == nullptr) return false;

        Node *curr = dummy->next;
        while (curr != nullptr) {
            if (curr->val == key) return true;
            curr = curr->next;
        }
        return false;
    }
};

class MyHashSet {
private:
    vector<Bucket> storage;
    int size = 769;
    int hash(int key) {
        return key % size;
    }

public:
    MyHashSet() {
        storage.assign(size, Bucket());
    }
    
    void add(int key) {
        int slot = hash(key);
        storage[slot].insert(key);
    }
    
    void remove(int key) {
        int slot = hash(key);
        storage[slot].erase(key);
    }
    
    bool contains(int key) {
        int slot = hash(key);
        bool found = storage[slot].contains(key);

        if (found) return true;

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */