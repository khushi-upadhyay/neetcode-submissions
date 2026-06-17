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
private:
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* ptr = slow->next;
        slow->next = NULL;
        return reverseList(ptr);
    }

    ListNode* reverseList(ListNode* head){
      ListNode* prev = NULL;
            ListNode* curr = head;
            if(!head) return 0;
             while(curr){
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;      
        }
        return prev;
    }

    ListNode* mergeList(ListNode* ptr1, ListNode* ptr2){
        ListNode* cur = ptr1;
        ListNode* nxt = ptr1;
        while(cur && ptr2 && ptr2->next){
            nxt = cur->next;
            cout<< nxt->val << endl;
            cur->next = ptr2;
            cur = ptr2;
            ptr2= ptr2->next;
            cur->next = nxt;
            cur = nxt;
        }
        nxt = cur->next;
        cur->next = ptr2;
        ptr2->next = nxt;
        return ptr1;
    }

public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
       ListNode* ptr = mergeList(head, middle(head));  
    }
};