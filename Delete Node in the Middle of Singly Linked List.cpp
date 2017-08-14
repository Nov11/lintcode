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
public:
    /**
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        if(!node){return;}
        while(true){
            node->val = node->next->val;
            if(node->next->next == nullptr){
                free(node->next);
                node->next = nullptr;
                break;
            }
            node = node->next;
        }
    }
};