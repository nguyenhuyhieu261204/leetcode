using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        ListNode *current = head;
        while (current)
        {
            if (current->next && current->val == current->next->val)
            {
                while (current->next && current->val == current->next->val)
                {
                    current = current->next;
                }
                if (!current->next)
                {
                    prev->next = nullptr;
                    break;
                }
                else
                {
                    current = current->next;
                }
            }
            else
            {
                prev->next = current;
                prev = prev->next;
                current = current->next;
            }
        }
        return dummy->next;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
