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
        if(head==NULL){return head;}


        ListNode* curr = head;
        ListNode* prev = head;

        int len = 0;
        while(curr){
            len++;
            curr=curr->next;
        }
        curr = head;

        // delete the last node
        if(n==1){
            // mode than one node are present
            if(len>1){
                while(len-2 && curr){
                    curr = curr->next;
                    len--;
                }
                curr->next = NULL;
                return head;
            }

            // delete the only node
            if(len==1){
                return NULL;
            }
        }

        int posFromStart = len-n+1;
        while(posFromStart-2 && curr){
            if(posFromStart==1)
            {
                // delete the first node
                curr = head->next;
                return curr;
            }
            
            curr = curr->next;
            posFromStart--;
        }
        
        if(curr && curr->next && curr->next->next)
        {
            curr->next = curr->next->next;
        }
        return head;
    }
};