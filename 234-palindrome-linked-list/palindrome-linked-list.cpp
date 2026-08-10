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
    ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
    // Empty or single-node list
    if(head == nullptr || head->next == nullptr)
        return true;
    // 1. Find middle
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // 2. Reverse second half
    ListNode* second = reverse(slow);
    // 3. Compare
    ListNode* first = head;
    while(second != nullptr) {
        if(first->val != second->val)
            return false;
        first = first->next;
        second = second->next;
    }
    return true;
    }
};