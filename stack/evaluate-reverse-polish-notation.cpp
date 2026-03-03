#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (string token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(token == "+" ? num2 + num1 : token == "-" ? num2 - num1
                                                 : token == "*"   ? num2 * num1
                                                                  : num2 / num1);
            }
            else
            {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
