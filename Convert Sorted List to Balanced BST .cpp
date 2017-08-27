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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if(!head){return nullptr;}
        if(!head->next){
            TreeNode* ret = new TreeNode(head->val);
            return ret;
        }
        
        ListNode node(0);
        node.next = head;
        ListNode* fast = &node;
        ListNode* slow = &node;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        //I havnt' take care of freeing list nodes.
        //It should be dealt with in real application
        TreeNode* t = new TreeNode(slow->next->val);
        t->right = sortedListToBST(slow->next->next);
        slow->next = nullptr;
        t->left = sortedListToBST(head);
        return t;
    }
};


