#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        int len = nums.size();
        if (len == 0)
            return ans;
        int start = 0;
        for (int end = 1; end < len; end++)
        {
            if ((long long)nums[end] - (long long)nums[end - 1] != 1)
            {
                if (nums[start] == nums[end - 1])
                {
                    ans.push_back(to_string(nums[start]));
                }
                else
                {
                    ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end - 1]));
                }
                start = end;
            }
        }
        if (nums[start] == nums[len - 1])
        {
            ans.push_back(to_string(nums[start]));
        }
        else
        {
            ans.push_back(to_string(nums[start]) + "->" + to_string(nums[len - 1]));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
