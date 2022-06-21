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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans = NULL, *it = NULL;
        bool flag = true;
        while(l1 && l2){
            int d1 = l1->val, d2 = l2->val;
            l1 = l1->next; l2 = l2->next;
            int sum = d1+d2+carry;
            if(sum >= 10){
                carry = 1;
                if(flag){
                    ans = new ListNode(sum%10);
                    it = ans;
                    flag = false;
                } else{
                    ListNode* nw = new ListNode(sum%10);
                    it->next = nw;
                }
            } else{
                carry = 0;
                if(flag){
                    ans = new ListNode(sum);
                    it = ans;
                    flag = false;
                } else{
                    it->next = new ListNode(sum);
                }
            }
            it = it->next;
        }
        
        while(l1){
            int sum = l1->val+carry;
            l1 = l1->next;
            if(sum >= 10) carry = 1;
            else carry = 0;
            if(sum >= 10){
                it->next = new ListNode(sum%10);
            } else{
                it->next = new ListNode(sum);
            }
            it = it->next;
        }
        while(l2){
            int sum = l2->val+carry;
            l2 = l2->next;
            if(sum >= 10) carry = 1;
            else carry = 0;
            if(sum >= 10){
                it->next = new ListNode(sum%10);
            } else{
                it->next = new ListNode(sum);
            }
            it = it->next;
        }
        if(carry) it->next = new ListNode(carry);
        return ans;
        
    }
};
