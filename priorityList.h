#ifndef PJ1_PRIORITYLIST_H
#define PJ1_PRIORITYLIST_H
#endif //PJ1_PRIORITYLIST_H


class Node {
private:
    int value;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* getPrev(){
        return this->prev;
    };
    Node* getNext(){
        return this->next;
    };
    void setPrev(Node* val){
        this->prev = val;
    };
    void setNext(Node* val){
        this->next = val;
    };
    int getValue(){
        return this->value;
    };
    void setValue(int val){
        this->value = val;
    };
    Node();
    Node(int val);
    Node(int val, Node* previous);
    friend class PriorityQueue;

};

class PriorityQueue {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    Node* enqueue(int val);
    int dequeue();
    bool removeMember(int* val);
    void writeAll();
};
