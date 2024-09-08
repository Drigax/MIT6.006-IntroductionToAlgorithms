#pragma once

#include <iostream>
#include <memory>

template<typename T>
class linked_list_node
{
    public:
    linked_list_node(T in_value)
    { 
        this->value = in_value;
        this->next = nullptr;
    }

    T value;
    std::shared_ptr<linked_list_node<T>> next;
};

template<typename T>
class linked_list
{
public:
    linked_list()
    {
    }

    void insert_front(T value)
    {
        auto new_node = std::make_shared<linked_list_node<T>>(value);
        auto tmp = this->head;
        if (this->head != nullptr) // base case: list is not empty, preserve reference to current head
        {
            new_node->next = tmp;
        }
        this->head = new_node;
        size++;
    }

    void insert_back(T value)
    {
        auto new_node = std::make_shared<linked_list_node<T>>(value);
        auto current = this->head;
        if (this->head == nullptr) // base case: list is empty. this is now head.
        {
            this->head = new_node;
        }
        else
        {
            while(current->next != nullptr)
            {
                current = current->next;
            }
            current->next = new_node;
        }
        size++;
    }

    T delete_front()
    {
        if (this->size == 0) // base case: list is empty
        {
            return nullptr;
        }
        
        auto old_head = this->head; // otherwise point head to whatever the old head pointed to.
        this->head = old_head->next;
        size--;
        return old_head.value;
    }

    T delete_back()
    {
        if (this->size == 0) // base case: list is empty
        {
            return nullptr;
        }

        auto current = this->head; // otherwise iterate to the size'th item, and remove next reference of size-1'th item
        auto prev = current;

        while(current->next != nullptr)
        {
            prev = current;
            current = current->next;
        }

        prev->next = nullptr;
        size--;

        if (size == 0) // special case: if we remove the last element from the back, update our head reference.
        {
            this->head = nullptr;
        }

        return current->value;
    }

    friend std::ostream& operator<<(std::ostream& os, const linked_list& ll)
    {
        os << "{ ";
        auto current = ll.head;
        while (current != nullptr)
        {
            os << current->value;
            if (current->next != nullptr)
            {
                os << ", ";
            }
            current = current->next;
        }
        os << " }";
        return os;
    }

    std::shared_ptr<linked_list_node<T>> head = nullptr;
    unsigned int size = 0;
};
