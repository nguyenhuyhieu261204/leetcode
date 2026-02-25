#include <stack>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        string token;
        stringstream ss(path);
        while (getline(ss, token, '/'))
        {
            if (token == "." || token == "")
            {
                continue;
            }
            else if (token == "..")
            {
                if (!st.empty())
                    st.pop();
            }
            else
            {
                st.push(token);
            }
        }
        if (st.empty())
            return "/";
        string ans;
        while (!st.empty())
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
