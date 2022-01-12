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
    stack<pair<int, int>> m_stack;//<value, cur_min>

public:
    void push( int val ) override
    {
        m_stack.emplace( val, m_stack.empty() ? val : ::min( m_stack.top().second, val ) );
    }
    void pop() override
    {
        m_stack.pop();
    }

    int top() override
    {
        return m_stack.top().first;
    }

public:
    int min()
    {
        return m_stack.top().second;
    }

public:
    int size() override
    {
        return m_stack.size();
    }
    bool empty() override
    {
        return m_stack.empty();
    }
};
#endif // UNTITLED2_PAIRS_STACK_H
