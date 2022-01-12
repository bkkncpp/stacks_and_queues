#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
//#include "queues_impls/two_stacks_queue.h"

using namespace std;

int inf = 2e9;
struct sliding_window1
{
    deque<pair<int, int>> d;
    int l, r;

    sliding_window1()
    {
        l = r = 0;
    }

    void push_back( int x )
    {
        while( !d.empty() && d.back().first >= x )
            d.pop_back();
        d.emplace_back( x, r );
        ++r;
    }

    void pop_front()
    {
        if( d.front().second == l )
            d.pop_front();
        ++l;
    }

    int get_min()
    {
        return d.empty() ? inf : d.front().first;
    }

    static void execute( const vector<int>& input, vector<int>& output )
    {
        sliding_window1 sw;
        for( int i = 0; i < 3; ++i )
            sw.push_back( input[i] );
        output.push_back( sw.get_min() );
        for( int i = 3; i < input.size(); ++i )
        {
            sw.push_back( input[i] );
            sw.pop_front();
            output.push_back( sw.get_min() );
        }
        std::cout << "output:" << std::endl;
        for( int i = 0; i < output.size(); ++i )
            std::cout << output[i] << " ";
        std::cout << "input:" << std::endl;
        for( int i = 0; i < input.size(); ++i )
            std::cout << input[i] << " ";
    }
};

// int inf = 2e9;
struct sliding_window2
{
    vector<int> l, r;
    int rmin;

    sliding_window2()
    {
        rmin = inf;
    }

    void push_back( int x )
    {
        r.push_back( x );
        rmin = min( rmin, x );
    }

    void pop_front()
    {
        if( l.empty() )
        {
            for( int mn = inf; !r.empty(); )
            {
                mn = min( mn, r.back() );
                l.push_back( mn );
                r.pop_back();
            }
            rmin = inf;
        }
        l.pop_back();
    }

    int get_min()
    {
        int res = rmin;
        if( !l.empty() )
            res = min( res, l.back() );
        return res;
    }
    static void execute()
    {
    }
};

template <class T>
class min_stack
{
    using Min = T;
    stack<pair<T, Min>> m_stack;

public:
    int size() const
    {
        return m_stack.size();
    }

    bool empty() const
    {
        return m_stack.empty();
    }

    pair<T, Min> top() const
    {
        return this->m_stack.top();
    }

    void push( T val )
    {
        T min = m_stack.empty() ? val : std::min( val, m_stack.top().second );
        this->m_stack.push( make_pair( val, min ) );
    }

    void pop()
    {
        this->m_stack.pop();
    }

    T get_min() const
    {
        if( this->m_stack.empty() )
            return {};
        return this->m_stack.top().second;
    }
};

template <class T>
class two_stacks_queue
{
    min_stack<T> m_in;
    min_stack<T> m_out;

public:
    void enque( T val )
    {
        this->m_in.push( val );
    }

    void deque()
    {
        if( this->m_out.empty() && this->m_in.empty() )
            return;
        if( this->m_out.empty() )
            this->move_to_out();
        this->m_out.pop();
    }

    T peek() const
    {
        if( this->m_out.empty() && this->m_in.empty() )
            return;
        if( this->m_out.empty() )
            this->move_to_out();
        return this->m_out.top().first;
    }

    T get_min() const
    {
        if( m_in.empty() && m_out.empty() )
            return {};
        T current_minimum = {};
        if( m_in.empty() || m_out.empty() )
            current_minimum = m_in.empty() ? m_out.top().second : m_in.top().second;
        else
            current_minimum = min( m_in.top().second, m_out.top().second );
        return current_minimum;
    }

private:
    void move_to_out()
    {
        int size = this->m_in.size();
        while( !m_in.empty() )
        {
            T val = this->m_in.top().first;
            this->m_out.push( val );
            this->m_in.pop();
        }
    }
};

void sliding_window_min( const vector<int> v, int m )
{
    two_stacks_queue<int> q;
    if( v.size() < m )
        return;
    for( int i = 0; i < m; ++i )
        q.enque( v[i] );

    cout << q.get_min() << " ";
    q.deque();
    for( int i = m; i < v.size(); ++i )
    {
        q.enque( v[i] );
        cout << q.get_min() << " ";
        q.deque();
    }
}

int main()
{
    //    // solution 1
    //    vector<int> input = { 5, 1, 3, 2, 4, 6, 1, 7, 3, 2, 8 };
    //    vector<int> output = {};
    //    sliding_window1::execute( input, output );
    //    // solution 2
    //    two_stacks_queue queue;
    //
    //    int m = 3;
    //    for( int i = 0; i < m; ++i )
    //        queue.push(input[i]);
    //
    //    output.push_back(queue.min());
    //
    //    for (int i = m + 1; i < input.size(); i++) {
    //        queue.pop();
    //        queue.push(input[i]);
    //        output.push_back(queue.front());
    //    }

    // string s = "2.0";
    // printf("%9s",s.c_str());

    vector<int> input = { 5, 1, 3, 2, 4, 6, 1, 7, 3, 2, 8 };

    sliding_window_min( input, 3 );

    return 0;
}
/*
 1123234
 4112332

 for(int i = 0; i<n; ++i)
 {
    val = a[i]

 }

 */