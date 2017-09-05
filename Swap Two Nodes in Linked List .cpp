/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
    bool find(ListNode*& prev, int target){
        while(prev->next){
            if(prev->next->val == target){
                return true;
            }
            prev = prev->next;
        }
        return false;
    }
public:
    /*
     * @param head: a ListNode
     * @param v1: An integer
     * @param v2: An integer
     * @return: a new head of singly-linked list
     */
    ListNode * swapNodes(ListNode * head, int v1, int v2) {
        // write your code here
        ListNode node(0);
        node.next = head;
        ListNode* ptr1 = &node;
        ListNode* ptr2 = &node;
        if(!find(ptr1, v1) || !find(ptr2, v2)){return head;}
        if(ptr1 == ptr2){return head;}
        if(ptr1->next == ptr2 || ptr2->next == ptr1){
            if(ptr2->next == ptr1){
                swap(ptr1, ptr2);
            }
            ptr1->next = ptr2->next;
            ptr2->next = ptr2->next->next;
            ptr1->next->next = ptr2;
        }else{
            ListNode* pv1 = ptr1->next;
            ListNode* pv2 = ptr2->next;
            ptr1->next = pv1->next;
            ptr2->next = pv2->next;
            
            pv1->next = ptr2->next;
            ptr2->next = pv1;
            
            pv2->next = ptr1->next;
            ptr1->next =pv2;
        }
        return node.next;
    }
};