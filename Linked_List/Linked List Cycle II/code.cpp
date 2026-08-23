class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {

                // Find cycle length
                int len = 1;
                ListNode* curr = slow->next;

                while (curr != slow) {
                    curr = curr->next;
                    len++;
                }

                // Move fast 'len' steps ahead
                fast = head;

                for (int i = 0; i < len; i++) {
                    fast = fast->next;
                }

                // Find cycle starting node
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return nullptr;
    }
};