/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution {
    ListNode* merge(ListNode* prev, ListNode* post){
        ListNode node(0);
        ListNode* ptr = &node;
        while(prev && post){
            if(prev->val < post->val){
                ListNode* next = prev->next;
                prev->next = ptr->next;
                ptr->next = prev;
                
                ptr = ptr->next;
                prev = next;
            }else{
                ListNode* next = post->next;
                post->next = ptr->next;
                ptr->next = post;
                
                ptr = ptr->next;
                post = next;
            }
        }
        ptr->next = prev != nullptr ? prev : post;
        return node.next;
    }
public:
    /*
     * @param head: The head of linked list.
     * @return: You should return the head of the sorted linked list, using constant space complexity.
     */
    ListNode * sortList(ListNode * head) {
        // write your code here
        if(head == nullptr || head->next == nullptr){return head;}
        ListNode node(0);
        node.next = head;
        
        ListNode* slow = &node;
        ListNode* fast = &node;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* post = sortList(slow->next);
        slow->next = nullptr;
        ListNode* prev = sortList(node.next);
        
        return merge(prev, post);
    }
};