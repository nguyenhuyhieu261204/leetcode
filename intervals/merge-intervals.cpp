#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int len = intervals.size();
        vector<vector<int>> ans;
        if (len == 0)
            return ans;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return a[0] < b[0];
             });
        ans.reserve(len);
        vector<int> current = intervals[0];
        for (int i = 1; i < len; i++)
        {
            if (intervals[i][0] <= current[1])
            {
                current[1] = max(current[1], intervals[i][1]);
            }
            else
            {
                ans.push_back(current);
                current = intervals[i];
            }
        }
        ans.push_back(current);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
