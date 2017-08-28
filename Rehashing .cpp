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
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int len = hashTable.size();
        if(len == 0){return {};}
        
        int cnt = 0;
        for(auto item : hashTable){
            while(item){
                cnt++;
                item = item->next;
            }
        }
        
        if(cnt >= len / 10){
            len *= 2;
        }
        
        vector<ListNode*> result(len);
        for(auto item : hashTable){
            ListNode* cur = item;
            while(cur){
                ListNode* next = cur->next;
                
                cur->next = nullptr;
                int bucket = (cur->val % len + len) % len;
                if(result[bucket] == nullptr){
                    result[bucket] = cur;
                }else{
                    ListNode* ptr = result[bucket];
                    while(ptr->next){
                        ptr = ptr->next;
                    }
                    ptr->next = cur;
                }
                
                cur = next;
            }
        }
        
        return result;
    }
};
