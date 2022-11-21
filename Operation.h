//
// Created by dejan on 11/21/22.
//

#include "Matrix.h"

#ifndef PJ1_OPERATION_H

#define PJ1_OPERATION_H


class Operation{
private:
    Matrix first;
    Matrix second;
    int order;
    std::string operation;
public:
    int getOrder(){
        return order;
    }
    void setOrder(int order){
        this->order=order;
    }
    std::string getOperation(){
        return operation;
    }
    Operation();
    Operation(Matrix first, Matrix second, int order, std::string operation);
    Matrix calculate();
};

std::ostream& operator<<(std::ostream&, const Operation&);

#endif //PJ1_OPERATION_H
