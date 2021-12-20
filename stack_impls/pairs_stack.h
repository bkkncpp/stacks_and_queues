//
// Created by sergey214 on 20.12.2021.
//

#ifndef UNTITLED2_PAIRS_STACK_H
#define UNTITLED2_PAIRS_STACK_H
#include "istack.h"
#include <stack>

using namespace std;

/*
 * pairs_stack is able to:
 * push by O(1)
 * pop by O(1)
 * getMin (O)1
 */
class pairs_stack : istack
{
private:
    stack<pair<int, int>> m_stack;

public:
    void push( int val ) override
    {
        m_stack.emplace( val, m_stack.empty() ? val : min( m_stack.top().second, val ) );
    }
    int pop() override
    {
        if( m_stack.empty() )
            throw std::exception();
        int last = m_stack.top().first;
        m_stack.pop();
        return last;
    }
    int min()
    {
        return m_stack.top().second;
    }
};
#endif // UNTITLED2_PAIRS_STACK_H
