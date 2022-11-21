#include <iostream>
#include "priorityList.h"
#include "Matrix.h"

using namespace std;



int main() {
    Matrix first(2,2);
    Matrix second(2,2);

    first<<2;
    second<<1;
    second<<3;
    Matrix max = Matrix::max(first, second);
    cout<<first;
    cout<<second;
    cout<<max;
    PriorityQueue que;
    Operation firstOp(first, second, 1, "+");
    que.enqueue(1, firstOp);
    Operation tmpOp = que.dequeue();
    Matrix result = tmpOp.calculate();
    cout<<result;



    return 0;
}
