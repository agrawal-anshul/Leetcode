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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node added before head to simplify removal logic
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // First and second pointers start at dummy
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move second pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            second = second->next;
        }

        // Move both pointers until second reaches end
        while (second != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node from end
        ListNode* temp = first->next;
        first->next = temp->next;
        delete temp;

        // Return new head of the list
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};