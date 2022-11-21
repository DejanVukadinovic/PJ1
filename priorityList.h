#ifndef SPA_LAB1C__STRUCTURES_H
#define SPA_LAB1C__STRUCTURES_H
#include "Matrix.h"
#include "Operation.h"
using namespace std;


class Node {
private:
    int value;
    Operation content;
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
    Operation getContent(){
        return this->content;
    };
    void setContent(Operation content){
        Node::content = content;
    };
    Node(Operation content);
    Node(Operation cont, int val);
    Node(Operation cont, int val, Node* previous);
    friend class PriorityQueue;
    friend class Stack;
};

class Stack {
private:
    Node* head = nullptr;
public:
    void push(string content);
    string pop();
    bool empty();
};

class PriorityQueue {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    Node* enqueue(int val, Operation content);
    Operation dequeue();
    bool removeMember(int* val);
};


#endif //SPA_LAB1C__STRUCTURES_H
