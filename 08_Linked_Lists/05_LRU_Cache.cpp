/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, 
add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
*/

class LRUCache {
public:
    class Node{
        public:
        int key,value;
        Node *next;
        Node *prev;
        Node(int key,int value){
            this->key = key;
            this->value = value;
            next = NULL;
            prev = NULL;
        }
    };

    Node *start = new Node(-1,-1);
    Node *last = new Node(-1,-1);
    unordered_map<int,Node*> mp;
    int size;
    LRUCache(int capacity) {
        size = capacity;
        start->next = last;
        last->prev = start;
    }

    void addNode(Node *newNode){
        Node *temp = start->next;
        newNode->next = temp;
        newNode->prev = start;
        temp->prev = newNode;
        start->next = newNode;
    }

    void deleteNode(Node *node){
        Node *nodePrev = node->prev;
        Node *nodeNext = node->next;
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;
        delete node;
    }

    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node *current = mp[key];
            int value = current->value;
            deleteNode(current);
            mp.erase(key);
            Node *newNode = new Node(key,value);
            addNode(newNode);
            mp[key] = newNode;
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node *current = mp[key];
            deleteNode(current);
            mp.erase(key);
            Node *newNode = new Node(key,value);
            addNode(newNode);
            mp[key] = newNode;
            return;
        }
        if(mp.size() == size){
            Node *leastUsedNode = last->prev;
            mp.erase(leastUsedNode->key);
            deleteNode(leastUsedNode);
            Node *newNode = new Node(key,value);
            addNode(newNode);
            mp[key] = newNode;
        }
        else{
            Node *newNode = new Node(key,value);
            addNode(newNode);
            mp[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
