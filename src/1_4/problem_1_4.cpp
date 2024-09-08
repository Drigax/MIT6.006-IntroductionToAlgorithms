#include <lib/data_structures/src/linked_list.h>

#include <iostream>
#include <memory>
#include <vector>
#include <limits.h>

using namespace std;

shared_ptr<linked_list_node<int>> reverse_recursive(shared_ptr<linked_list_node<int>> p_node)
{
    //cout << "reversing order of " << p_node->value << endl;
    if (p_node->next == nullptr)            // base case: there is no next node. return this as our old tail element.
        return p_node;
    auto next = p_node->next;               // preserve reference to next element in sequence
    auto tail = reverse_recursive(next);    // get last element in sequence and tail recurse.
    next->next = p_node;                    // point next element to this element
    p_node->next = nullptr;                 // clear reference that this node points to.
    return tail;
}

void reorder_students_recursive(linked_list<int>& input)
{
    int half_length = input.size/2;                                 // find pivot of input
    cout << "Reversing elements after the "<< half_length <<"th element" << endl;
    auto current = input.head;
    for (int i = 0; i < half_length - 1; ++i)                       // iterate through collection until we get to pivot element.
    {
        current = current->next;
    }
    cout << "Reversing elements after "<< current->value << endl;
    current->next = reverse_recursive(current->next);               // recursively reverse all elements after the pivot element
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

