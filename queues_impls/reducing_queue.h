//
// Created by sergey214 on 20.12.2021.
//

#ifndef STACKS_AND_QUEUES_REDUCING_QUEUE_H
#define STACKS_AND_QUEUES_REDUCING_QUEUE_H
#include "iqueue.h"
#include <deque>
using namespace std;

class reducing_queue : iqueue
{
private:
    deque<int> m_deque;

    void pop() override
    {
        int val = m_deque.front();
        m_deque.pop_front();
    }
public:
    void push( int val ) override
    {
        while( !m_deque.empty() && m_deque.back() > val )
            m_deque.pop_back();
        m_deque.push_back( val );
    }
    int pop_given( int val )
    {
        if( !m_deque.empty() && m_deque.front() == val )
            return 0;
    }
    int get_min()
    {
        return m_deque.front();
    }

private:
    int front() override
    {
        return m_deque.front();
    }
    int size() override
    {
        return m_deque.size();
    }
};
#endif // STACKS_AND_QUEUES_REDUCING_QUEUE_H
