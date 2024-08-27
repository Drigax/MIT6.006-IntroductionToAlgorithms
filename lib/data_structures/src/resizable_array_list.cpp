#include "resizable_array_list.h"

#include <algorithm>
#include <cassert>
    
template<typename T>
resizable_array_list<T>::resizable_array_list()
{
    storage = std::make_unique<T[]>(new T[this->storage_size]);
}

template<typename T>
resizable_array_list<T>::resizable_array_list(
    std::iterator<T, unsigned long, const T*,const T&> begin,
    std::iterator<T, unsigned long, const T*, const T&> end)
{
    for (auto it = begin; it != end; ++it)
    {
        insert_last(*it);
    }
}

template<typename T>
std::iterator<std::bidirectional_iterator_tag,
                T,
                unsigned long,
                const T*,
                const T&> 
    resizable_array_list<T>::begin()
{
    return std::iterator<std::bidirectional_iterator_tag,
                T, unsigned long, const T*, const T&>
                (&storage[0]);
}

template<typename T>
std::iterator<std::bidirectional_iterator_tag,
                T,
                unsigned long,
                const T*,
                const T&> 
    resizable_array_list<T>::end()
{
    return std::iterator<std::bidirectional_iterator_tag,
                T, unsigned long, const T*, const T&>
                (&storage[item_count]);
}

template<typename T>
T& resizable_array_list<T>::first()
{
    return storage[0];
}

template<typename T>
T& resizable_array_list<T>::last()
{
    return storage[item_count];
}

template<typename T>
void resizable_array_list<T>::clear()
{
    item_count = 0;
}


template<typename T>
unsigned long resizable_array_list<T>::count()
{
    return item_count;
}

template<typename T>
T& resizable_array_list<T>::operator[](unsigned long idx)
{
    return storage[idx];
}

template<typename T>
const T& resizable_array_list<T>::operator[](unsigned long idx) const
{
    return storage[idx];
}

template<typename T>
T& resizable_array_list<T>::get(unsigned long idx)
{
    return storage[idx];
}

template<typename T>
void resizable_array_list<T>::set(unsigned long idx, T& val)
{
    storage[idx] = val;
}

template<typename T>
void resizable_array_list<T>::insert_at(unsigned long idx, T& val)
{
    assert(idx <= item_count);                      // if we try to insert past the current end of the list, throw an assert.
    if (item_count == storage_size)                 
    {
        resize();
    }
    for (auto i = item_count; i > idx; --i)         // O(n) shift right
    {        
        storage[i] = storage[i-1];              
    }
    storage[idx] = val;
    item_count++;
}

template<typename T>
void resizable_array_list<T>::delete_at(unsigned long idx)
{
    assert(idx < item_count);                      // if we try to insert past the current end of the list, throw an assert.
    for (auto i = idx; i < item_count - 1; ++i)    // O(n) shift left
    {
        storage[i] = storage[i+1];
    }
    item_count--;
}

template<typename T>
void resizable_array_list<T>::insert_first(T& val)
{
    if (item_count == storage_size)                 // special case, avoid multiple O(n) element copies by offsetting during the resize.
    {
        resize(storage_size * resize_factor, 1);
        storage[0] = val;
        return;
    } 
    else
    {
        for(unsigned long i = item_count; i > 0; --i)         // O[n] right shift of all items in the collection.
        {            
            storage[i] = storage[i-1];
        }
    }
    storage[0] = val;
    item_count++;
}

template<typename T>
void resizable_array_list<T>::insert_last(T& val)
{
    if (item_count == storage_size)
    {
        resize();
    }
    storage[item_count] = val;
    item_count++;
}

template<typename T>
void resizable_array_list<T>::delete_first()
{
    for(unsigned long i = 0; i < item_count-1; ++i)           // O[n] left shift of all items in the collection.
    {          
        storage[i] = storage[i+1];
    }
    item_count--;
}

template<typename T>
void resizable_array_list<T>::delete_last()
{
    item_count--; // constant time delete
    item_count = std::max(item_count, (unsigned long)0);
}

template<typename T>
bool resizable_array_list<T>::is_empty()
{
    return item_count > 0;
}


template<typename T>
void resizable_array_list<T>::resize()
{
    resize(storage_size * resize_factor);
}

template<typename T>
void resizable_array_list<T>::resize(unsigned long new_item_count, unsigned long first_element_offset)
{
    auto new_storage = new T[new_item_count];       // variable time, potentially costly allocaton.
    for (auto i = 0; i < storage_size; ++i)         // O(n) copy unsigned longo new space
    {
        new_storage[i+first_element_offset] = storage[i];
    }
    storage = std::make_unique<T[]>(new_storage);   // old storage is deallocated now that it is out of scope.
}
