#include <iostream>
#include "priorityList.h"

using namespace std;



int main() {
    PriorityQueue* que = new PriorityQueue();
    que->enqueue(12);
    que->enqueue(4);
    que->enqueue(21);
    que->enqueue(17);
    que->enqueue(73);
    que->writeAll();
    cout<<"dequeue: "<<que->dequeue()<<endl;
    que->writeAll();
    que->enqueue(37);
    que->enqueue(73);
    que->enqueue(53);
    que->writeAll();
    int num = 21;
    que->removeMember(&num);
    que->writeAll();



    return 0;
}
