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
        // Adding a dummy node before the head to simplify edge case handling
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        for(int i = 0; i <=n and second!=nullptr; i++){
            second = second->next;
        }

        // If second reached end, we are deleting the head
        if(second == nullptr){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // else if second is not nullptr -> Move both pointers until second is at the last node
        while(second){
            first = first->next;
            second = second->next;
        }
        
        // Delete the node after 'first'
        ListNode* temp = first->next;
        first->next = temp->next;
        delete temp;

        
        return head;
    }
};