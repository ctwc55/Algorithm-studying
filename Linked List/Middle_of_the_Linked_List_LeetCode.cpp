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
    ListNode* middleNode(ListNode* head) {
        ListNode* now=head;
        int cnt=0;
        
        while(now!=NULL){
            cnt++;
            now=now->next;
        }
        
        cnt/=2;
        while(cnt--){
            head=head->next;
        }
        
        return head;
    }
};
