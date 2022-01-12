//
// Created by sergey214 on 20.12.2021.
//

#ifndef STACKS_AND_QUEUES_IQUEUE_H
#define STACKS_AND_QUEUES_IQUEUE_H
class iqueue
{
public:
    virtual void push(int val) = 0;
    virtual void pop() = 0;
    virtual int front() = 0;
    virtual int size() = 0;
    virtual bool empty() = 0;
};
#endif // STACKS_AND_QUEUES_IQUEUE_H
