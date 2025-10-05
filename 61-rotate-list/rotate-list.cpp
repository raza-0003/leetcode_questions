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
    ListNode* RotateLL(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        ListNode* tail = temp->next;
        temp->next = nullptr;
        tail->next = head;
        return tail;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        ListNode* temp = head;
        int n = 0;
        while(temp){
            n++;
            temp=temp->next;
        }
        temp = head;
        k = k % n; 
        for(int i=0;i<k;i++){
            ListNode* newHead = RotateLL(temp);
            temp = newHead;
        }
        return temp;
        
    }
};