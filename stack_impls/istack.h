//
// Created by sergey214 on 20.12.2021.
//

#ifndef UNTITLED2_STACK_INTERFACE_H
#define UNTITLED2_STACK_INTERFACE_H
class istack
{
public:
    virtual void push(int val) = 0;
    virtual void pop() = 0;
    virtual int top() = 0;
    virtual int size() = 0;
    virtual bool empty() = 0;
};
#endif // UNTITLED2_STACK_INTERFACE_H
