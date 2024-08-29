#include "../src/resizable_array_list.h"

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

TEST(resizable_array_list_test, is_initially_empty)
{
    resizable_array_list<int> arr;
    ASSERT_TRUE(arr.is_empty());
}

TEST(resizable_array_list_test, initial_capacity_not_zero)
{
    resizable_array_list<int> arr;
    ASSERT_NE(arr.capacity(), (unsigned long)0);
}

TEST(resizable_array_list_test, iterator_constructor_has_proper_initialization)
{
    //TODO:
    resizable_array_list<int> arr;
    ASSERT_EQ(arr.count(), (unsigned long)0);
}

TEST(resizable_array_list_test, first_gets_first)
{
    resizable_array_list<int> arr;
    ASSERT_NE(arr.capacity(), (unsigned long)0);
}

TEST(resizable_array_list_test, insert_first_inserts_first)
{
    resizable_array_list<int> arr;
    ASSERT_NE(arr.capacity(), (unsigned long)0);
}

TEST(resizable_array_list_test, insert_last_inserts_last)
{
    resizable_array_list<int> arr;
    ASSERT_NE(arr.capacity(), (unsigned long)0);
}

TEST(resizable_array_list_test, bracket_operator_indexes_properly)
{
    resizable_array_list<int> arr;
    ASSERT_NE(arr.capacity(), (unsigned long)0);
}

TEST(resizable_array_list_test, const_bracket_operator_indexes_properly)
{
    resizable_array_list<int> arr;
    ASSERT_NE(arr.capacity(), (unsigned long)0);
}

TEST(resizable_array_list_test, get_indexes_properly)
{
    resizable_array_list<int> arr;
    ASSERT_NE(arr.capacity(), (unsigned long)0);
}

TEST(resizable_array_list_test, get_returns_value_reference)
{
    resizable_array_list<int> arr;
    ASSERT_NE(arr.capacity(), (unsigned long)0);
}

TEST(resizable_array_list_test, set_indexes_properly)
{
    resizable_array_list<int> arr;
    ASSERT_NE(arr.capacity(), (unsigned long)0);
}

TEST(resizable_array_list_test, insert_at_indexes_and_shifts_properly)
{
    resizable_array_list<int> arr;
    ASSERT_NE(arr.capacity(), (unsigned long)0);
}

TEST(resizable_array_list_test, delete_at_indexes_and_shifts_properly)
{
    resizable_array_list<int> arr;
    ASSERT_NE(arr.capacity(), (unsigned long)0);
}

TEST(resizable_array_list_test, insert_first_inserts_and_shifts_properly)
{
    resizable_array_list<int> arr;
    ASSERT_NE(arr.capacity(), (unsigned long)0);
}

TEST(resizable_array_list_test, delete_first_inserts_and_shifts_properly)
{
    resizable_array_list<int> arr;
    ASSERT_NE(arr.capacity(), (unsigned long)0);
}

TEST(resizable_array_list_test, resizes_to_hold_more_elements)
{
    resizable_array_list<int> arr;
    auto initialCapacity = arr.capacity();
    for (int i = 0; i <= static_cast<int>(initialCapacity); ++i)
    {
        arr.insert_last(i);
    }
    
    ASSERT_GT(arr.capacity(), initialCapacity);
}

TEST(resizable_array_list_test, resize_preserves_item_order)
{
    resizable_array_list<int> arr;
    auto initialCapacity = arr.capacity();
    for (int i = 0; i <= static_cast<int>(initialCapacity); i++)
    {
        arr.insert_last(i); // should cause resize.
    }

    for (int i = 0; i < static_cast<int>(initialCapacity); i++)
    {
        //std::cout<< "i: " << i << "static_cast<unsigned long>(i): " << static_cast<unsigned long>(i) << std::endl;
        EXPECT_EQ(arr.get(static_cast<unsigned long>(i)), i) << "Checking for " << i << " at position " << i << " : " << arr.get(static_cast<unsigned long>(i)) << std::endl;
    }
}

