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
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // Now mid point = slow and end point = fast;
        ListNode* ll1 = head;
        ListNode* next1 = nullptr;
        ListNode* ll2 = reverseList(slow->next);
        //  cut the first half
        slow->next = nullptr;

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