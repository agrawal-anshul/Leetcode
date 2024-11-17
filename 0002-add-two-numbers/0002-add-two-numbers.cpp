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


    // int reverseDigits(int num) 
    // { 
    //     int revNum = 0;
    //     while(num){
    //         revNum=revNum*10+num%10;
    //         num=num/10;
    //     }
    //     return revNum;
    // } 

    long long generateNumber(ListNode* head){
        ListNode* curr = head;
        if(curr==NULL){ return 0;}
        long long num=0;
        long long tenMultiple = 1; 
        while(curr){
            num+= (long long)(curr->val)*tenMultiple;
            tenMultiple*=10;
            curr = curr->next;
        }
        return num;
    }

    ListNode* createLL(long long num){
        if (num == 0) {
            return new ListNode(0); // Handle case where num is 0
        }

        ListNode* head = new ListNode(num%10);
        num = num/10;
        ListNode* curr = head;
        while(num){
            ListNode* nn = new ListNode(num%10);
            curr->next = nn;
            curr = curr->next;

            num = num/10;
        }
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // METHOD 1:
        // long long x = generateNumber(l1);
        // long long y = generateNumber(l2);
        // long long sum = x+y;
        // return createLL(sum);

        // Method 2:
        ListNode *head = new ListNode(0);
        ListNode* curr = head;
        int carry = 0;
        
        while((l1!=NULL) || (l2!=NULL) || (carry!=0)){
            int sum = carry;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
        }

        return head->next;
    }
};