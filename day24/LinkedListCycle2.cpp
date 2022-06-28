/// Brute force approach:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL or head->next == NULL) return NULL;
        
        map<ListNode*, int> mp;
        ListNode *it = head;
        while(it){
            if(mp[it] == 1) return it;
            mp[it]++;
            it = it->next;
        }
        return NULL;
    }
};

//// optimized approach:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL or head->next == NULL) return NULL;
        
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(!fast->next or !fast->next->next) return NULL;
        
        ListNode *dummy = head;
        while(slow != dummy){
            slow = slow->next;
            dummy = dummy->next;
        }
        return slow;
    }
};
