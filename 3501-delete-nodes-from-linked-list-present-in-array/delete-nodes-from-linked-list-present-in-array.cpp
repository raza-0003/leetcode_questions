// Ensure you are compiling in an environment that knows about ListNode.
// Assuming your environment is C++-like.

class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
        unordered_set<int> set_to_delete(nums.begin(), nums.end());
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;
        while (curr) {
            if (set_to_delete.count(curr->val)) {
                ListNode* temp = curr;
                // Advance 'curr' BEFORE deletion.
                curr = curr->next;
                // Unlink 'temp'.
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy.next; // Return the new head.
    }
};