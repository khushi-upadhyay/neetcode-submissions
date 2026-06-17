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
    void reorderList(ListNode* head) {
        vector<int>v;
        ListNode* curr = head;
        while(curr != NULL){
            v.push_back(curr->val);
            curr = curr->next;
        }
        vector<int>res;
        int i = 0;
        int j = v.size() -1;
        while(i < j){
            res.push_back(v[i]);
            res.push_back(v[j]);
            i++;
            j--;
        }
        if(i==j) res.push_back(v[i]);
        curr = head;
        for (int i = 0; i < res.size()&& curr != nullptr; i++) {
            curr->val = res[i];   
             curr = curr->next;
        }
        
    }
};