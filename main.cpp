#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <vector>
#include "my_stack.h"

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

int main()
{
    // solution 1
    vector<int> input = { 5, 1, 3, 2, 4, 6, 1, 7, 3, 2, 8 };
    vector<int> output = {};
    sliding_window1::execute( input, output );
    // solution 2
    my_stack myStack;
    return 0;
}
