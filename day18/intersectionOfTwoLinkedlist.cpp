/////1st best approach: (Not preferable):
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *it1 = headA, *it2 = headB;
        int len1 = 0, len2 = 0;
        while(it1 or it2){
            if(it1){
                len1++;
                it1 = it1->next;
            }
            if(it2){
                len2++;
                it2 = it2->next;
            }
        }
        it1 = headA; it2 = headB;
        if(len2 > len1){
            int diff = len2-len1;
            for(int i = 1; i <= diff; i++) it2 = it2->next;
        }
        if(len1 > len2){
            int diff = len1-len2;
            for(int i = 1; i <= diff; i++) it1 = it1->next;
        }
        while(it1 and it2){
            if(it1 == it2) return it1;
            it1 = it1->next;
            it2 = it2->next;
        }
        return NULL;
    }
};


//// 2nd best approach: (Preferable approach)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *it1 = headA, *it2 = headB;
        while(it1 != it2){
            it1 = it1 == NULL? headB:it1->next;
            it2 = it2 == NULL? headA:it2->next;
        }
        return it1;
    }
};





///// Optimized approach: (Using map/hashing) T.c ----> O(N+M) SC : O(N)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mpp;
        ListNode *it = headA;
        while(it){
            mpp[it]++;
            it = it->next;
        }
        
        it = headB;
        while(it){
            if(mpp.find(it) != mpp.end()) return it;
            it = it->next;
        }
        return NULL;
    }
};



/// brute force approach T.c ----> O(NXM)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA){
            ListNode *tmp = headB;
            while(tmp){
                if(tmp == headA) return tmp;
                tmp = tmp->next;
            }
            headA = headA->next;
        }
        return NULL;
    }
};
