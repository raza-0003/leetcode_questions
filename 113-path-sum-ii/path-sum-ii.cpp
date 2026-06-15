/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,vector<vector<int>>&ans,vector<int>&temp,int sum){
        if(root==nullptr){
            return;
        }
        temp.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(sum == root->val){
                ans.push_back(temp);
            }
            temp.pop_back();
            return;
        }
        solve(root->left,ans,temp,sum-root->val);
        solve(root->right,ans,temp,sum-root->val);
        temp.pop_back();
       
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(root,ans,temp,targetSum);
        return ans;
        
    }
};