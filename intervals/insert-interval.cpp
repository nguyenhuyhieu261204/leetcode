#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        for (vector current : intervals)
        {
            if (current[1] < newInterval[0])
            {
                ans.push_back(current);
            }
            else if (current[0] > newInterval[1])
            {
                ans.push_back(newInterval);
                newInterval = current;
            }
            else
            {
                newInterval[0] = min(newInterval[0], current[0]);
                newInterval[1] = max(newInterval[1], current[1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
