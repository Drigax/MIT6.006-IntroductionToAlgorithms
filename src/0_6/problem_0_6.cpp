#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

pair<int,int> count_long_subarrays(vector<int> input)
{
    // base case, shortest possible subarray given constraints is 1.
    unsigned int longestSubarrayLength = 1;
    unsigned int longestSubarrayCount = 1;
    unsigned int currentSubarrayLength = 1;
        
    for (unsigned int i = 1; i < input.size(); ++i)
    {
        if (input[i-1] < input[i])
        {
            currentSubarrayLength++;
        }
        else 
        {
            currentSubarrayLength = 1;
        }

        if (currentSubarrayLength > longestSubarrayLength)
        {
            longestSubarrayLength = currentSubarrayLength;
            longestSubarrayCount = 1;
        } 
        else if (currentSubarrayLength == longestSubarrayLength)
        {
            longestSubarrayCount++;
        }
    }
    return pair<int,int>(longestSubarrayLength, longestSubarrayCount);
}

int main([[maybe_unused]]int argc, [[maybe_unused]] char** argv)
{
    vector<int> testcase({1,3,4,2,7,5,6,9,8});
    cout << "using testcase: { ";
    for (auto value : testcase)
        cout << value << ", ";
    cout << " }" << endl;


    auto result = count_long_subarrays(testcase);
    cout << "Longest subarray length: " << result.first << " Longest subarray count: " << result.second << endl;
}
