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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
        else if(list2->val <= list1->val){
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
        return list1;
        
    }
    ListNode* mergeAndUnion(vector<ListNode*>& lists,int s,int e){
        if(s == e){
            return lists[s];
        }
        int mid = s + (e-s)/2;
        ListNode* L1 = mergeAndUnion(lists,s,mid);
        ListNode* L2 = mergeAndUnion(lists,mid+1,e);
        return mergeTwoLists(L1,L2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;
        return mergeAndUnion(lists,0,n-1);
    }
};