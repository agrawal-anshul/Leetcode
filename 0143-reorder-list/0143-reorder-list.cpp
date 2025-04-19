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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        
        //Find middle using slow-fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        // slow will be at the mid point.
        // fast will be at the end.
        while(fast && fast->next && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        
        // Splitting list into 2 halves
        ListNode* ll2 = reverseList(slow->next); //reverse the second half
        slow->next = nullptr;

        //Merging the two halves
        ListNode* ll1 = head;
        ListNode* next1 = nullptr;
        ListNode* next2 = nullptr;
        while(ll1 && ll2){
            next1 = ll1->next;
            ll1->next = ll2;

            next2 = ll2->next;
            ll2->next = next1;

            ll1 = next1;
            ll2 = next2;
        }


    }
};