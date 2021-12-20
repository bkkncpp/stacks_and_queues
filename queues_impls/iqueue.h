//
// Created by sergey214 on 20.12.2021.
//

#ifndef STACKS_AND_QUEUES_IQUEUE_H
#define STACKS_AND_QUEUES_IQUEUE_H
class iqueue
{
public:
    virtual void push(int val) = 0;
    virtual int pop() = 0;
};
#endif // STACKS_AND_QUEUES_IQUEUE_H
