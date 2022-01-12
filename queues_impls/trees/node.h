//
// Created by sergey214 on 12.01.2022.
//

#ifndef STACKS_AND_QUEUES_NODE_H
#define STACKS_AND_QUEUES_NODE_H

template<class T>
class node
{
public:
    T val = {};
    node * left = nullptr;
    node * right= nullptr;
};

template<class T>
void add(node<T> * node, T val)
{
    if(val > node->val)
    {
        if(!node->right)
        {
            node->right = new ::node<T>(val);
        }
        else
        {
            if(node->val)
        }

    }
    if(node->left && node->right)
    {
        if(node->left->val);

    }
    if(node->right)
        node->right->val;
}

template<class T>
T get_sum(const node<T> * node)
{
    if(!node)
        return 0;
    return node->val + get_sum(node->left)+ get_sum(node->right);
}

template<class T>
void get_sum_of_leaves(const node<T> * node, T & sum)
{
    if(!node)
        return;
    if(!node->right && !node->left)
        sum += node->val;
    if(node->right)
        get_sum_of_leaves(node->right, sum);
    if(node->left)
        get_sum_of_leaves(node->left, sum);
}


#endif // STACKS_AND_QUEUES_NODE_H
