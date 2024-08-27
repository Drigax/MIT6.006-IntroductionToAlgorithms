#pragma once

#include "set_unordered.h"
#include <cassert>

template<typename T>
set_unordered<T>::set_unordered()
{
}

template<typename T>
set_unordered<T>::set_unordered(std::iterator<std::forward_iterator_tag, T, long, const T*, const T&> begin,
                            std::iterator<std::forward_iterator_tag, T, long, const T*, const T&> end)
{
    for (auto itr = begin; itr != end; ++itr)
    {
        insert(*itr);
    }
}

template<typename T>
unsigned long set_unordered<T>::count()
{
    return storage->get().size();
}

template<typename T>
bool set_unordered<T>::contains(T& item)
{
    auto it = storage.begin();
    
    unsigned long count = this->count();
    while(count > 0)
    {
        if (*it == item)                // O[n] iteration through set to find element.
        {
            return true;
        }
        ++it;
        --count;
    }
    return false;
}

template<typename T>
unsigned long set_unordered<T>::find(T& item)
{
    auto it = storage.begin();

    unsigned long idx = 0;
    unsigned long count = this->count();
    while(idx < count)
    {
        if (*it == item)                // O[n] iteration through set to find element.
        {
            return idx;
        }
        ++idx;
        ++it;
    }
    assert(false);                      // item does not exist in set.
}

template<typename T>
void set_unordered<T>::insert(T& item)
{
    if (!this->contains(item))
    {
        this->storage->get().insert_last(item);     // (amortized) O(1) insertion
    }
}

template<typename T>
void set_unordered<T>::remove(T& item)
{
    if (!this->contains(item))                      // O(n) traversal to see if item exists in collection
    {
        auto idx = this->find(item);                // O(n) traversal to get index of item
        this->storage->get().delete_at(idx);        // O(n) shift of existing items in collection.
    }
}

template<typename T>
std::iterator<std::bidirectional_iterator_tag, T, long, const T*, const T&> set_unordered<T>::iter_order()
{
    return std::iterator<std::bidirectional_iterator_tag, T, long, const T*, const T&>();
}

template<typename T>
T& set_unordered<T>::find_min()
{
    assert(!storage->get().is_empty());

    T& current = storage.get.get(0);
    for (auto itr = storage.get().begin(); itr != storage.get().end(); ++itr)       // O(n) traversal of all items in set.
    {
        current = *itr < current ? *itr : current;  // one liner min function
    }
    return current;
}

template<typename T>
T& set_unordered<T>::find_max()
{
    assert(!storage->get().is_empty());

    T& current = storage.get().get(0);
    for (auto itr = storage.get().begin()++; itr != storage.get().end(); ++itr)     // O(n) traversal of all items in set.
    {
        current = *itr > current ? *itr : current;  // one liner max function
    }
    return current;
}

template<typename T>
T& set_unordered<T>::find_next(T& item)
{
    assert(!storage->get().count() > 1);

    auto idx = find(item);                  // O(n) traversal to find item

    assert (idx != storage->get().item_count-1);

    return storage->get().get(idx + 1);     // O(1) retrieval
}

template<typename T>
T& set_unordered<T>::find_prev(T& item)
{
    assert(!storage->get().count() > 1);

    auto idx = find(item);                  // O(n) traversal to find item

    assert (idx > 0);

    return storage->get().get(idx - 1);     // O(1) retrieval
}
