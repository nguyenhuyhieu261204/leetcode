#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

/**
 * Use map
 */
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        Node *current = head;
        while (current)
        {
            Node *cp = new Node(current->val);
            cp->next = current->next;
            current->next = cp;
            current = cp->next;
        }
        current = head;
        while (current)
        {
            current->next->random = current->random ? current->random->next : nullptr;
            current = current->next->next;
        }
        current = head;
        Node *ans = head->next;
        while (current)
        {
            Node *next = current->next->next;
            current->next->next = next ? next->next : nullptr;
            current->next = next;
            current = next;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
