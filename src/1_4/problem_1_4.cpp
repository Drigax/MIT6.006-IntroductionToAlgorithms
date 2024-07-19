#include <iostream>
#include <memory>
#include <vector>
#include <limits.h>

using namespace std;

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
    shared_ptr<linked_list_node<T>> next;
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
        auto new_node = make_shared<linked_list_node<T>>(value);
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
        auto new_node = make_shared<linked_list_node<T>>(value);
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

    friend ostream& operator<<(ostream& os, const linked_list& ll)
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

    shared_ptr<linked_list_node<T>> head = nullptr;
    unsigned int size = 0;
};


shared_ptr<linked_list_node<int>> reverse_recursive(shared_ptr<linked_list_node<int>> p_node)
{
    //cout << "reversing order of " << p_node->value << endl;
    if (p_node->next == nullptr) // base case: there is no next node.
        return p_node;
    auto next = p_node->next;
    auto tail = reverse_recursive(next);
    next->next = p_node;
    p_node->next = nullptr; // clear reference that this node points to.
    return tail;
}

void reorder_students_recursive(linked_list<int>& input)
{
    int half_length = input.size/2; // find pivot of input
    cout << "Reversing elements after the "<< half_length <<"th element" << endl;
    auto current = input.head;
    for (int i = 0; i < half_length - 1; ++i)
    {
        current = current->next;
    }
    cout << "Reversing elements after "<< current->value << endl;
    current->next = reverse_recursive(current->next);
}

void reorder_students_iterative(linked_list<int>& input)
{
    unsigned int half_length = input.size/2; // find pivot of input
    cout << "Reversing elements after the "<< half_length <<"th element" << endl;
    auto pivot = input.head;
    for (unsigned int _ = 0; _ < half_length - 1; ++_)
    {
        pivot = pivot->next;
    }
    cout << "Reversing elements after "<< pivot->value << endl;

    auto new_front = pivot->next;   // preserve reference to new last element in list.

                                    // we need to maintain references to 3 elements:
    auto current = pivot->next;     // 1) the previous element
    auto next = pivot->next;        // 2) the element that will now point to its previous element
    auto next_next = next->next;    // 3) the next element to traverse to.
    for (unsigned int _ = 0; _ < input.size - half_length - 1 ; ++_) // traverse through the list
    {
        next->next = current;       // make the next element point back to its previous
        current = next;             // increment our pointers through the list in its original order.
        next = next_next;           // we needed to preserve this reference to next_next, else we do not know what element we need to reverse next.
        next_next = next->next;
    }
    pivot->next = next_next;
    new_front->next = nullptr;
}

int main([[maybe_unused]]int argc, [[maybe_unused]] char** argv)
{
    linked_list<int> testcase;
    linked_list<int> testcase2;
    for (int i = 10; i > 0; --i)
    {
        testcase.insert_front(i);
        testcase2.insert_front(i);
    }

    cout << "Running reorder_students_recursive on input list: " << testcase << endl;
    reorder_students_recursive(testcase);
    cout << " -> " << testcase << endl;

    cout << "Running reorder_students_iterative on input list: " << testcase2 << endl;
    reorder_students_recursive(testcase2);
    cout << " -> " << testcase2 << endl;
}

