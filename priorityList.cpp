#include <iostream>
#include "string.h"
#include "priorityList.h"
#include "Matrix.h"
#include "Operation.h"

using namespace std;


Node::Node(Operation content) : content(content) {
}
Node::Node(Operation cont, int val) : value(val), content(cont) {
}
Node::Node(Operation cont, int val, Node* previous) : value(val), content(cont) {
    if (previous){
        this->next = previous->next;
    }
    this->prev = previous;
}

Node *PriorityQueue::enqueue(int val, Operation content) {
    Node* p = this->head;

    if(p== nullptr){
        this->head = new Node(content, val, nullptr);
        this->head->setNext(nullptr);
        this->tail = this->head;
        return this->head;
    }else if(p->getNext()== nullptr){
        Node* temp = new Node(content, val);
        if(val>this->head->getValue()){
            head->setPrev(temp);
            temp->setNext(head);
            head=temp;
            this->tail = head->getNext();
            return this->head;
        }
        temp->setPrev(this->head);
        temp->setNext(nullptr);
        head->setNext(temp);
        this->tail = temp;
        return this->head;
    }
    while(p->getNext()){
        if(p->getValue()<val){
            Node* tmp = new Node(content, val, p->getPrev());
            tmp->setNext(p);
            if(p->getPrev()){
                p->getPrev()->setNext(tmp);
            }
            p->setPrev(tmp);
            if(val>head->getValue()){
                head=tmp;
            }
            return tmp;
        }
        p = p->getNext();
    }
    tail = new Node(content, val, p);
    p->setNext(tail);
    return tail;
}

Operation PriorityQueue::dequeue() {


    if (this->head){
        Operation cont = this->head->getContent();
        this->head = this->head->getNext();
        if(this->head){
            delete this->head->getPrev();
            this->head->setPrev(nullptr);
        }
        return cont;
    }
    Operation newOperation;
    return newOperation;

}

bool PriorityQueue::removeMember(int *val) {
    Node *p = this->head;

    while(p->getNext()){
        if(p->getValue()==*val){
            p->getNext()->setPrev(p->getPrev());
            p->getPrev()->setNext(p->getNext());
            delete p;
            return true;
        }
        p = p->getNext();
    }
    return false;

}
