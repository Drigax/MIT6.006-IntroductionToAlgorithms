#include "../src/set_unordered.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

#include "gtest/gtest.h"

TEST(set_unordered_test, is_initially_empty)
{
    set_unordered<int> st;
    ASSERT_TRUE(st.is_empty());
}

TEST(set_unordered_test, does_not_contain_arbitrary_element)
{
    set_unordered<int> st;
    int value = 0;
    ASSERT_FALSE(st.contains(value));
}

TEST(set_unordered_test, contains_element_after_insertion)
{
    //TODO: this test relies on insert behavior, rather than some constructor.
    set_unordered<int> st;
    for (unsigned long i = 0UL; i < 10UL; ++i)
    {
        int iValue = static_cast<int>(i);
        st.insert(iValue);
    }

    for (unsigned long i = 0UL; i < 10UL; ++i)
    {
        int iValue = static_cast<int>(i);
        ASSERT_TRUE(st.contains(iValue));
    }
}

TEST(set_unordered_test, can_find_valid_element)
{
    //TODO: this test relies on insert behavior, rather than some constructor.
    set_unordered<int> st;
    for (unsigned long i = 0UL; i < 10UL; ++i)
    {
        int iValue = static_cast<int>(i);
        st.insert(iValue);
    }

    for (unsigned long i = 0UL; i < 10UL; ++i)
    {
        int iValue = static_cast<int>(i);
        ASSERT_TRUE(st.contains(iValue));
    }
}


TEST(set_unordered_test, cant_find_invalid_element)
{
    //TODO: this test relies on insert behavior, rather than some constructor.
    set_unordered<int> st;
    for (unsigned long i = 0UL; i < 10UL; ++i)
    {
        int iValue = static_cast<int>(i);
        st.insert(iValue);
    }
    
    int invalidValue = INT32_MAX;
    ASSERT_FALSE(st.contains(invalidValue));
}


TEST(set_unordered_test, can_remove_valid_element)
{
    //TODO: this test relies on insert behavior, rather than some constructor.
    set_unordered<int> st;
    for (unsigned long i = 0UL; i < 10UL; ++i)
    {
        int iValue = static_cast<int>(i);
        st.insert(iValue);
    }
    
    for (unsigned long i = 0UL; i < 10UL; ++i)
    {
        int iValue = static_cast<int>(i);
        st.remove(iValue);
    }

    for (unsigned long i = 0UL; i < 10UL; ++i)
    {
        int iValue = static_cast<int>(i);
        ASSERT_FALSE(st.contains(iValue));
    }
}


TEST(set_unordered_test, cant_remove_invalid_element)
{
    //TODO: this test relies on insert behavior, rather than some constructor.
    set_unordered<int> st;
    for (unsigned long i = 0UL; i < 10; ++i)
    {
        int iValue = static_cast<int>(i); 
        st.insert(iValue);
    }

    int invalidValue = INT32_MAX;
    EXPECT_DEATH(st.remove(invalidValue), "");
}


TEST(set_unordered_test, find_min_finds_min)
{
    const unsigned long testAmount = 100UL;

    set_unordered<int> st;
    int arr[testAmount];
    
    //TODO: this test relies on insert behavior, rather than some constructor.
    for (unsigned long i = 0UL; i < testAmount; ++i)
    {
        int randValue = rand();
        if (!st.contains(randValue))
        {
            st.insert(randValue);
            arr[st.count()-1] = randValue;
        }
    }

    ASSERT_TRUE(st.count() > 0);

    int minValue = st.find_min();
    int arrMinValue = INT32_MAX;
    for (unsigned long i = 0UL; i < st.count(); ++i)
    {
        arrMinValue = arrMinValue < arr[i] ? arrMinValue : arr[i];
    }

    ASSERT_EQ(arrMinValue, minValue);
}

TEST(set_unordered_test, find_max_finds_max)
{
    const unsigned long testAmount = 100UL;

    set_unordered<int> st;
    int arr[testAmount];
    
    //TODO: this test relies on insert behavior, rather than some constructor.
    for (unsigned long i = 0UL; i < testAmount; ++i)
    {
        int randValue = rand();
        if (!st.contains(randValue))
        {
            st.insert(randValue);
            arr[st.count()-1] = randValue;
        }
    }

    ASSERT_TRUE(st.count() > 0);

    int minValue = st.find_max();
    int arrMaxValue = INT32_MIN;
    for (unsigned long i = 0UL; i < st.count(); ++i)
    {
        arrMaxValue = arrMaxValue > arr[i] ? arrMaxValue : arr[i];
    }

    ASSERT_EQ(arrMaxValue, minValue);
}


TEST(set_unordered_test, find_next_finds_next)
{
    const unsigned long testAmount = 100UL;
    const unsigned long testIterations = 100UL;

    set_unordered<int> st;
    std::vector<int> testInputOrder;
    
    //TODO: this test relies on insert behavior, rather than some constructor.
    for (unsigned long i = 0UL; i < testAmount; ++i)
    {
        int iValue = rand();
        if (!st.contains(iValue))
        {
            st.insert(iValue);
            testInputOrder.push_back(iValue);
        }
    }

    ASSERT_TRUE(st.count() > 0);

    for(unsigned long i = 0; i < testIterations; ++i)
    {
        unsigned long testIndex = static_cast<unsigned long>(rand()) % st.count() - 1UL; // get random index
        int valueToTest = testInputOrder[testIndex];
        int orderNextValue = testInputOrder[testIndex + 1];
        int setNextValue = st.find_next(valueToTest);

        ASSERT_EQ(setNextValue, orderNextValue);
    }
}

TEST(set_unordered_test, find_prev_finds_prev)
{
    const unsigned long testAmount = 100UL;
    const unsigned long testIterations = 100UL;

    set_unordered<int> st;
    std::vector<int> testInputOrder;
    
    //TODO: this test relies on insert behavior, rather than some constructor.
    for (unsigned long i = 0UL; i < testAmount; ++i)
    {
        int iValue = rand();
        if (!st.contains(iValue))
        {
            st.insert(iValue);
            testInputOrder.push_back(iValue);
        }
    }

    ASSERT_TRUE(st.count() > 0);

    for(unsigned long i = 0; i < testIterations; ++i)
    {
        unsigned long testIndex = (static_cast<unsigned long>(rand()) % (st.count() - 1UL)) + 1UL; // get random index
        
        ASSERT_TRUE(testIndex != 0);
        
        int valueToTest = testInputOrder[testIndex];
        int orderPrevValue = testInputOrder[testIndex - 1];
        int setPrevValue = st.find_prev(valueToTest);

        ASSERT_EQ(setPrevValue, orderPrevValue);
    }
} 

