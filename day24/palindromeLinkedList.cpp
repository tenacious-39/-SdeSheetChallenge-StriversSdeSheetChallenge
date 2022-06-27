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
    ListNode* reverseList(ListNode *head){
        ListNode *newHead = NULL;
        while(head){
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
            
        } return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL or head->next == NULL) return true;
        
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while(slow){
            if(head->val != slow->val){
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};
