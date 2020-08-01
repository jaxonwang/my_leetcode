#include <iostream>
#include <unordered_map>

using namespace std;

class MyListNode{
public:
    int key;
    int d;
    MyListNode *next;
    MyListNode *before;
    MyListNode(int key, int d):key(key), d(d), next(nullptr), before(nullptr){}
};

class LRUCache {
public:

    int capacity;
    int size;
    MyListNode *head;
    MyListNode *tail;
    unordered_map<int, MyListNode*> m;

    LRUCache(int capacity):capacity(capacity), size(0), head(new MyListNode{-1, -1}), tail(head){
        head->before = nullptr;
        head->next = nullptr;
    }
    ~LRUCache(){
        MyListNode * current = head;
        while(current){
            MyListNode * tmp = current->next;
            delete current;
            current = tmp;
        }
    }
    
    int get(int key) {
        if(m.count(key) == 0)
            return -1;
        int value = m[key]->d;

        MyListNode * current = m[key];
        if(head->next == m[key])
            return value;
        if(tail == m[key]){
            tail = current->before;
        }

        current->before->next = current->next;
        if(current->next)
        current->next->before = current->before;

        current->next = head->next;
        current->before = head;
        head->next->before = current;
        head->next = current;

        return value;
    }
    void print(){
        MyListNode * current = head;
        while(current){
            cout<<current->key <<":"<<current->d<< " ";
            current = current->next;
        }
        cout << endl;
    }
    
    void put(int key, int value) {
        // when already in
        if(m.count(key) >0){
            get(key);
            head->next->d = value;
            return;
        }

        if(size == capacity){
            MyListNode * tmp = tail;
            m.erase((tmp->key));
            tail = tail->before;
            tail->next = nullptr;
            delete tmp;
            size--;
        }
        MyListNode * n_node = new MyListNode(key, value);

        if(size == 0)
            tail = n_node;
        n_node->next = head->next;
        n_node->before = head;
        if(head->next)
            head->next->before = n_node;
        head->next = n_node;
        m[key] = n_node;
        size++;
    }
};

int main(int argc, const char *argv[])
{
    LRUCache cache( 2 /* capacity */ );

cache.put(1, 1);
cache.print();
cache.put(2, 2);
cache.print();
cache.get(1);       // returns 1
cache.print();
cache.put(3, 3);    // evicts key 2
cache.print();
cache.get(2);       // returns -1 (not found)
cache.print();
cache.put(4, 4);    // evicts key 1
cache.print();
cache.get(1);       // returns -1 (not found)
cache.print();
cache.get(3);       // returns 3
cache.print();
cache.get(4);       // returns 4
    
cache.print();
    return 0;
}
