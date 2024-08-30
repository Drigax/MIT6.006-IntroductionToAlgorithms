#pragma once

#include <cassert>
#include <iterator>
#include <memory>
#include <iostream>

#define UNUSED(x) (void)(x)

template<typename T>
class resizable_array_list
{
public:
    resizable_array_list()
    {
        storage = std::make_unique<T[]>(this->storage_size);
    }

    std::iterator<std::bidirectional_iterator_tag,
                T, unsigned long, const T*, const T&> 
                begin()
    {
        return std::iterator<std::bidirectional_iterator_tag,
                    T, unsigned long, const T*, const T&>
                    (&storage[0]);
    }

    
    std::iterator<std::bidirectional_iterator_tag,
                T, unsigned long, const T*, const T&> 
                end()
    {
        return std::iterator<std::bidirectional_iterator_tag,
                    T, unsigned long, const T*, const T&>
                    (&storage[item_count]);
    }
    
    T& first()
    {
        return storage[0];
    }

    T& last()
    {
        return storage[item_count-1];
    }

    void clear()
    {
        item_count = 0;
    }
    
    unsigned long count()
    {
        return item_count;
    }

    unsigned long capacity()
    {
        return storage_size;
    }
    
    T& operator[](unsigned long idx)
    {
        return storage[idx];
    }

    const T& operator[](unsigned long idx) const
    {
        return storage[idx];
    }
    
    T& get(unsigned long idx)
    {
        return storage[idx];
    }

    void set(unsigned long idx, T val)
    {
        storage[idx] = val;
    }

    void insert_at(unsigned long idx, T val)
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

    void delete_at(unsigned long idx)
    {
        assert(idx < item_count);                      // if we try to insert past the current end of the list, throw an assert.
        for (auto i = idx; i < item_count - 1; ++i)    // O(n) shift left
        {
            storage[i] = storage[i+1];
        }
        item_count--;
    }

    void insert_first(T val)
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

    void insert_last(T val)
    {
        if (item_count == storage_size)
        {
            resize();
        }
        storage[item_count] = val;
        item_count++;
    }

    void delete_first()
    {
        for(unsigned long i = 0UL; i < item_count-1; ++i)           // O[n] left shift of all items in the collection.
        {          
            storage[i] = storage[i+1];
        }
        if (item_count > 0UL)
        {
            item_count--;
        }
    }

    void delete_last()
    {
        if (item_count > 0UL)
        {
            item_count--; // constant time delete
        }
    }

    bool is_empty()
    {
        return item_count == 0;
    }

    void resize()
    {
        resize(storage_size * resize_factor, 0UL);
    }

    void resize(unsigned long new_item_count, unsigned long first_element_offset)
    {
        auto old_storage = move(storage);                   
        storage = std::make_unique<T[]>(new_item_count);    // variable time, potentially costly allocaton.
        
        for (auto i = 0UL; i < storage_size; ++i)           // O(n) copy into new space
        {
            storage[i+first_element_offset] = old_storage[i];
            //std::cout << "setting new storage idx: " << i+first_element_offset << " : " << old_storage[i] << " --> " << storage[i] << std::endl;
        }
        storage_size = new_item_count;                      // old storage is deallocated once it is out of scope.
    }
    
private:
    std::unique_ptr<T[]> storage;
    
    unsigned long storage_size = 5;
    const unsigned long resize_factor = 2;
    unsigned long item_count = 0;
    
};
