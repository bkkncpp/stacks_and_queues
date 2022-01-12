//
// Created by sergey214 on 23.12.2021.
//

#ifndef STACKS_AND_QUEUES_TWO_STACKS_QUEUE_H
#define STACKS_AND_QUEUES_TWO_STACKS_QUEUE_H

#include "../stack_impls/pairs_stack.h"
#include "iqueue.h"
#include <stack>
using namespace std;

class two_stacks_queue : iqueue
{
private:
    pairs_stack m_insert_stack;
    pairs_stack m_extract_stack;

private:
    bool move_to_extract_stack()
    {
        for( int i = 0; i < m_insert_stack.size(); ++i )
        {
            m_extract_stack.push( m_insert_stack.top() );
            m_insert_stack.pop();
        }
        return !m_extract_stack.empty();
    }

public:
    int size()
    {
        return m_extract_stack.size() + m_insert_stack.size();
    }

public:
    bool empty() override
    {
        return m_extract_stack.empty() && m_insert_stack.empty();
    }

public:
    void push( int val ) override
    {
        int minima = m_insert_stack.empty() ? val : ::min (val, m_insert_stack.top());
        m_insert_stack.push( minima );
    }
    void pop() override
    {
        if( m_extract_stack.empty() )
        {
            if( move_to_extract_stack() )
                m_extract_stack.pop();
        }
        else
            m_extract_stack.pop();
    }
    int front() override
    {
        if( !m_extract_stack.empty() )
            return m_extract_stack.top();
        else
        {
            if( move_to_extract_stack() )
                return m_extract_stack.top();
            else
                throw std::exception();
        }
    }
    int min()
    {
        int min_val;
        if( m_insert_stack.empty() || m_extract_stack.empty() )
            min_val = m_insert_stack.empty() ? m_extract_stack.top() : m_insert_stack.top();
        else
            min_val = ::min( m_insert_stack.top(), m_extract_stack.top() );
        return min_val;
    }
};
#endif // STACKS_AND_QUEUES_TWO_STACKS_QUEUE_H
