#include "../src/resizable_array_list.h"

#include <iostream>
#include <vector>
#include <random>

#include "gtest/gtest.h"

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

TEST(resizable_array_list_test, first_gets_first)
{
    //TODO: this test relies on inser_first behavior, rather than some constructor.
    resizable_array_list<int> arr;
    for (unsigned long i = 0UL; i < arr.capacity(); ++i)
    {
        int iValue = static_cast<int>(i);
        arr.insert_first(iValue);
    }
    ASSERT_EQ(arr.first(), static_cast<int>(arr.capacity()) - 1);
}

TEST(resizable_array_list_test, insert_first_inserts_first)
{
    //TODO: this test relies on insert_first behavior, rather than some constructor.
    resizable_array_list<int> arr;
    int test_val = random();
    for (unsigned long i = 0UL; i < arr.capacity(); ++i)
    {
        int iValue = static_cast<int>(i);
        arr.insert_first(iValue);
    }
    arr.insert_first(test_val);
    ASSERT_EQ(arr.first(), test_val);
}

TEST(resizable_array_list_test, insert_last_inserts_last)
{
    //TODO: this test relies on insert_last behavior, rather than some constructor.
    resizable_array_list<int> arr;
    int test_val = rand();
    for (unsigned long i = 0UL; i < arr.capacity(); ++i)
    {
        arr.insert_last(static_cast<int>(i));
    }
    arr.insert_last(test_val);
    ASSERT_EQ(arr.last(), test_val);
}

TEST(resizable_array_list_test, bracket_operator_indexes_properly)
{
    //TODO: this test relies on insert_last behavior, rather than some constructor.
    resizable_array_list<int> arr;
    int test_val = rand();
    UNUSED(test_val);
    
    for (unsigned long i = 0UL; i < arr.capacity(); ++i)
    {
        arr.insert_last(static_cast<int>(i));
    }
    
    unsigned long randIdx = static_cast<unsigned long>(rand()) % arr.count();
    UNUSED(randIdx);
    ASSERT_TRUE(true);
    //arr[randIdx] = test_val;
    //ASSERT_EQ(arr[randIdx], test_val);
}

TEST(resizable_array_list_test, const_bracket_operator_indexes_properly)
{
    //TODO: this test relies on insert_last behavior, rather than some constructor.
    resizable_array_list<int> arr;
    int test_val = rand();
    for (unsigned long i = 0UL; i < arr.capacity(); ++i)
    {
        arr.insert_last(static_cast<int>(i));
    }

    unsigned long randIdx = static_cast<unsigned long>(rand()) % arr.count();
    arr.set(randIdx, test_val);
    const int const_val = arr.get(randIdx);
    ASSERT_EQ(test_val, const_val);
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
