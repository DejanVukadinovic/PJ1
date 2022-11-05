#include <iostream>

using namespace std;

class Node {
    private:
        int value;
        Node* prev = nullptr;
        Node* next = nullptr;
    public:
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
        Node(int val, Node* previous);
        Node();
};

Node::Node(int val, Node* previous) {
    this->setValue(val);
    this->next = previous->next;
    this->prev = previous;
}
Node::Node() {
}

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

Node *PriorityQueue::enqueue(int val) {
    Node* p = this->head;

    if(p== nullptr){
        this->head = new Node();
        this->head->setValue(val);
        this->head->setPrev(nullptr);
        this->head->setNext(nullptr);
        this->tail = this->head;
        return this->head;
    }else if(p->getNext()== nullptr){
        Node* temp = new Node;
        temp->setValue(val);
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
        cout<<"79 "<<val<<endl;
        if(p->getValue()<val){
            cout<<"81 "<<val<<endl;
            Node* tmp = new Node();
            tmp->setValue(val);
            tmp->setNext(p);
            tmp->setPrev(p->getPrev());
            p->getPrev()->setNext(tmp);
            p->setPrev(tmp);
            cout<<"87 "<<tmp->getNext()<<"  "<<tmp->getPrev()<<endl;
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
        cout<<"134 "<<p->getValue()<<endl;
        p=p->getNext();
    }

}


int main() {
    PriorityQueue* que = new PriorityQueue();
    que->enqueue(12);
    que->enqueue(4);
    que->enqueue(21);
    que->enqueue(17);
    que->enqueue(73);
    que->enqueue(53);
    que->writeAll();
    //std::cout<<que->dequeue()<<std::endl;
    //que->enqueue(17);
    //que->enqueue(73);
    //que->enqueue(53);
    //int kurac = 21;
    //que->removeMember(&kurac);
    //que->writeAll();



    return 0;
}
