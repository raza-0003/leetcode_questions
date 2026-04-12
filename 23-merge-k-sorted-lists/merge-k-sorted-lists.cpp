class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans;
        // Step 1: Collect values
        for (auto it : lists) {
            while (it != nullptr) {
                ans.push_back(it->val);
                it = it->next;
            }
        }
        // Edge case
        if (ans.size() == 0) return nullptr;
        // Step 2: Sort
        sort(ans.begin(), ans.end());
        // Step 3: Create linked list
        ListNode* head = new ListNode(ans[0]);
        ListNode* temp = head;

        for (int i = 1; i < ans.size(); i++) {
            temp->next = new ListNode(ans[i]);
            temp = temp->next;   
        }

        return head;
    }
};