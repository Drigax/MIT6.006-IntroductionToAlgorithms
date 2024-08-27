#include <iostream>
#include "resizable_array_list.h"

template<typename T> 
class set_unordered 
{
    set_unordered();
    set_unordered(std::iterator<std::forward_iterator_tag, T, long, const T*, const T&> begin,
                std::iterator<std::forward_iterator_tag, T, long, const T*, const T&> end);

    unsigned long count();
    
    bool contains(T& item);
    unsigned long find(T& item);

    void insert(T& item);
    void remove(T& item);
    
    std::iterator<std::bidirectional_iterator_tag, T, long, const T*, const T&> iter_order();
    
    T& find_min();
    T& find_max();
    T& find_next(T& item);
    T& find_prev(T& item);

    std::unique_ptr<resizable_array_list<T>> storage;
};
