#include <iostream>
#include "priorityList.h"

using namespace std;


Node::Node() {
}
Node::Node(int val) {
    this->setValue(val);
}
Node::Node(int val, Node* previous) {
    this->setValue(val);
    if (previous){
        this->next = previous->next;
    }
    this->prev = previous;
}


Node *PriorityQueue::enqueue(int val) {
    Node* p = this->head;

    if(p== nullptr){
        this->head = new Node(val, nullptr);
        this->head->setNext(nullptr);
        this->tail = this->head;
        return this->head;
    }else if(p->getNext()== nullptr){
        Node* temp = new Node(val);
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
            Node* tmp = new Node(val, p->getPrev());
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
    tail = new Node(val, p);
    return tail;
}

int PriorityQueue::dequeue() {
    int val = this->head->getValue();
    this->head = this->head->getNext();
    delete this->head->getPrev();
    this->head->setPrev(nullptr);
    return val;
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

void PriorityQueue::writeAll() {
    Node *p = this->head;
    while(p!= nullptr){
        cout<<"writeAll: "<<p->getValue()<<endl;
        p=p->getNext();
    }
    cout<<endl;

}

