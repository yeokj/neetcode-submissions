class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node *prev;
        Node *next;
        Node (int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    unordered_map<int, Node*> cache;
    int cap;
    Node *head;
    Node *tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        Node *node = cache[key];
        removeNode(node);
        addToHead(node);

        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            Node *node = cache[key];
            node->value = value;
            removeNode(node);
            addToHead(node);
        }
        else {
            Node *node = new Node(key, value);
            addToHead(node);
            cache[key] = node;
        }
        if (cache.size() > cap) {
            Node* lru = tail->prev;
            removeNode(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
