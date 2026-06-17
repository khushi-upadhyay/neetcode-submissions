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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<int>v;
        ListNode* curr = head;
        while(curr != NULL){
            v.push_back(curr->val);
            curr = curr->next;
        }
        v.erase(v.begin() + (v.size()-n));
        for(int i = 0 ; i< v.size(); i++){
            cout<<v[i];
        }
        if (v.empty()) return nullptr; // for case list = [1], n = 1
        curr = head;
        for(int i = 0; i < v.size(); i++){
            curr->val = v[i];
            if (i == v.size() - 1) {
        curr->next = nullptr; 
    } else {
        curr = curr->next;
    }

        }       return head;
    }
};
// always remember even if we shrink the vector the list size remains same thats why have to delete it separately 