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
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        if(headA == nullptr && headB == nullptr){return nullptr;}
        if(headA == nullptr || headB == nullptr){return nullptr;}
        int shiftA = 0;
        int shiftB = 0;
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        while(shiftA + shiftB <= 2){
            if(ptrA == ptrB){return ptrA;}
            ptrA = ptrA->next;
            if(!ptrA){
                shiftA++;
                ptrA = headB;
            }
            ptrB = ptrB->next;
            if(!ptrB){
                shiftB++;
                ptrB = headA;
            }
        }
        return nullptr;
    }
};