/**
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
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
    void work(TreeNode* root, DoublyListNode*& node){
        if(!root){
            return;
        }
        work(root->left, node);
        DoublyListNode* newNode = new DoublyListNode(root->val);
        node->next = newNode;
        newNode->prev = node;
        node = node->next;
        work(root->right, node);
    }
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        // Write your code here
        DoublyListNode node(0);
        DoublyListNode* ptr = &node;
        work(root, ptr);
        ptr->next = nullptr;
        return node.next;
    }
};


