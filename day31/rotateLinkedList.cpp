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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL or head->next == NULL) return head;
        int len = 0;
        ListNode *it = head;
        while(it){
            len++;
            it = it->next;
        }
        k %= len;
        if(!k) return head;
        ListNode *fast = head, *slow = head;
        for(int i = 1; i <= k; i++) fast = fast->next;
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *newHead = slow->next;
        fast->next = head;
        slow->next = NULL;
        return newHead;
    }
};
