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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *l1=list1,*l2=list2;
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        while(l1 != NULL && l2 != NULL){
            if (l1->val <= l2->val) {
                curr->next = l1; // Reuse the node from l1
                l1 = l1->next;  // Move to the next node in l1
            } else {
                curr->next = l2; // Reuse the node from l2
                l2 = l2->next;  // Move to the next node in l2
            }
            curr = curr->next; // Advance the result list
        }

        if(l1 !=NULL){
            curr->next = l1;
        }else{
            curr->next = l2;
        }

        ListNode* mergedll = res->next;
        delete res;
        return mergedll;
    }
};