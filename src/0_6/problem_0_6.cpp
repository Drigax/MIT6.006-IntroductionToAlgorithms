#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

pair<int,int> count_long_subarrays(vector<int> input)
{
    int longestSubarrayLength = 0;
    int longestSubarrayCount = 0;
    
    for (auto current = input.begin(); current < input.end();)
    {
        cout << "starting new subarray:";
        int prev = INT_MIN;
        int currentSubarrayLength = 0;
        while (current < input.end() && *current > prev)
        {
            cout << *current << ", ";
            prev = *current;
            ++currentSubarrayLength;
            ++current;
        }
        cout << endl << "subarray length is: " << currentSubarrayLength << endl;
        if(currentSubarrayLength > longestSubarrayLength){
                longestSubarrayLength = currentSubarrayLength;
                longestSubarrayCount = 1;
                cout << "longest subarray is length: " << longestSubarrayLength;        
        } else if (currentSubarrayLength == longestSubarrayLength){
            ++longestSubarrayCount;
        }
        cout << "number of longest subarray is: " << longestSubarrayCount << endl;
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
