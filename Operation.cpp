//
// Created by dejan on 11/21/22.
//
#include "Operation.h"

Operation::Operation() {}
Operation::Operation(Matrix first, Matrix second, int order, std::string operation)
                    : first(first), second(second), order(order), operation(operation) {}

Matrix Operation::calculate() {
    if(operation=="+"){
        return first+second;
    }else if(operation=="-"){
        return first-second;
    } else if (operation=="*"){
        return first*second;
    }else{
        Matrix errorMatrix(0,0);
        return errorMatrix;
    }
}