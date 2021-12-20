//
// Created by sergey214 on 20.12.2021.
//
#ifndef UNTITLED2_MY_STACK_H
#define UNTITLED2_MY_STACK_H
#include "stack_interface.h"
#include <stack>

using namespace std;

class my_stack : istack
{
private:
    stack<int> m_insert;
    stack<int> m_extract;

public:
    my_stack()
    {
    }

private:
    void insert2extract()
    {
        for( int i = 0; i < m_insert.size(); ++i )
        {
            m_extract.push( m_insert.top() );
            m_insert.pop();
        }
    }
    void push( int val ) override
    {
        m_insert.push( val );
    }

    int pop() override
    {
        if( m_extract.empty() && m_insert.empty() )
            throw std::exception();
        if( m_extract.empty() )
            insert2extract();
        int val = m_extract.top();
        m_extract.pop();
        return val;
    }
};
#endif // UNTITLED2_MY_STACK_H
