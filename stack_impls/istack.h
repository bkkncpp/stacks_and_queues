//
// Created by sergey214 on 20.12.2021.
//

#ifndef UNTITLED2_STACK_INTERFACE_H
#define UNTITLED2_STACK_INTERFACE_H
class istack
{
public:
    virtual void push(int val) = 0;
    virtual int pop() = 0;
};
#endif // UNTITLED2_STACK_INTERFACE_H
