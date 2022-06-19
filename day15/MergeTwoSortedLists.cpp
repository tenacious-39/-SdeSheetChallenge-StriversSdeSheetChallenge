// Making new List:
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
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* newHead;
        ListNode *it1 = list1, *it2 = list2;
        if(list1->val < list2->val){
            newHead = new ListNode(list1->val);
            it1 = list1->next;
        } else{ 
            newHead = new ListNode(list2->val);
            it2 = it2->next;
        }
        ListNode* n = newHead;
        while(it1 && it2){
            if(it1->val < it2->val){
                ListNode *tmp = new ListNode(it1->val);
                n->next = tmp;
                n = tmp;
                it1 = it1->next;
            } else{
                ListNode *tmp = new ListNode(it2->val);
                n->next = tmp;
                n = tmp;
                it2 = it2->next;
            }
        }
        
        while(it1){
            ListNode* tmp = new ListNode(it1->val);
            it1 = it1->next;
            n->next = tmp;
            n = tmp;
        }
        while(it2){
            ListNode* tmp = new ListNode(it2->val);
            it2 = it2->next;
            n->next = tmp;
            n = tmp;
        }
        return newHead;
        
    }
};

// optimized approach:

