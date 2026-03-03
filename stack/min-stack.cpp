#include <stack>

using namespace std;

class MinStack
{
private:
    stack<int> st;
    stack<int> min;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        this->st.push(val);
        if (this->min.empty() || this->min.top() >= val)
        {
            this->min.push(val);
        }
    }

    void pop()
    {
        if (this->st.empty())
            return;
        if (this->st.top() == this->min.top())
        {
            this->min.pop();
        }
        this->st.pop();
    }

    int top()
    {
        return this->st.top();
    }

    int getMin()
    {
        return this->min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
